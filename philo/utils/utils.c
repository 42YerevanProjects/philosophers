#include "../includes/philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	cleanup(t_mutex *mutex, t_data *data, t_philo *philos)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size = philos[0].data->philo_n;
	while (i < size)
		pthread_mutex_destroy(&mutex->m_forks[i++]);
	pthread_mutex_destroy(&mutex->m_write);
	free(mutex->m_forks);
	free(mutex);
	free(data);
	i = 0;
	while (i < size)
	{	
		pthread_mutex_destroy(philos[i].l_fork);
		pthread_mutex_destroy(philos[i].r_fork);
		i++;
	}
	free(philos);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_nbrlen(long n)
{
	int		size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * sign);
}
