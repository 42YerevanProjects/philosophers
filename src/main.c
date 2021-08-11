#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_mutex	*mutex;
	t_data	*data;

	if (check_args(argc, argv) != 0)
		return (-1);

	mutex = (t_mutex *)malloc(sizeof(t_mutex));
	data = (t_data *)malloc(sizeof(t_data));

	init_data(data, argc, argv);
	init_mutex(mutex, data);
	philos = init_threads(data, mutex);

	printf("%d\n", philos[0].index);
	return (0);
}
