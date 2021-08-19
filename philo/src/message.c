#include "../includes/philo.h"

int	print_status(t_philo *philo, char *msg)
{
	int		index;
	long	time;
	
	index = philo->index;
	time = get_time_ms() - philo->born_time_ms;
	printf("%ld #%d %s\n", time, index, msg);
	return (0);
}
