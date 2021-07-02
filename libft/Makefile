# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnave <tnave@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 10:36:30 by tnave             #+#    #+#              #
#    Updated: 2021/06/24 20:34:31 by tnave            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

PATH_SRCS = ./
HEADER = ./

SRCS =  ft_atoi.c 		\
        ft_isalnum.c 	\
        ft_isalpha.c 	\
        ft_isascii.c 	\
        ft_isdigit.c 	\
        ft_isprint.c 	\
        ft_strlen.c 	\
        ft_bzero.c 		\
        ft_calloc.c 	\
        ft_memchr.c 	\
        ft_memcmp.c 	\
        ft_strnstr.c 	\
        ft_strdup.c 	\
        ft_itoa.c 		\
        ft_putchar_fd.c \
        ft_putnbr_fd.c 	\
        ft_putstr_fd.c 	\
        ft_putendl_fd.c \
        ft_strmapi.c 	\
        ft_strlcat.c 	\
        ft_memcpy.c 	\
        ft_substr.c 	\
        ft_memccpy.c 	\
        ft_memmove.c 	\
        ft_memset.c 	\
        ft_strchr.c 	\
        ft_strjoin.c 	\
		ft_strtrim.c 	\
		ft_split.c 		\
        ft_strlcpy.c 	\
        ft_strncmp.c 	\
        ft_strrchr.c 	\
        ft_tolower.c	\
        ft_toupper.c	\
		get_next_line.c \
		get_next_line_utils.c \
		ft_split_charset.c


SRCS_BONUS = 	ft_lstadd_back.c	\
				ft_lstadd_front.c	\
				ft_lstclear.c		\
				ft_lstdelone.c		\
				ft_lstiter.c		\
				ft_lstlast.c		\
				ft_lstmap.c			\
				ft_lstnew.c			\
				ft_lstsize.c		\
				get_next_line.c		\
				get_next_line_utils	\
				ft_split_charset.c

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

.c.o :
	${CC} -c ${FLAGS} -I ${HEADER} $< -o ${<:.c=.o}

all: $(NAME)

$(NAME) : ${OBJS}
	ar -rcs $(NAME) ${OBJS}

bonus:	$(NAME) ${OBJS_BONUS}
	ar -rcs $(NAME) ${OBJS} ${OBJS_BONUS}

clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
