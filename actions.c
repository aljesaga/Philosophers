#include "philo.h"

void	take_the_forks(t_philo *philo)
{
   /* pthread_mutex_lock(table->fork);*/
    philo->table->total_time += 5;
    printf("[%ld]   %d : has take a fork\n", philo->table->total_time, philo->name);
    philo->time_rest += 5;
    if (philo->time_rest + 9 > philo->table->time_to_die)
        exit (0);
    usleep(5);
}

void    eating(t_philo *philo)
{
    philo->table->total_time += philo->table->time_to_eat;
    printf("[%ld]   %d : is eating\n", philo->table->total_time, philo->name);
    philo->time_rest = 0;
    if (philo->time_rest + 9 > philo->table->time_to_die)
        exit (0);
    usleep(philo->table->time_to_eat);
}

void    put_the_forks(t_philo *philo)
{
    /*pthread_mutex_unlock(table->fork);*/
    philo->table->total_time += 5;
    philo->time_rest += 5;
}

void    sleeping(t_philo *philo)
{
    philo->table->total_time += philo->table->time_to_sleep;
    printf("[%ld]   %d : is sleeping\n", philo->table->total_time, philo->name);
    philo->time_rest += philo->table->time_to_sleep;
    if (philo->time_rest + 9 > philo->table->time_to_die)
        exit (0);
    usleep(philo->table->time_to_sleep); 
}

void    thinking(t_philo *philo)
{
    philo->table->total_time += philo->table->time_to_sleep;
    printf("[%ld]   %d : is thinking\n", philo->table->total_time, philo->name);
    philo->time_rest += philo->table->time_to_sleep;
    if (philo->time_rest + 9 > philo->table->time_to_die)
        exit (0);
    usleep(philo->table->time_to_sleep);
}
