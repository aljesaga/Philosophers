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

int	main(int arc, char **arv)
{
	t_table	table;

	if (arc > 4 && arc < 7)
	{
		if (arv_analytics(arv, &table) == 1)
		{
			printf("philo == %ld\n", table.all_philos);
			printf("die == %ld\n", table.time_to_die);
			printf("eat == %ld\n", table.time_to_eat);
			printf("sleep == %ld\n", table.time_to_sleep);
			printf("comidas == %ld\n", table.n_of_foods);
		}
	}
	return (0);
}
