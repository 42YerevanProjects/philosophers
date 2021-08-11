#include "../includes/philosophers.h"

static void	init_data(t_data *data, int argc, char **argv)
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
		data->eat_n = ft_atoi(args[i + 4]);
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char **argv)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if (check_args(argc, argv) != 0)
		return (-1);
	init_data(data, argc, argv);
	printf("%d\n", data->philo_n);
	free(data);
	return (0);
}
