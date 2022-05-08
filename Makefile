NAME	= so_long

LIBMLX	= libmlx.a

SRCS	= 	so_long.c map_parsing_and_validation.c ft_split.c ft_strcmp.c \
		ft_strjoin.c ft_strlen.c print_errors.c init_check_images.c \
		window_maker.c moves.c move_validating.c ft_itoa.c ft_strdup.c \
		ft_memcpy.c animation.c key_handler_linux.c

HEADER	= so_long.h

OBJ		= $(SRCS:%.c=%.o)

CFLAGS	= -Wall -Werror -Wextra -I ./

.PHONY	: all clean fclean re exe

all		: $(NAME)

$(NAME)	: ${OBJ} ${HEADER} ${LIBMLX}
	gcc ${OBJ} -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c ${HEADER}
	gcc $(CFLAGS) -c $< -o $@

#macos	: ${OBJ} ${HEADER}
#	cd ./mlx_macos && make -f Makefile && mv libmlx.a ./..
#	gcc ${OBJ} -Lmlx_macos -lmlx_macos -framework OpenGL -framework AppKit -o $(NAME)

exe		:
	./so_long ./bonus.ber

clean	:
	rm -f $(OBJ)
	cd ./mlx_linux && make -f Makefile clean
	cd ./mlx_macos && make -f Makefile clean

fclean	: clean
	rm -f ${NAME} ${LIBMLX}

${LIBMLX}:
	cd ./mlx_linux && make -f Makefile && mv libmlx.a ./..

#${LIBMLXMAC}:
#	cd ./mlx_macos && make -f Makefile && mv libmlx.a ./..

re		 : fclean all
