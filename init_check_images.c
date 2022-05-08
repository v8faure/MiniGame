/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slonnie <slonnie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:50:57 by slonnie           #+#    #+#             */
/*   Updated: 2022/04/14 17:51:37 by slonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*check_images(char *path)
{
	if (open(path, O_RDONLY) < 0)
		print_error_and_exit("Image not found!");
	return (path);
}

void	init_images(t_game_atr *game)
{
	game->img_size = 64;
	game->img_wall = check_images("./images/wall.xpm");
	game->img_floor = check_images("./images/floor.xpm");
	game->img_collect = check_images("./images/collet.xpm");
	game->img_foe_start = check_images("./images/foe_start.xpm");
	game->img_foe_end = check_images("./images/foe_end.xpm");
	game->img_player_up = check_images("./images/player_up.xpm");
	game->img_player_down = check_images("./images/player_down.xpm");
	game->img_player_left = check_images("./images/player_left.xpm");
	game->img_player_right = check_images("./images/player_right.xpm");
	game->img_exit_close = check_images("./images/exit_close.xpm");
	game->img_exit_open = check_images("./images/exit_open.xpm");
}
