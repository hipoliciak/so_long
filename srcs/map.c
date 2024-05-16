/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:17:51 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/16 02:09:54 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game, char *path)
{
	int		fd;
	char	*line;
	char	**split;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		end_game(game);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		end_game(game);
	}
	if (ft_strchr(line, '\n') != 0)
	{
		split = ft_split(line, '\n');
		free(line);
		line = split[0];
		free(split);
	}
	game->map.width = ft_strlen(line);
	while (line)
	{
		if ((int)ft_strlen(line) != game->map.width)
		{
			free(line);
			close(fd);
			end_game(game);
		}
		game->map.height++;
		game->map.width = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
		if (ft_strchr(line, '\n') != 0)
		{
			split = ft_split(line, '\n');
			free(line);
			line = split[0];
			free(split);
		}
	}
	close(fd);
}

void	fill_map(t_game *game, char *path)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		end_game(game);
	game->map.map = malloc(game->map.height * sizeof(char *));
	if (!game->map.map)
		end_game(game);
	i = 0;
	while (i < game->map.height)
	{
		line = get_next_line(fd);
		game->map.map[i] = malloc((game->map.width + 1) * sizeof(char));
		if (!game->map.map[i])
			end_game(game);
		ft_strlcpy(game->map.map[i], line, game->map.width + 1);
		free(line);
		i++;
	}
	close(fd);
}

int	validate_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_strchr("01CEP", map->map[i][j]) == NULL)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (i == 0 || i == map->height)
			{
				if (map->map[i][j] != '1')
					return (0);
			}
			if (j == 0 || j == map->width - 1)
			{
				if (map->map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	count_elements(t_game *game)
{
	int	i;
	int	j;
	int	player;
	int	exit;

	i = 0;
	player = 0;
	exit = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'C')
				game->collectibles++;
			if (game->map.map[i][j] == 'P')
				player++;
			if (game->map.map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (game->collectibles == 0 || player != 1 || exit != 1)
		return (0);
	return (1);
}
