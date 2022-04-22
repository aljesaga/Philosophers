/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analytics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:50:24 by alsanche          #+#    #+#             */
/*   Updated: 2022/04/22 19:40:50 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_long_atoi(const char *a)
{
	long long	n;
	long long	sig;

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
		table->all_philos = ft_long_atoi(times);
	else if (check == 2)
		table->time_to_die = ft_long_atoi(times);
	else if (check == 3)
		table->time_to_eat = ft_long_atoi(times);
	else if (check == 4)
		table->time_to_sleep = ft_long_atoi(times);
	else if (check == 5)
		table->n_of_foods = ft_long_atoi(times);
}

int	arv_analytics(char **times, t_table *table)
{
	int	i;
	int	x;

	i = 1;
	while (times[i])
	{
		x = 0;
		while (times[i][x] != '\0')
		{
			if (times[i][x] < 48 || times[i][x] > 57)
			{
				printf("Error\n Arv it is not numeric\n");
				return (0);
			}
			x++;
		}
		assign_arv(times[i], table, i);
		i++;
	}
	table->die = 1;
	return (1);
}
