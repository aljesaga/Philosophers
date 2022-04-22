/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:13:47 by alsanche          #+#    #+#             */
/*   Updated: 2022/04/03 16:52:11 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				time_rest;
	int				name;
	int				die;
	long			n_foods;
	int				l_fork;
	int				r_fork;
	struct s_table	*table;
} t_philo;

typedef struct s_table
{
	long				all_philos;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				n_of_foods;
	long				total_time;
	pthread_mutex_t		*fork;
	t_philo				*philo;
}	t_table;

/* analytics */

int		arv_analytics(char **times, t_table *table);

/* philo */

void	philo_rutine(t_philo *philo);
void	whit_out_limit(t_table *init);
int		main(int arc, char **arv);

/* actions */

void	take_the_forks(t_philo *philo);
void    eating(t_philo *philo);
void    put_the_forks(t_philo *philo);
void    sleeping(t_philo *philo);
void    thinking(t_philo *philo);

#endif