#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>


typedef struct	s_mutexes
{
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_write;
	pthread_mutex_t m_num_of_meals;
}				t_mutex;

typedef struct	s_data
{
	int	philo_n;
	int	die_t;
	int	eat_t;
	int	sleep_t;
	int	eat_count;
	int	meal_counter;			
}				t_data;

typedef struct	s_philo
{
	pthread_mutex_t	r_fork;
	pthread_mutex_t l_fork;
	pthread_t		t_id;
	int				index;
	long			born_time_ms;
	long			last_meal;
	t_mutex			*mutex;
	t_data			*data;

}				t_philo;

// Util functions
int		ft_isdigit(int c);
void	ft_free(char **str);
long	ft_atoi(const char *str);
int		ft_nbrlen(long n);
size_t	ft_strlen(const char *s);

char	**ft_split(const char *s, char c);
int		check_args(int argc, char **argv);

long	get_time_ms(void);
void	ft_usleep(int length);

// Sources
int		init_mutex(t_mutex *mutex, t_data *data);
void	init_data(t_data *data, int argc, char **argv);
t_philo	*init_threads(t_data *data, t_mutex *mutex);

#endif

