/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:39:36 by alsanche          #+#    #+#             */
/*   Updated: 2022/04/22 20:11:09 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_table *table_s, int i)
{
	if (i < table_s->all_philos / 2)
		table_s->philo[i].name = i + 1;
	else
		table_s->philo[i].name = i;
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
	while (--i >= 0)
		pthread_mutex_init(&(table->fork[i]), NULL);
	while (++i <= table->all_philos)
		init_philo(table, i);
}

void	philo_rutine(t_philo *philo)
{
	int	i;

	i = philo->table->die;
	while (philo->time_rest + 9 < philo->table->time_to_die)
	{
		if (i == 1)
			i = take_the_forks(philo);
		if (i == 1)
			i = eating(philo);
		put_the_forks(philo);
		if (i == 1)
			i = sleeping(philo);
		if (i == 1)
			i = thinking(philo);
		sleep(10);
	}
	philo->table->die = i;
	printf("[%ld] %d : is die\n", philo->table->total_time, philo->name);
}

void	whit_out_limit(t_table *init)
{
	int	i;
	int	x;

	i = 0;
	x = init->all_philos;
	init->philo = malloc(sizeof(t_philo) * init->all_philos + 1);
	if (!init->philo)
		exit (0);
	init->fork = malloc(sizeof(pthread_mutex_t) * init->all_philos + 1);
	if (!init->fork)
		exit (0);
	sit_on_the_table(init);
	while (i != x)
	{
		philo_rutine(&init->philo[i]);
		if (init->die == 0)
			break ;
		philo_rutine(&init->philo[x]);
		i++;
		x--;
		if (init->die == 0)
			break ;
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
