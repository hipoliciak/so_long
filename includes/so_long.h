/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:24:47 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/11 17:39:39 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "key_linux.h"
# include <fcntl.h>
# include <stdio.h>

# define HEIGHT 600
# define WIDTH 1000

# define COINS "sprites/coins.xpm"
# define PORTAL "sprites/portal.xpm"
# define TREE "sprites/tree.xpm"
# define FLOOR "sprites/floor.xpm"
# define PLAYER "sprites/player.xpm"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_image		coins;
	t_image		portal;
	t_image		tree;
	t_image		floor;
	t_image		player;
}	t_game;

int		end_game(t_game *game);
int		key_hook(int keycode, t_game *game);
t_image	sprite(void *mlx, char *path);
void	init_sprites(t_game *game);
void	render_sprite(t_game *game, t_image *sprite, int line, int column);
void	init_map(t_map *map);
void	read_map(t_map *map, char *path);
void	render_map(t_game *game, t_map map);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	localize_player(t_game *game);
void	victory_message(t_game *game);

#endif