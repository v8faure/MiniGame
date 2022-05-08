/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slonnie <slonnie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:08:57 by slonnie           #+#    #+#             */
/*   Updated: 2022/04/14 20:11:58 by slonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animation(t_game_atr *game)
{
	size_t	x;
	size_t	y;

	y = -1;
	game->frame = clock() + game->time;
	while (++y < game->height)
	{
		x = -1;
		while (game->array[y][++x])
		{
			if (game->array[y][x] == 'F' && game->frame <= clock())
			{
				put_img(game, game->img_floor, x, y);
				put_img(game, game->img_foe_end, x, y);
				game->array[y][x] = 'A';
			}
			else if (game->array[y][x] == 'A' && game->frame <= clock())
			{
				put_img(game, game->img_floor, x, y);
				put_img(game, game->img_foe_start, x, y);
				game->array[y][x] = 'F';
			}
		}
	}
	return (0);
}
