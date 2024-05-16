/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:35:54 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/16 00:31:42 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		end_game(game);
	else if (keycode == KEY_W || keycode == KEY_AR_U)
	{
		move_up(game);
		// draw_map(game);
	}
	else if (keycode == KEY_S || keycode == KEY_AR_D)
	{
		move_down(game);
		// draw_map(game);
	}
	else if (keycode == KEY_A || keycode == KEY_AR_L)
	{
		move_left(game);
		// draw_map(game);
	}
	else if (keycode == KEY_D || keycode == KEY_AR_R)
	{
		move_right(game);
		// draw_map(game);
	}
	return (0);
}

static void	init_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->collectibles = 0;
	game->moves = 0;
	game->map.map = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.x_player_pos = 0;
	game->map.y_player_pos = 0;
	game->map.x_exit_pos = 0;
	game->map.y_exit_pos = 0;
	game->collectible.xpm_ptr = NULL;
	game->exit.xpm_ptr = NULL;
	game->wall.xpm_ptr = NULL;
	game->floor.xpm_ptr = NULL;
	game->player.direction = 'R';
	game->player.player_r.xpm_ptr = NULL;
	game->player.player_l.xpm_ptr = NULL;
	game->player.player_u.xpm_ptr = NULL;
	game->player.player_d.xpm_ptr = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc <= 1)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	init_game(&game);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (1);
	init_sprites(&game);
	read_map(&game, argv[1]);
	fill_map(&game, argv[1]);
	// draw_map(&game);
	if (!validate_elements(&game.map) || !check_walls(&game.map) || !count_elements(&game))
		end_game(&game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map.width * SPRITE_SIZE, game.map.height * SPRITE_SIZE, "Let's play So Long!");
	if (!game.win_ptr)
		return (1);
	render_map(&game, game.map);
	init_positions(&game);
	mlx_key_hook(game.win_ptr, key_hook, &game);
	mlx_hook(game.win_ptr, CLOSE_BTN, 0, end_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
