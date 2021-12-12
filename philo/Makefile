# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: milmi <milmi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 00:43:14 by milmi             #+#    #+#              #
#    Updated: 2021/12/12 02:26:08 by milmi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = main.c philo.c utils.c
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRCS:.c=.o)
all: $(NAME)

$(NAME): $(SRCS) philo.h
	gcc $(FLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "No object files to be cleaned!"

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re