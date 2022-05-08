/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_linux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slonnie <slonnie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:51:08 by slonnie           #+#    #+#             */
/*   Updated: 2022/05/08 16:00:16 by slonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_game_atr *game)
{
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	else if (keycode == 119 || keycode == 65362)
		move_up(game);
	else if (keycode == 115 || keycode == 65364)
		move_down(game);
	else if (keycode == 97 || keycode == 65361)
		move_left(game);
	else if (keycode == 100 || keycode == 65363)
		move_right(game);
	return (0);
}
