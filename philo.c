/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:39:36 by alsanche          #+#    #+#             */
/*   Updated: 2022/04/03 17:05:39 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_table *table_s, int i)
{
	table_s->philo[i].name = i;
	table_s->philo[i].die = 0;
	table_s->philo[i].n_foods = 0;
	table_s->philo[i].time_rest = 0;
	table_s->philo[i].table = table_s;
	table_s->philo[i].l_fork = i;
 	table_s->philo[i].r_fork = (i % table_s->all_philos) + 1;
}

static void	sit_on_the_table(t_table *table)
{
	int	i;

	i = table->all_philos;
	while(--i >= 0)
		pthread_mutex_init(&(table->fork[i]), NULL);
	while(++i <= table->all_philos)
		init_philo(table, i);
}

void	philo_rutine(t_philo *philo)
{
	while (philo->time_rest + 10 < philo->table->time_to_die)
	{
		take_the_forks(philo);
		eating(philo);
		put_the_forks(philo);
		sleeping(philo);
		thinking(philo);
	}
}

void	whit_out_limit(t_table *init)
{
	int i;

	i = 0;
	init->philo = malloc(sizeof(t_philo) * init->all_philos + 1);
	if (!init->philo)
		exit (0);
	init->fork = malloc(sizeof(pthread_mutex_t) * init->all_philos + 1);
	if (!init->fork)
		exit (0);
	sit_on_the_table(init);
	while (++i <= init->all_philos)
		printf("philo id: %d----rest_time: %ld\nl_fork: %d\nr_fork: %d\n", init->philo[i].name, init->philo[i].time_rest, init->philo[i].l_fork, init->philo[i].r_fork);
	/*philo_rutine(table);*/
	
}

int	main(int arc, char **arv)
{
	t_table		table;

	if (arc > 4 && arc < 7)
	{
		if (arv_analytics(arv, &table) == 1)
		{
			if (arc == 5)
				whit_out_limit(&table);
			else
				whit_out_limit(&table);
		}
	}
	else
		printf("Error\n Argimentos insuficientes\n");
	return (0);
}
