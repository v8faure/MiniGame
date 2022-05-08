/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slonnie <slonnie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:53:23 by slonnie           #+#    #+#             */
/*   Updated: 2022/05/08 16:04:19 by slonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_game_atr *game, void *xpm_file_ptr, size_t x, size_t y)
{
	game->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, xpm_file_ptr, \
										&game->img_size, &game->img_size);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
						game->img_ptr, x * game->img_size, y * game->img_size);
}

void	filling_window(t_game_atr *game)
{
	size_t	w;
	size_t	h;

	h = -1;
	while (++h < game->height)
	{
		w = -1;
		while (game->array[h][++w])
		{
			if (game->array[h][w] == '1')
				put_img(game, game->img_wall, w, h);
			else if (game->array[h][w] == '0')
				put_img(game, game->img_floor, w, h);
			else if (game->array[h][w] == 'C')
				put_img(game, game->img_collect, w, h);
			else if (game->array[h][w] == 'F')
				put_img(game, game->img_foe_start, w, h);
			else if (game->array[h][w] == 'P')
			{
				put_img(game, game->img_player_right, w, h);
				game->player_pos_h = h;
				game->player_pos_w = w;
			}
			else if (game->array[h][w] == 'E')
			{
				put_img(game, game->img_exit_close, w, h);
				game->exit_pos_h = h;
				game->exit_pos_w = w;
			}
		}
	}
}

void	window_maker(t_game_atr *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * game->img_size, \
									game->height * game->img_size, "so_long");
	filling_window(game);
}
