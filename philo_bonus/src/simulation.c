/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:47:05 by shovsepy          #+#    #+#             */
/*   Updated: 2021/08/19 18:47:07 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	*check_is_alive(void *ptr)
{
	t_philo		*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		sem_wait(philo->sem->end);
		if (get_time_ms() - philo->last_meal > philo->data->die_t)
		{
			print_status(philo, "died");
			kill(0, SIGINT);
			return (NULL);
		}
		sem_post(philo->sem->end);
		usleep(1000);
	}
	return (NULL);
}

static void	philosopher_eat(t_philo *philo)
{
	sem_wait(philo->sem->fork);
	print_status(philo, "has taken a fork");
	print_status(philo, "has taken a fork");
	philo->last_meal = get_time_ms();
	print_status(philo, "is eating");
	usleep(philo->data->eat_t * 1000);
	sem_post(philo->sem->fork);
}

static void	philosopher_sleep_and_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->data->sleep_t * 1000);
	print_status(philo, "is thinking");
}

void	simulation_cycle(t_philo *philo)
{
	int			loop;
	pthread_t	thread_id;

	loop = philo->data->eat_count;
	philo->last_meal = get_time_ms();
	pthread_create(&thread_id, NULL, &check_is_alive, (void *)philo);
	while (loop != 0)
	{
		philosopher_eat(philo);
		philosopher_sleep_and_think(philo);
		usleep(1000);
		if (loop != -1)
			loop--;
	}
	exit(0);
}
