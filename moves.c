/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slonnie <slonnie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:26:32 by slonnie           #+#    #+#             */
/*   Updated: 2022/05/08 15:50:11 by slonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game_atr *game)
{
	size_t	x;
	size_t	y;

	x = game->player_pos_w;
	y = game->player_pos_h - 1;
	if (move_check(game, game->img_player_up, x, y))
	{
		game->array[game->player_pos_h][x] = '0';
		game->array[y][x] = 'P';
		game->player_pos_h = y;
		game->steps += 1;
		print_steps(game);
	}
}

void	move_down(t_game_atr *game)
{
	size_t	x;
	size_t	y;

	x = game->player_pos_w;
	y = game->player_pos_h + 1;
	if (move_check(game, game->img_player_down, x, y))
	{
		game->array[game->player_pos_h][x] = '0';
		game->array[y][x] = 'P';
		game->player_pos_h = y;
		game->steps += 1;
		print_steps(game);
	}
}

void	move_left(t_game_atr *game)
{
	size_t	x;
	size_t	y;

	x = game->player_pos_w - 1;
	y = game->player_pos_h;
	if (move_check(game, game->img_player_left, x, y))
	{
		game->array[y][game->player_pos_w] = '0';
		game->array[y][x] = 'P';
		game->player_pos_w = x;
		game->steps += 1;
		print_steps(game);
	}
}

void	move_right(t_game_atr *game)
{
	size_t	x;
	size_t	y;

	x = game->player_pos_w + 1;
	y = game->player_pos_h;
	if (move_check(game, game->img_player_right, x, y))
	{
		game->array[y][game->player_pos_w] = '0';
		game->array[y][x] = 'P';
		game->player_pos_w = x;
		game->steps += 1;
		print_steps(game);
	}
}
