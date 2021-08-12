#include "../includes/philosophers.h"

static void	philosopher_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->l_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->mutex->m_write);
	print_status(philo, "is eating");
	usleep(philo->data->eat_t * 1000);
	philo->last_meal = get_time_ms();
	philo->data->meal_counter++;
	pthread_mutex_unlock(&philo->mutex->m_write);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
}

static void	philosopher_sleep_and_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->data->sleep_t * 1000);
	print_status(philo, "is thinking");
}

void	*create_simulation(void	*philosopher)
{
	t_philo	*philo;
	int		limit;

	philo = (t_philo *) philosopher;
	limit = philo->data->eat_count;
	while (limit)
	{
		philosopher_eat(philo);
		philosopher_sleep_and_think(philo);
		if (limit != -1)
			limit--;
		usleep(10 * 1000);
	}
}

