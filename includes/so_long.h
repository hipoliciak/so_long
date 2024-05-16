/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:24:47 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/16 00:13:55 by dmodrzej         ###   ########.fr       */
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

# define SPRITE_SIZE 50

# define COLLECTIBLE "sprites/cherry.xpm"
# define EXIT "sprites/exit.xpm"
# define WALL "sprites/wall.xpm"
# define FLOOR "sprites/floor.xpm"
# define PLAYER_R "sprites/player_r.xpm"
# define PLAYER_L "sprites/player_l.xpm"
# define PLAYER_U "sprites/player_u.xpm"
# define PLAYER_D "sprites/player_d.xpm"
# define ENEMY_R "sprites/enemy_r.xpm"
# define ENEMY_L "sprites/enemy_l.xpm"
# define ENEMY_U "sprites/enemy_u.xpm"
# define ENEMY_D "sprites/enemy_d.xpm"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		x_player_pos;
	int		y_player_pos;
	int		x_exit_pos;
	int		y_exit_pos;
}	t_map;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_player
{
	t_image	player_r;
	t_image	player_l;
	t_image	player_u;
	t_image	player_d;
	char	direction;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			collectibles;
	int			moves;
	t_map		map;
	t_image		collectible;
	t_image		exit;
	t_image		wall;
	t_image		floor;
	t_player	player;
	// t_image		enemy_r;
	// t_image		enemy_l;
	// t_image		enemy_u;
	// t_image		enemy_d;
}	t_game;

//Engine
void	init_positions(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

//Graphics
void	init_sprites(t_game *game);
t_image	create_sprite(t_game *game, char *path);
void	render_sprite(t_game *game, t_image *sprite, int line, int column);
void	render_player(t_game *game, int line, int column);
void	render_map(t_game *game, t_map map);

//Map
void	read_map(t_game *game, char *path);
void	fill_map(t_game *game, char *path);
int		validate_elements(t_map *map);
int		check_walls(t_map *map);
int		count_elements(t_game *game);
void	draw_map(t_game *game);

//Utils
void	display_moves_and_collectibles(t_game *game);
int		end_game(t_game *game);
void	destroy_images(t_game *game);
void	exit_with_message(int code);

#endif