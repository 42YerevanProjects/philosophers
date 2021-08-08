#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct	s_data
{
	int	philo_n;
	int	die_t;
	int	eat_t;
	int	sleep_t;
	int	eat_n;
}				t_data;

void	ft_error(char *msg);
int		ft_isdigit(int c);
void	ft_free(char **str);
long	ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
void	check_args(int argc, char **argv);

#endif

