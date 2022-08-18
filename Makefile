# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 18:29:44 by alsanche          #+#    #+#              #
#    Updated: 2022/08/10 14:55:30 by alsanche         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c analytics.c actions.c \
	philo_utils.c

OBJS = $(SRC:%.c=%.o)

CC = gcc

WFLAGS = -Wall -Wextra -Werror -pthread #-g3 -fsanitize=thread

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $^ -o $@ $(WFLAGS)

clean:
	@	rm -rf $(OBJS)

fclean:
	@	make clean
	@	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean