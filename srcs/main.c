/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:35:54 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/11 18:27:36 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	end_game(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->coins.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->portal.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->tree.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player.xpm_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	while (game->map.height--)
		free(game->map.map[game->map.height]);
	free(game->map.map);
	free(game->mlx_ptr);
	exit_with_message(0);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		end_game(game);
	else if (keycode == KEY_W || keycode == KEY_AR_U)
		move_up(game);
	else if (keycode == KEY_S || keycode == KEY_AR_D)
		move_down(game);
	else if (keycode == KEY_A || keycode == KEY_AR_L)
		move_left(game);
	else if (keycode == KEY_D || keycode == KEY_AR_R)
		move_right(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc <= 1)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (1);
	init_sprites(&game);
	init_map(&game.map);
	read_map(&game.map, argv[1]);
	game.win_ptr = mlx_new_window(game.mlx_ptr, (game.map.width - 1) * game.floor.x, game.map.height * game.floor.y, "Let's play So Long!");
	if (!game.win_ptr)
		return (1);
	render_map(&game, game.map);
	localize_player(&game);
	mlx_key_hook(game.win_ptr, key_hook, &game);
	mlx_hook(game.win_ptr, CLOSE_BTN, 0, end_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
