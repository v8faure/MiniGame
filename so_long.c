/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slonnie <slonnie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:22:18 by slonnie           #+#    #+#             */
/*   Updated: 2022/05/08 16:00:36 by slonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game_atr *game)
{
	game->width = 0;
	game->height = 1;
	game->collect = 0;
	game->player = 0;
	game->exit = 0;
	game->player_pos_w = 0;
	game->player_pos_h = 0;
	game->steps = 0;
	game->frame = 0;
	game->time = 26;
	if (game->time > 33)
		print_error_and_exit("Too big delay. RTFM!");
}

void	check_argv(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '.')
		i++;
	if (ft_strcmp(&argv[i], "ber") == 0)
	{
		print_error_and_exit("Must run only with argument map.ber. Try again.");
	}
}

int	main(int argc, char **argv)
{
	t_game_atr	game;
	int			fd;

	if (argc != 2)
		print_error_and_exit("Wrong number of arguments. Link map.ber.");
	check_argv(argv[1]);
	init_map(&game);
	init_images(&game);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error_and_exit("Can't read map file");
	map_parsing_to_struct(fd, &game);
	map_shape_validating(&game);
	map_struct_validating(&game);
	window_maker(&game);
	mlx_key_hook(game.win_ptr, key_handler, &game);
	mlx_hook(game.win_ptr, 17, 1L << 0, exit_game, &game);
	mlx_loop_hook(game.mlx_ptr, animation, &game);
	mlx_loop(game.mlx_ptr);
}
