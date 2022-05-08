/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_macos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slonnie <slonnie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:50:18 by slonnie           #+#    #+#             */
/*   Updated: 2022/05/08 15:51:01 by slonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_game_atr *game)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 13)
		move_up(game);
	else if (keycode == 1)
		move_down(game);
	else if (keycode == 0)
		move_left(game);
	else if (keycode == 2)
		move_right(game);
	return (0);
}
