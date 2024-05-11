/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:17:51 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/11 17:29:22 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map)
{
	map->map = NULL;
	map->width = 0;
	map->height = 0;
}

void	read_map(t_map *map, char *path)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nCould not open file %s\n", path);
		exit(1);
	}
	map->height = 0;
	map->width = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->height++;
		if (map->width == 0)
			map->width = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->map = malloc(map->height * sizeof(char *));
	if (!map->map)
	{
		ft_printf("Error\nCould not allocate memory for map\n");
		exit(1);
	}
	i = 0;
	while (i < map->height)
	{
		map->map[i] = malloc((map->width + 1) * sizeof(char));
		if (!map->map[i])
		{
			ft_printf("Error\nCould not allocate memory for map row\n");
			exit(1);
		}
		i++;
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nCould not open file %s\n", path);
		exit(1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		ft_strlcpy(map->map[i], line, map->width + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	render_map(t_game *game, t_map map)
{
	int	line;
	int	column;

	line = 0;
	while (line < map.height)
	{
		column = 0;
		while (column < map.width - 1)
		{
			if (map.map[line][column] == 'E')
				render_sprite(game, &game->portal, line, column);
			if (map.map[line][column] == 'C')
				render_sprite(game, &game->coins, line, column);
			if (map.map[line][column] == '1')
				render_sprite(game, &game->tree, line, column);
			if (map.map[line][column] == '0')
				render_sprite(game, &game->floor, line, column);
			if (map.map[line][column] == 'P')
				render_sprite(game, &game->player, line, column);		
			column++;
		}
		line++;
	}
}
