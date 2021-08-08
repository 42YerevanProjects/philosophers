#include "../includes/philo_one.h"

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc != 6 && argc != 7)
		ft_error("Error: The number of arguments should be 5 or 6");
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error("Error: the arguments contain non-numeric value!");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error: arguments contain numbers exceeding the limits of an integer!");
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
