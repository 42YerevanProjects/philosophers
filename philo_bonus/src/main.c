#include "../includes/philo_bonus.h"

static void	launch_process(t_philo *philos)
{
	int 	i;
	int		status;
	int		size;

	i = 0;
	size = philos[0].data->philo_n;
	while (i < size)
	{
		philos[i].born_time_ms = get_time_ms();
		philos[i].pid = fork();
		if (philos[i].pid == 0)
			simulation_cycle(&philos[i]);
		else if (philos[i].pid < 0)
			ft_error("Error while oppening a fork");
		i++;
	}
	i = 0;
	while (i++ < size)
		waitpid(philos[i].pid, &status, 0);
	printf("Every one has eaten enough!\n");
}

int	main(int argc, char **argv)
{
	t_philo		*philos;
	t_data		data;
	t_semaphore	sem;

	check_args(argc, argv);
	init_data(&data, argc, argv);
	if (data.philo_n == 1)
	{
		printf("0 #1 died\n");
		return (0);
	}
	init_semaphore(&sem, data.philo_n);
	philos = init_philos(&data, &sem);
	launch_process(philos);
	cleanup(philos, &sem);
	return (0);
}

