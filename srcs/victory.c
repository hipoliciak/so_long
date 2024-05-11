/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:36:40 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/11 17:58:17 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	victory_message(t_game *game)
{
	mlx_string_put(game->mlx_ptr, game->win_ptr, 48, 16, 0x00FFFFFF, "Congratulations! You won!");
	// mlx_string_put(game->mlx_ptr, game->win_ptr, 48, 32, 0x00FFFFFF, "Press ESC or Q to exit.");
}
