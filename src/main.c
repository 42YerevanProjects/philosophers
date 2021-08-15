#include "../includes/philosophers.h"

static int	launch_threads(t_philo *philos)
{
	int	i;
	int	size;
	int	ret;

	i = 0;
	size = philos[0].data->philo_n;
	while (i < size)
	{
		philos[i].born_time_ms = get_time_ms();
		ret = pthread_create(&philos[i].t_id, NULL, create_simulation, (void*)&philos[i]);
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
	int		i;
	int		size;
	int		ret;
	void	*status;

	i = 0;
	size = philos[0].data->philo_n;
	while (i < size)
	{
		ret = pthread_join((philos[i].t_id), &status);
		if (ret != 0)
		{
			printf("Something went wrong while joining a thread\n");
			free(status);
			return (-1);
		}
		if (*(int *)status != 0)
		{
			print_status(&philos[*(int *)status - 1], "died");
			free(status);
			return (0);
		}
		i++;
	}
	if (*(int *)status == 0)
		printf("Everyone ate enough!!!\n");
	free(status);
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
	if (!mutex || !data)
		return (-1);
	init_data(data, argc, argv);
	if (data->philo_n == 1)
	{
		printf("0 #1 died\n");
		return (-1);
	}
	init_mutex(mutex, data);
	philos = init_threads(data, mutex);
	if (launch_threads(philos) != 0)
		return (-1);
	if (join_threads(philos) != 0)
		return (-1);
	cleanup(mutex, data, philos);
	return (0);
}
