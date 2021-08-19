/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:42:31 by shovsepy          #+#    #+#             */
/*   Updated: 2021/08/19 18:42:33 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

typedef struct s_semaphore
{
	sem_t	*fork;
	sem_t	*write;
	sem_t	*end;
}				t_semaphore;

typedef struct s_data
{
	int	philo_n;
	int	die_t;
	int	eat_t;
	int	sleep_t;
	int	eat_count;
}			t_data;

typedef struct s_philo
{
	pid_t			pid;
	int				index;
	long long		born_time_ms;
	long long		last_meal;
	t_semaphore		*sem;
	t_data			*data;

}				t_philo;

// Util functions
int			ft_isdigit(int c);
void		ft_free(char **str);
long		ft_atoi(const char *str);
int			ft_nbrlen(long n);
size_t		ft_strlen(const char *s);
char		**ft_split(const char *s, char c);
void		ft_error(char *msg);
void		check_args(int argc, char **argv);
void		cleanup(t_philo *philos, t_semaphore *sem);

long long	get_time_ms(void);
void		ft_usleep(int length);

// Sources
void		init_semaphore(t_semaphore *sem, int len);
void		init_data(t_data *data, int argc, char **argv);
t_philo		*init_philos(t_data *data, t_semaphore *sem);
void		simulation_cycle(t_philo *philo);
void		print_status(t_philo *philo, char *msg);

#endif
