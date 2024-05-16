/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:44:52 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/15 23:14:09 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_game *game)
{
	game->enemy.enemy = create_sprite(game->mlx_ptr, ENEMY);
	game->enemy.direction = 'R';
	game->enemy.x_pos = 1;
	game->enemy.y_pos = 1;
}

void	render_enemy(t_game *game)
{
	render_sprite(game, &game->enemy.enemy, game->enemy.y_pos, game->enemy.x_pos);
}

void	move_enemy(t_game *game)
{
	if (game->enemy.direction == 'R')
	{
		if (game->map.map[game->enemy.y_pos][game->enemy.x_pos + 1] != '1')
			game->enemy.x_pos++;
		else
			game->enemy.direction = 'L';
	}
	else if (game->enemy.direction == 'L')
	{
		if (game->map.map[game->enemy.y_pos][game->enemy.x_pos - 1] != '1')
			game->enemy.x_pos--;
		else
			game->enemy.direction = 'R';
	}
	else if (game->enemy.direction == 'U')
	{
		if (game->map.map[game->enemy.y_pos - 1][game->enemy.x_pos] != '1')
			game->enemy.y_pos--;
		else
			game->enemy.direction = 'D';
	}
	else if (game->enemy.direction == 'D')
	{
		if (game->map.map[game->enemy.y_pos + 1][game->enemy.x_pos] != '1')
			game->enemy.y_pos++;
		else
			game->enemy.direction = 'U';
	}
}
