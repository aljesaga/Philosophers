/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:39:36 by alsanche          #+#    #+#             */
/*   Updated: 2022/08/03 18:28:39 by alsanche         ###   ########lyon.fr   */
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
		philo[i]->n_foods = 0;
		philo[i]->name = i + 1;
		philo[i]->table = table_s;
		philo[i]->time_init = table_s->t_init;
		philo[i]->last_eat = table_s->t_init;
		pthread_mutex_init(&philo[i]->fork, NULL);
		pthread_mutex_init(&philo[i]->print, NULL);
	}
	i = -1;
	while (++i < table_s->all_philos - 1)
	{
		philo[i]->next = philo[i + 1];
	}
	philo[i]->next = philo[0];
}

void	whit_out_limit(t_table *init)
{
	int		i;
	t_philo	**philo;

	if (init->all_philos <= 1)
		exit (0);
	philo = malloc(sizeof(t_philo *) * init->all_philos);
	if (!philo)
		exit (127);
	init_philo(philo, init);
	i = -1;
	while (++i < init->all_philos)
		pthread_create(&philo[i]->id, NULL, philo_run, philo[i]);
	its_a_life(philo, init);
	i = -1;
	while (++i < init->all_philos)
		pthread_join(philo[i]->id, NULL);
	exit (0);
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
