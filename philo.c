/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:39:36 by alsanche          #+#    #+#             */
/*   Updated: 2022/08/18 16:35:14 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_philo **philo, t_table *table_s)
{
	int		i;

	i = -1;
	while (++i < table_s->all_philos)
	{
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->id = malloc(sizeof(pthread_t));
		if (table_s->n_of_foods != -1)
			philo[i]->n_foods = 0;
		philo[i]->name = i + 1;
		philo[i]->table = table_s;
		philo[i]->last_eat = table_s->t_init;
		pthread_mutex_init(&philo[i]->fork, NULL);
	}
	i = -1;
	while (++i < table_s->all_philos - 1)
	{
		philo[i]->next = philo[i + 1];
	}
	philo[i]->next = philo[0];
}

void	free_exit(t_table *table, t_philo **philo)
{
	int	i;

	i = table->all_philos;
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->life);
	while (--i > -1)
	{
		pthread_mutex_destroy(&philo[i]->fork);
		free(philo[i]->id);
		free(philo[i]);
	}
}

void	whit_out_limit(t_table *table)
{
	int		i;
	t_philo	**philo;

	philo = malloc(sizeof(t_philo *) * table->all_philos);
	if (!philo)
	{
		pthread_mutex_destroy(&table->print);
		pthread_mutex_destroy(&table->life);
		return ;
	}
	init_philo(philo, table);
	i = -1;
	while (++i < table->all_philos)
		pthread_create(philo[i]->id, NULL, philo_run, philo[i]);
	its_a_life(philo, table);
	i = -1;
	while (++i < table->all_philos)
		pthread_join(*philo[i]->id, NULL);
	free_exit(table, philo);
	free(philo);
}

int	main(int arc, char **arv)
{
	t_table			table;

	if (arc > 4 && arc < 7)
	{
		if (arv_analytics(arv, &table) == 1)
			whit_out_limit(&table);
	}
	else
		printf("Error\n Argimentos insuficientes\n");
	return (0);
}
