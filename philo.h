/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:13:47 by alsanche          #+#    #+#             */
/*   Updated: 2022/08/02 13:30:34 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				last_eat;
	size_t			time_init;
	int				name;
	int				n_foods;
	pthread_t		id;
	pthread_mutex_t	fork;
	pthread_mutex_t	print;
	struct s_philo	*next;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int			all_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			n_of_foods;
	int			die;
	size_t		t_init;
	t_philo		**philo;
}	t_table;

/* analytics */

int			arv_analytics(char **times, t_table *table);

/* philo */

void		whit_out_limit(t_table *init);
int			main(int arc, char **arv);

/* actions */

void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		*philo_run(void *void_philo);

/* philo_utils */

int			its_a_life(t_table *init);
size_t		time_now(void);
void		print_action(t_philo *philo, char *msn);

#endif