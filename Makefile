# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 18:29:44 by alsanche          #+#    #+#              #
#    Updated: 2022/07/04 11:55:18 by alsanche         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c analytics.c actions.c \
	philo_utils.c

OBJS = $(SRC:%.c=%.o)

CC = gcc

DFLAGS = -fsanitize=address -g3

WFLAGS = -Wall -Wextra -Werror
WFLAGS += $(DFLAGS)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $^ -o $@ $(CFLAGS) $(DFLAGS)

clean:
	@	rm -rf $(OBJS)

fclean:
	@	make clean
	@	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean