/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:40:58 by shovsepy          #+#    #+#             */
/*   Updated: 2021/08/19 18:40:59 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	get_len(char **args)
{
	int	len;

	len = 0;
	while (args[len])
		len++;
	return (len);
}

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

int	check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc != 5 && argc != 6 && argc != 2)
	{
		printf("Error: The number of arguments should be 4 or 5\n");
		return (-1);
	}
	if (argc == 2)
	{	
		args = ft_split(argv[1], ' ');
		if (get_len(args) != 4 && get_len(args) != 5)
		{
			ft_free(args);
			printf("Error: The number of arguments should be 4 or 5\n");
			return (-1);
		}
	}
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
		{
			printf("Error: the arguments contain non-numeric value!\n");
			return (-1);
		}
		if (tmp < -2147483648 || tmp > 2147483647)
		{
			printf("Error: numbers exceeding the limits of an integer!\n");
			return (-1);
		}
		i++;
	}
	if (argc == 2)
		ft_free(args);
	return (0);
}
