/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_and_validation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slonnie <slonnie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:23:06 by slonnie           #+#    #+#             */
/*   Updated: 2022/04/14 17:50:06 by slonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_struct_validating(t_game_atr *game)
{
	if (game->collect == 0)
		print_error_and_exit("You forgot add collectibles.");
	if (game->player == 0)
		print_error_and_exit("You forgot add player.");
	if (game->exit == 0)
		print_error_and_exit("You forgot add exit.");
}

void	map_core_validating(t_game_atr *game)
{
	int	width;

	width = 0;
	while (game->array[game->height][++width])
	{
		if ((game->array[game->height][width] != '1') &&
			(game->array[game->height][width] != '0') &&
			(game->array[game->height][width] != 'C') &&
			(game->array[game->height][width] != 'F') &&
			(game->array[game->height][width] != 'P') &&
			(game->array[game->height][width] != 'E'))
			print_error_and_exit("Invalid values on the map. RTFM!");
		if (game->array[game->height][width] == 'C')
			game->collect += 1;
		else if (game->array[game->height][width] == 'P')
		{
			if (game->player++ != 0)
				print_error_and_exit("Player must be only one. RTFM!");
		}
		else if (game->array[game->height][width] == 'E')
		{
			if (game->exit++ != 0)
				print_error_and_exit("Exit must be only one. RTFM!");
		}
	}
}

void	map_shape_validating(t_game_atr *game)
{
	while (game->array[FIRST][game->width])
	{
		if (game->array[FIRST][game->width] != '1')
			print_error_and_exit("The map content is incorrect. RTFM!");
		game->width += 1;
	}
	if (game->width > 39)
		print_error_and_exit("The map is to width. RTFM!");
	while (ft_strcmp(game->array[FIRST], game->array[game->height]))
	{
		if ((ft_strlen(game->array[game->height])) != game->width)
			print_error_and_exit("The map content is incorrect. RTFM!");
		if ((game->array[game->height][FIRST] != '1') ||
			(game->array[game->height][game->width - 1] != '1'))
			print_error_and_exit("The map content is incorrect. RTFM!");
		map_core_validating(game);
		game->height += 1;
		if (game->height == 17)
			print_error_and_exit("The map is too high. RTFM!");
	}
	game->height += 1;
}

void	map_parsing_to_struct(int fd, t_game_atr *game)
{
	int		readed_bytes;
	char	buffer[BUFFERSIZE];
	char	*readed;
	char	*tmp_ptr;

	readed = malloc(sizeof(char) * 1);
	if (!readed)
		print_error_and_exit("Failed to allocate memory for reading");
	readed[0] = 0;
	readed_bytes = read(fd, &buffer, BUFFERSIZE);
	if (readed_bytes > 680)
		print_error_and_exit("Map is too big. RTFM");
	while (readed_bytes)
	{
		tmp_ptr = readed;
		readed = ft_strjoin(readed, buffer);
		free(tmp_ptr);
		readed_bytes = read(fd, &buffer, BUFFERSIZE);
		if (readed_bytes < 0)
			print_error_and_exit("Failed reading map.ber.");
	}
	game->array = ft_split(readed, '\n');
	close(fd);
	free(readed);
}
