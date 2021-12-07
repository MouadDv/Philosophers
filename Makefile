# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: milmi <milmi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 00:43:14 by milmi             #+#    #+#              #
#    Updated: 2021/12/07 14:09:49 by milmi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
SRCS = main.c philo.c utils.c
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) -o $(NAME)
	
clean:
	rm -rf philo.dSYM
fclean: clean
	rm -f $(NAME)

re:	fclean all
