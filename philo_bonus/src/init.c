#include "../includes/philo_bonus.h"

void	init_semaphore(t_semaphore *sem, int len)
{
	sem_unlink("fork");
	sem_unlink("write");
	sem_unlink("end");
	sem->fork = sem_open("fork", O_CREAT | O_RDWR, 0660, len / 2);
	sem->write = sem_open("write", O_CREAT | O_RDWR, 0660, 1);
	sem->end = sem_open("end", O_CREAT | O_RDWR, 0660, 1);	
}

void	init_data(t_data *data, int argc, char **argv)
{
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	data->philo_n = ft_atoi(args[i]);
	data->die_t = ft_atoi(args[i + 1]);
	data->eat_t = ft_atoi(args[i + 2]);
	data->sleep_t = ft_atoi(args[i + 3]);
	if (args[i + 4] != NULL)
		data->eat_count = ft_atoi(args[i + 4]);
	else
		data->eat_count = -1;
	if (argc == 2)
		ft_free(args);
}


t_philo	*init_philos(t_data *data, t_semaphore *sem)
{
	t_philo *philos;
	int	i;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_n);
	while (i < data->philo_n)
	{
		philos[i].index = i + 1;
		philos[i].born_time_ms = 0;
		philos[i].last_meal = 0;
		philos[i].sem = sem;
		philos[i].data = data;
		i++;
	}
	return (philos);
}
