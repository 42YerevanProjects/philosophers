#include "../includes/philo.h"

long long	get_time_ms(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep(int length)
{
	long long	time;

	time = get_time_ms();
	while (get_time_ms() < time + length)
		usleep(length);
}
