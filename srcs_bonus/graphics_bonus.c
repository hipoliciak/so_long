/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:03:34 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/16 14:08:39 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_sprites(t_game *game)
{
	game->collectible = create_sprite(game, COLLECTIBLE);
	game->exit = create_sprite(game, EXIT);
	game->wall = create_sprite(game, WALL);
	game->floor = create_sprite(game, FLOOR);
	game->player.player_r = create_sprite(game, PLAYER_R);
	game->player.player_l = create_sprite(game, PLAYER_L);
	game->player.player_u = create_sprite(game, PLAYER_U);
	game->player.player_d = create_sprite(game, PLAYER_D);
	game->enemy.enemy_r = create_sprite(game, ENEMY_R);
	game->enemy.enemy_l = create_sprite(game, ENEMY_L);
	game->enemy.enemy_u = create_sprite(game, ENEMY_U);
	game->enemy.enemy_d = create_sprite(game, ENEMY_D);
}

t_image	create_sprite(t_game *game, char *path)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&sprite.x, &sprite.y);
	if (!sprite.xpm_ptr)
		end_game(game, "Failed to load sprite", 1);
	return (sprite);
}

void	render_sprite(t_game *game, t_image *sprite, int line, int column)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite->xpm_ptr,
		column * SPRITE_SIZE, line * SPRITE_SIZE);
}

void	render_player(t_game *game, int line, int column)
{
	if (game->player.direction == 'R')
		render_sprite(game, &game->player.player_r, line, column);
	else if (game->player.direction == 'L')
		render_sprite(game, &game->player.player_l, line, column);
	else if (game->player.direction == 'U')
		render_sprite(game, &game->player.player_u, line, column);
	else if (game->player.direction == 'D')
		render_sprite(game, &game->player.player_d, line, column);
}

void	render_map(t_game *game, t_map map)
{
	int	line;
	int	column;

	line = 0;
	while (line < map.height)
	{
		column = 0;
		while (column < map.width)
		{
			if (map.map[line][column] == 'E')
				render_sprite(game, &game->exit, line, column);
			if (map.map[line][column] == 'C')
				render_sprite(game, &game->collectible, line, column);
			if (map.map[line][column] == '1')
				render_sprite(game, &game->wall, line, column);
			if (map.map[line][column] == '0')
				render_sprite(game, &game->floor, line, column);
			if (map.map[line][column] == 'P')
				render_player(game, line, column);
			if (map.map[line][column] == 'R')
				render_enemy(game, line, column);
			column++;
		}
		line++;
	}
	display_moves_and_collectibles(game);
}
