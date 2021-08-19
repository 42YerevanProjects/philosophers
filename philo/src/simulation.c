#include "../includes/philo.h"

static int	is_dead(t_philo *philo)
{
	if (philo->last_meal == 0)
		return (0);
	if ((get_time_ms() - philo->last_meal) <= philo->data->die_t)
		return (0);
	philo->death_time = get_time_ms();
	return (1);
}

static void	philosopher_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	philo->last_meal = get_time_ms();
	print_status(philo, "has taken a fork");
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->mutex->m_write);
	print_status(philo, "is eating");
	pthread_mutex_unlock(&philo->mutex->m_write);
	usleep(philo->data->eat_t * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
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
	int		*ret;

	philo = (t_philo *) philosopher;
	limit = philo->data->eat_count;
	ret = malloc(sizeof(int));
	*ret = 0;
	while (limit && !philo->data->dead)
	{
		philosopher_eat(philo);
		if (is_dead(philo) && limit == -1)
		{	
			*ret = philo->index;
			philo->data->dead = 1;
			return ((void *)ret);
		}
		philosopher_sleep_and_think(philo);
		if (is_dead(philo) && limit == -1)
		{	
			*ret = philo->index;
			philo->data->dead = 1;
			return ((void *)ret);
		}
		if (limit != -1)
			limit--;
	}
	return ((void *)ret);
}
