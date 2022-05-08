/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_validating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slonnie <slonnie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:46:35 by slonnie           #+#    #+#             */
/*   Updated: 2022/04/14 20:21:30 by slonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_steps(t_game_atr *game)
{
	char	*str_tmp;

	str_tmp = ft_itoa(game->steps);
	put_img(game, game->img_wall, 0, 0);
	put_img(game, game->img_wall, 1, 0);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 3, 20, 0xf2f3f4, "STEP=");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 55, 20, 0xf2f3f4, str_tmp);
	free(str_tmp);
}

int	exit_game(t_game_atr *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}

void	endgame_check(t_game_atr *game)
{
	game->collect -= 1;
	if (game->collect == 0)
	{
		put_img(game, game->img_exit_open, game->exit_pos_w, game->exit_pos_h);
				game->exit -= 1;
	}
}

bool	move_check(t_game_atr *game, void *player_xpm, size_t x, size_t y)
{
	if (game->array[y][x] == 'F' || game->array[y][x] == 'A')
		exit_game(game);
	else if (game->array[y][x] == '0')
	{
		put_img(game, player_xpm, x, y);
		put_img(game, game->img_floor, game->player_pos_w, game->player_pos_h);
		return (true);
	}
	else if (game->array[y][x] == 'C')
	{
		put_img(game, game->img_floor, x, y);
		put_img(game, player_xpm, x, y);
		put_img(game, game->img_floor, game->player_pos_w, game->player_pos_h);
		endgame_check(game);
		return (true);
	}
	else if (game->array[y][x] == '1')
	{
		put_img(game, player_xpm, game->player_pos_w, game->player_pos_h);
	}
	else if (game->array[y][x] == 'E')
	{
		if (game->exit == 0)
			exit_game(game);
	}
	return (false);
}
