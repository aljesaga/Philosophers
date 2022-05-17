/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:39:36 by alsanche          #+#    #+#             */
/*   Updated: 2022/05/17 15:11:30 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_table *table_s, int i)
{
	table_s->philo[i].name = i + 1;
	table_s->philo[i].n_foods = 0;
	table_s->philo[i].time_rest = 0;
	table_s->philo[i].table = table_s;
	table_s->philo[i].l_fork = i;
	table_s->philo[i].r_fork = (i % table_s->all_philos);
}

static void	sit_on_the_table(t_table *table)
{
	int	i;

	i = table->all_philos;
	while (--i >= 0)
		pthread_mutex_init(&(table->fork[i]), NULL);
	i = table->all_philos;
	while (--i >= 0)
		init_philo(table, i);
}

void	*philo_rutine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->name % 2 == 1)
		usleep(50);
	while (philo->table->die == 0)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	whit_out_limit(t_table *init)
{
	int	i;

	i = 0;
	init->philo = malloc(sizeof(t_philo) * init->all_philos);
	if (!init->philo)
		exit (0);
	init->fork = malloc(sizeof(pthread_mutex_t) * init->all_philos + 1);
	if (!init->fork)
		exit (0);
	sit_on_the_table(init);
	while (i < init->all_philos)
	{
		pthread_create(&(init->philo[i].philo_id), NULL, philo_rutine, &(init->philo[i]));
		i++;
	}
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
