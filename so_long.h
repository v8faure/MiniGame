/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slonnie <slonnie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:54:47 by slonnie           #+#    #+#             */
/*   Updated: 2022/05/08 15:57:08 by slonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_linux/mlx.h"
# include "./mlx_macos/mlx.h"
# include <unistd.h>
# include <time.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define BUFFERSIZE 700
# define FIRST 0

typedef struct game_attribute
{
	char	**array;
	size_t	width;
	size_t	height;
	size_t	collect;
	int		exit;
	int		exit_pos_w;
	int		exit_pos_h;
	int		player;
	int		player_pos_w;
	int		player_pos_h;
	int		time;
	clock_t	frame;
	int		steps;
	void	*mlx_ptr;
	void	*win_ptr;
	int		img_size;
	void	*img_ptr;
	void	*img_wall;
	void	*img_floor;
	void	*img_collect;
	void	*img_foe_start;
	void	*img_foe_end;
	void	*img_player_up;
	void	*img_player_down;
	void	*img_player_left;
	void	*img_player_right;
	void	*img_exit_close;
	void	*img_exit_open;
}				t_game_atr;

/*print_errors.c*/
void	ft_putchar_fd(char chr, int fd);
void	ft_putstr_fd(char *msg, int fd);
void	print_error_and_exit(char *err_msg);
/*init_check_images.c */
void	init_images(t_game_atr *game);
/*map_parsing_and_validating.c*/
void	map_parsing_to_struct(int fd, t_game_atr *game);
void	map_shape_validating(t_game_atr *game);
void	map_struct_validating(t_game_atr *game);
/*window_maker.c*/
void	window_maker(t_game_atr *game);
void	put_img(t_game_atr *game, void *xpm_file_ptr, size_t x, size_t y);
/*key_handler linux or macos.c*/
int		key_handler(int keycode, t_game_atr *game);
/*moves.c*/
void	move_up(t_game_atr *game);
void	move_down(t_game_atr *game);
void	move_left(t_game_atr *game);
void	move_right(t_game_atr *game);
/*move_validating.c*/
void	print_steps(t_game_atr *game);
int		exit_game(t_game_atr *game);
bool	move_check(t_game_atr *game, void *player_xpm, size_t x, size_t y);
/*animation.c*/
int		animation(t_game_atr *game);
/*libft*/
char	**ft_split(char const *str, char c);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
