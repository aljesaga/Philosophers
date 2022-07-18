/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:47:00 by alsanche          #+#    #+#             */
/*   Updated: 2022/07/05 11:48:04 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	its_a_life(t_table *init)
{
	if (init->die == 1)
	{
		return (0);
	}
	return (1);
}

long long	time_now(void)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	return ((tm.tv_sec * 1000) + (tm.tv_usec / 1000));
}

void	print_action(t_philo *philo, char *msn)
{
	printf("[%lld] ", time_now() - philo->time_init);
	printf("%d: ", philo->name);
	printf("%s\n", msn);
}
