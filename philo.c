#include "philo.h"

void	print(t_philo *data, t_stack *stack, char *str)
{
	pthread_mutex_lock(&(data->wr_m));
	printf("%lld %d %s\n", get_time() / 1000, stack->pid + 1, str);
	pthread_mutex_unlock(&(data->wr_m));
}

void	eat(t_philo *data, t_stack *stack)
{
	pthread_mutex_lock(&(data->forks[stack->pid]));
	pthread_mutex_lock(&(data->forks[(stack->pid + 1) % data->n]));
	if (get_time() - stack->starttime >  data->t_d * 1000)
	{
		pthread_mutex_lock(&(data->wr_m));
		printf("%lld %d died\n", get_time() / 1000, stack->pid + 1);
		data->philodeath = 1;
	}
	print(data, stack, "has taken a fork");
	print(data, stack, "is eating");
	stack->timeseat++;
	mysleep(data->t_e);
	stack->starttime = get_time();
	pthread_mutex_unlock(&(data->forks[stack->pid]));
	pthread_mutex_unlock(&(data->forks[(stack->pid + 1) % data->n]));
	print(data, stack, "is sleeping");
	mysleep(data->t_s);
	print(data, stack, "is thinking");
}