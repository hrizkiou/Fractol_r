# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/10 18:41:36 by hrizkiou          #+#    #+#              #
#    Updated: 2020/10/15 01:50:51 by hrizkiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lmlx -framework OpenGL -framework AppKit
SRCS = main.c
NAME = fractol

# OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME):$(OBJS)
	@make -C libft
	# @$(CC) $(CFLAGS) libft/libft.a $(MFLAGS) -o $(NAME)
	@$(CC) $(SRCS) libft/libft.a $(MFLAGS) -o $(NAME)
clean:
	@make clean -C libft
	@rm -rf $(OBJS)

fclean:clean
	@make fclean -C libft
	@rm -rf $(OBJS) $(NAME)

re: fclean all
