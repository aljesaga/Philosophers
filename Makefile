# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 18:29:44 by alsanche          #+#    #+#              #
#    Updated: 2022/04/22 18:29:45 by alsanche         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c analytics.c actions.c

OBJS = $(SRC:%.c=%.o)

CC = gcc

DFLAGS = -fsanitize=address

WFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $^ -o $@ $(CFLAGS) $(DFLAGS)

clean:
		rm -rf $(OBJS)

fclean:
		rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean