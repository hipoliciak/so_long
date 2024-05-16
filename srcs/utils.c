/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:05:59 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/16 01:57:02 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves_and_collectibles(t_game *game)
{
	char	*moves;
	char	*collectibles;

	moves = ft_itoa(game->moves);
	collectibles = ft_itoa(game->collectibles);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 0x00FFFFFF, "Moves: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 120, 10, 0x00FFFFFF, moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 25, 0x00FFFFFF, "Collectibles: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 120, 25, 0x00FFFFFF, collectibles);
	free(moves);
	free(collectibles);
}

void	exit_with_message(int code)
{
	int		fd;
	char	*line;

	fd = open("victory.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	ft_printf("\n");
	close(fd);
	exit(code);
}

void	destroy_images(t_game *game)
{
	if (game->collectible.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->collectible.xpm_ptr);
	if (game->exit.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit.xpm_ptr);
	if (game->wall.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	if (game->floor.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	if (game->player.player_r.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.player_r.xpm_ptr);
	if (game->player.player_l.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.player_l.xpm_ptr);
	if (game->player.player_u.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.player_u.xpm_ptr);
	if (game->player.player_d.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.player_d.xpm_ptr);
}

int	end_game(t_game *game)
{
	if (game->map.map)
	{
		while (game->map.height--)
			free(game->map.map[game->map.height]);
		free(game->map.map);
	}
	destroy_images(game);
	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_loop_end(game->mlx_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit_with_message(0);
	return (0);
}

void	draw_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		ft_printf("%s\n", game->map.map[i]);
		i++;
	}
	ft_printf("x_player_pos: %d\n", game->map.x_player_pos);
	ft_printf("y_player_pos: %d\n", game->map.y_player_pos);
	ft_printf("x_exit_pos: %d\n", game->map.x_exit_pos);
	ft_printf("y_exit_pos: %d\n", game->map.y_exit_pos);
	ft_printf("moves: %d\n", game->moves);
	ft_printf("collectibles: %d\n", game->collectibles);	
	ft_printf("\n");
}
