#include "../includes/philo.h"

int	print_status(t_philo *philo, char *msg)
{
	int		index;
	long	time;
	if (philo->data->dead && philo->data->death_count != 1)
		return (-1);
	index = philo->index;
	time = get_time_ms() - philo->born_time_ms;
	printf("%ld #%d %s\n", time, index, msg);
	return (0);
}
