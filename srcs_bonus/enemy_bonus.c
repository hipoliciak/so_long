/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:44:52 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/16 14:08:34 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_enemy(t_game *game, int line, int column)
{
	if (game->enemy.direction == 'R')
		render_sprite(game, &game->enemy.enemy_r, line, column);
	else if (game->enemy.direction == 'L')
		render_sprite(game, &game->enemy.enemy_l, line, column);
	else if (game->enemy.direction == 'U')
		render_sprite(game, &game->enemy.enemy_u, line, column);
	else if (game->enemy.direction == 'D')
		render_sprite(game, &game->enemy.enemy_d, line, column);
}

void	move_enemy(t_game *game, int keycode)
{
	int	x;
	int	y;

	x = game->map.x_enemy_pos;
	y = game->map.y_enemy_pos;
	if (game->map.map[y][x + 1] != '1' && (keycode == KEY_D || keycode == KEY_AR_R))
	{
		game->map.map[y][x] = '0';
		game->map.map[y][x + 1] = 'R';
		game->enemy.direction = 'R';
		game->map.x_enemy_pos++;
	}
	else if (game->map.map[y][x - 1] != '1' && (keycode == KEY_A || keycode == KEY_AR_L))
	{
		game->map.map[y][x] = '0';
		game->map.map[y][x - 1] = 'R';
		game->enemy.direction = 'L';
		game->map.x_enemy_pos--;
	}
	else if (game->map.map[y - 1][x] != '1' && (keycode == KEY_W || keycode == KEY_AR_U))
	{
		game->map.map[y][x] = '0';
		game->map.map[y - 1][x] = 'R';
		game->enemy.direction = 'U';
		game->map.y_enemy_pos--;
	}
	else if (game->map.map[y + 1][x] != '1' && (keycode == KEY_S || keycode == KEY_AR_D))
	{
		game->map.map[y][x] = '0';
		game->map.map[y + 1][x] = 'R';
		game->enemy.direction = 'D';
		game->map.y_enemy_pos++;
	}
}
