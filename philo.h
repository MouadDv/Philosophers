#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct
{
	int					philodeath;
	int					pid;
	int					ac;
	int					n;
	int					t_d;
	int					t_e;
	int					t_s;
	int					n_t_p_e;
	int					*status;
	pthread_t			*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		wr_m;
}				t_philo;

typedef struct
{
	int					pid;
	long long			starttime;
	int					timeseat;
	
}				t_stack;

int			ft_atoi(const char *str);
long long	get_time(void);
void		mysleep(long long time);
void		eat(t_philo *data, t_stack *stack);

#endif