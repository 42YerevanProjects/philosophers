#include "../includes/philosophers.h"

static int launch_threads(t_philo *philos)
{
	int	i;
	int	size;
	int	ret;

	i = 0;
	size = philos[0].data->philo_n;
	while (i < size)
	{
		ret = pthread_create(&philos[i].t_id, NULL, create_simulation, &philos[i]);
		if (ret != 0)
		{
			printf("Something went wrong while creating a thread\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	join_threads(t_philo *philos)
{
	int	i;
	int size;
	int	ret;

	i = 0;
	size = philos[0].data->philo_n;
	while (i < size)
	{
		ret = pthread_join(philos[i].t_id, NULL);
		if (ret != 0)
		{
			printf("Something went wrong while creating a thread\n");
			return (-1);
		}
		i++;	
	}
	return (0);
}

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

	launch_threads(philos);
	join_threads(philos);

	return (0);
}

