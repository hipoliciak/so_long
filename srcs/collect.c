/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:41:37 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/05/11 17:30:57 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collectibles(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.width)
	{
		y = 0;
		while (y < game->map.height)
		{
			if (game->map.map[y][x] == 'C')
				game->collectibles++;
			y++;
		}
		x++;
	}
}
