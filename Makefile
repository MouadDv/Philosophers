# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: milmi <milmi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 00:43:14 by milmi             #+#    #+#              #
#    Updated: 2021/11/15 06:06:37 by milmi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
SRCS = main.c
FLAGS = -Wall -Wextra -Werror -g
INCLUDES=./
all: $(NAME)
$(NAME):
	gcc $(FLAGS) $(SRCS) -o $(NAME)
clean:

fclean: clean
	rm -f $(NAME)
re:	fclean all
