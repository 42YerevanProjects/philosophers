#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_mutexes
{
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_write;
}				t_mutex;

typedef struct s_data
{
	int	philo_n;
	int	die_t;
	int	eat_t;
	int	sleep_t;
	int	eat_count;	
	int	dead;
}				t_data;

typedef struct s_philo
{
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_t			t_id;
	int					index;
	long long			born_time_ms;
	long long			last_meal;
	long long			death_time;
	t_mutex				*mutex;
	t_data				*data;

}				t_philo;

// Util functions
int			ft_isdigit(int c);
void		ft_free(char **str);
long		ft_atoi(const char *str);
int			ft_nbrlen(long n);
size_t		ft_strlen(const char *s);
char		**ft_split(const char *s, char c);

int			check_args(int argc, char **argv);
long long	get_time_ms(void);
void		ft_usleep(int length);
void		cleanup(t_mutex *mutex, t_data *data, t_philo *philos);

// Sources
int			init_mutex(t_mutex *mutex, t_data *data);
void		init_data(t_data *data, int argc, char **argv);
t_philo		*init_threads(t_data *data, t_mutex *mutex);

void		*create_simulation(void *philosopher);
int		print_status(t_philo *philo, char *msg);

#endif

