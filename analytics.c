/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analytics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:50:24 by alsanche          #+#    #+#             */
/*   Updated: 2022/08/04 16:10:36 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *a)
{
	int	n;
	int	sig;

	n = 0;
	sig = 1;
	while ((*a == 32) || (*a >= 9 && *a <= 13))
		a++;
	if (*a == 45)
		sig = -1;
	if (*a == 43 || *a == 45)
		a++;
	while (*a >= 48 && *a <= 57)
	{
		if ((n * sig) > 2147483647)
			return (-1);
		else if ((n * sig) < -2147483648)
			return (0);
		n = n * 10 + *a - 48;
		a++;
	}
	return (n * sig);
}

static void	assign_arv(char *times, t_table *table, int check)
{
	if (check == 1)
		table->all_philos = ft_atoi(times);
	else if (check == 2)
		table->time_to_die = ft_atoi(times);
	else if (check == 3)
		table->time_to_eat = ft_atoi(times);
	else if (check == 4)
		table->time_to_sleep = ft_atoi(times);
	else if (check == 5)
		table->n_of_foods = ft_atoi(times);
}

int	arv_analytics(char **times, t_table *table)
{
	int	i;
	int	x;

	i = 0;
	while (times[++i])
	{
		x = -1;
		while (times[i][++x] != '\0')
		{
			if (times[i][x] < 48 || times[i][x] > 57)
			{
				printf("Error\n argument it is not numeric\n");
				return (0);
			}
		}
		assign_arv(times[i], table, i);
	}
	if (times[5] == NULL)
		table->n_of_foods = -1;
	table->die = 0;
	table->t_init = time_now();
	pthread_mutex_init(&table->life, NULL);
	pthread_mutex_init(&table->print, NULL);
	return (1);
}
