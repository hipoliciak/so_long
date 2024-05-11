/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:03:34 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/11 14:29:36 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	sprite(void *mlx, char *path)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (!sprite.xpm_ptr)
	{
		ft_printf("Error\nInvalid sprite path: %s\n", path);
		exit(1);
	}
	return (sprite);
}

void	init_sprites(t_game *game)
{
	game->coins = sprite(game->mlx_ptr, COINS);
	game->portal = sprite(game->mlx_ptr, PORTAL);
	game->tree = sprite(game->mlx_ptr, TREE);
	game->floor = sprite(game->mlx_ptr, FLOOR);
	game->player = sprite(game->mlx_ptr, PLAYER);
}

void	render_sprite(t_game *game, t_image *sprite, int line, int column)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite->xpm_ptr, column * sprite->x, line * sprite->y);
}
