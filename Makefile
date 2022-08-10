# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccottin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 17:05:58 by ccottin           #+#    #+#              #
#    Updated: 2022/08/04 21:42:52 by ccottin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

SRCS	= srcs/init_map.c srcs/utils.c srcs/init.c srcs/ft_return.c srcs/main.c srcs/set_info.c srcs/get_info_wall.c srcs/utils1.c srcs/set_info_map.c

SRCSDIR	= srcs

OBJS	= $(SRCS:%.c=%.o)

OBJSDIR	= objs

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -g3 

all	:	$(NAME)

%.o	:	%.c
		$(CC) $(CFLAGS) -I/usr/include -Imlx_Linux -I./includes -c $< -o $@

$(NAME)	:	$(OBJS)
		make -C ./mlx_Linux
		$(CC) $(OBJS) -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz -o $@

clean	:
		make -C ./mlx_Linux clean
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean
		make all

.PHONY	:	all clean fclean re