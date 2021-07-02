# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnave <tnave@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/13 14:34:04 by tnave             #+#    #+#              #
#    Updated: 2021/07/02 12:01:16 by tnave            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	srcs/main_functions/keys.c			\
		srcs/main_functions/main.c			\
		srcs/main_functions/mlx1138.c		\
		srcs/main_functions/raycasting.c	\
		srcs/main_functions/textures.c		\
		srcs/parsing/parsing_id.c 			\
		srcs/parsing/parsing_map.c			\
		srcs/utils/colors.c					\
		srcs/utils/errors.c					\
		srcs/utils/exit.c					\
		srcs/utils/free_utils.c				\
		srcs/utils/keys_utils.c				\
		srcs/utils/lst_sprites.c			\
		srcs/utils/new_lst.c				\
		srcs/utils/parsing_id_utils.c 		\
		srcs/utils/parsing_map_utils_two.c 	\
		srcs/utils/parsing_map_utils.c 		\
		srcs/utils/raycasting_utils.c


SRCS_BONUS = 	srcs/bonus/sprites.c 						\
				srcs/bonus/main.c						\
				srcs/bonus/keys.c						\
				srcs/bonus/mlx1138.c					\
				srcs/bonus/raycasting.c					\
				srcs/bonus/textures.c					\
				srcs/bonus/parsing_id.c 				\
				srcs/bonus/parsing_map.c				\
				srcs/bonus/errors.c						\
				srcs/bonus/exit.c						\
				srcs/bonus/free_utils.c					\
				srcs/bonus/keys_utils.c					\
				srcs/bonus/lst_sprites.c				\
				srcs/bonus/parsing_map_utils_two.c 		\
				srcs/bonus/bonus_utils.c				\
				srcs/bonus/floor_text.c					\
				srcs/bonus/mini_map.c					\
				srcs/bonus/sky_text.c					\
				srcs/utils/colors.c						\
				srcs/utils/new_lst.c					\
				srcs/utils/parsing_map_utils.c			\
				srcs/utils/raycasting_utils.c			\
				srcs/utils/parsing_id_utils.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I  ./include/ -g3

LDFLAGS = -L libft -L ./mlx/

HEADER = -I ./includes/ -I libft/includes -I mlx

OBJ = $(SRCS:%.c=%.o)

OBJ_BONUS = $(SRCS_BONUS:%.c=%.o)

LIBS = -lm -lft -lmlx -lXext -lX11

$(NAME): $(OBJ)
	make -C libft/
	make -C mlx/
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) ./libft/libft.a -o $(NAME) $(LIBS)

all: ${NAME}

%.o%.c:
	${CC} -c ${CFLAGS} -I ${HEADER} -I libft -I/usr/include -Imlx -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJ}
	rm -f ${OBJ_BONUS}
	make clean -C libft/
	make clean -C mlx/

bonus: $(OBJ_BONUS)
	make -C libft/
	make -C mlx/
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ_BONUS) ./libft/libft.a -o $(NAME) $(LIBS)

fclean: clean
	rm -f ${NAME} libft.a
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
