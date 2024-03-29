/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:13:47 by alsanche          #+#    #+#             */
/*   Updated: 2022/08/12 18:12:08 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define C "\033[1;36m"
# define M "\033[1;35m"
# define Y "\033[1;33m"
# define R "\033[1;31m"
# define G "\033[1;32m"
# define W "\033[1;37m"
# define RESET "\033[0m"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	long			last_eat;
	int				name;
	int				n_foods;
	pthread_t		*id;
	pthread_mutex_t	fork;
	struct s_philo	*next;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int				all_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_of_foods;
	int				die;
	long			t_init;
	t_philo			**philo;
	pthread_mutex_t	print;
	pthread_mutex_t	life;
}	t_table;

/* analytics */

int			arv_analytics(char **times, t_table *table);

/* philo */

void		whit_out_limit(t_table *init);
int			main(int arc, char **arv);

/* actions */

void		actions(t_philo *philo);
void		*philo_run(void *void_philo);

/* philo_utils */

void		its_a_life(t_philo **philo, t_table *table);
void		free_exit(t_table *table, t_philo **philo);
long		time_now(void);
void		print_action(t_philo *philo, char *msn, char *color);

#endif