/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:13:47 by alsanche          #+#    #+#             */
/*   Updated: 2022/07/05 12:07:09 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				time_rest;
	long long		time_init;
	int				name;
	long			n_foods;
	int				l_fork;
	int				r_fork;
	pthread_t		philo_id;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	long				all_philos;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				n_of_foods;
	long				die;
	pthread_mutex_t		*fork;
	t_philo				*philo;
}	t_table;

/* analytics */

int			arv_analytics(char **times, t_table *table);

/* philo */

void		*philo_rutine(void *void_philo);
void		whit_out_limit(t_table *init);
int			main(int arc, char **arv);

/* actions */

void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

/* philo_utils */

int			its_a_life(t_table *init);
long long	time_now(void);
void		print_action(t_philo *philo, char *msn);

#endif