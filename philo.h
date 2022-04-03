/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:13:47 by alsanche          #+#    #+#             */
/*   Updated: 2022/04/03 16:52:11 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>

typedef struct s_table
{
	long	all_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	n_of_foods;
}	t_table;

/* analytics */

int		arv_analytics(char **times, t_table *table);

/* philo */

int		main(int arc, char **arv);

#endif