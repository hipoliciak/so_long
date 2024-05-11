/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:31:31 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/11 18:01:28 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	localize_player(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.width)
	{
		y = 0;
		while (y < game->map.height)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.x = x * game->floor.x;
				game->player.y = y * game->floor.y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x / game->floor.x;
	y = game->player.y / game->floor.y;
	if (game->map.map[y - 1][x] != '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.xpm_ptr, game->player.x, game->player.y);
		game->player.y -= game->floor.y;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.xpm_ptr, game->player.x, game->player.y);
	}
	if (game->map.map[y - 1][x] == 'E')
		end_game(game);
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x / game->floor.x;
	y = game->player.y / game->floor.y;
	if (game->map.map[y + 1][x] != '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.xpm_ptr, game->player.x, game->player.y);
		game->player.y += game->floor.y;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.xpm_ptr, game->player.x, game->player.y);
	}
	if (game->map.map[y + 1][x] == 'E')
		end_game(game);
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x / game->floor.x;
	y = game->player.y / game->floor.y;
	if (game->map.map[y][x - 1] != '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.xpm_ptr, game->player.x, game->player.y);
		game->player.x -= game->floor.x;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.xpm_ptr, game->player.x, game->player.y);
	}
	if (game->map.map[y][x - 1] == 'E')
		end_game(game);
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x / game->floor.x;
	y = game->player.y / game->floor.y;
	if (game->map.map[y][x + 1] != '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.xpm_ptr, game->player.x, game->player.y);
		game->player.x += game->floor.x;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.xpm_ptr, game->player.x, game->player.y);
	}
	if (game->map.map[y][x + 1] == 'E')
		end_game(game);
}
