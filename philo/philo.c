/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:39:22 by milmi             #+#    #+#             */
/*   Updated: 2021/12/13 00:14:42 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *data, int pid, char *str)
{
	pthread_mutex_lock(&(data->wr_m));
	printf("%lld %d %s\n", get_time() / 1000, pid + 1, str);
	pthread_mutex_unlock(&(data->wr_m));
}

void	eat_sleep_think(t_philo *data, int pid)
{
	pthread_mutex_lock(&(data->forks[pid]));
	print(data, pid, "has taken a fork");
	pthread_mutex_lock(&(data->forks[(pid + 1) % data->n]));
	print(data, pid, "has taken a fork");
	print(data, pid, "is eating");
	data->timeseat[pid]++;
	data->starttime[pid] = get_time();
	mysleep(data->t_e);
	pthread_mutex_unlock(&(data->forks[pid]));
	pthread_mutex_unlock(&(data->forks[(pid + 1) % data->n]));
	print(data, pid, "is sleeping");
	mysleep(data->t_s);
	print(data, pid, "is thinking");
}

void	freealloc(t_philo *data)
{
	int		i;

	i = 0;
	while (i < data->n)
	{
		pthread_detach(data->philos[i]);
		i++;
	}
	free(data->philos);
	free(data->starttime);
	free(data->timeseat);
	i = 0;
	while (i++ < data->n)
		pthread_mutex_destroy(&(data->forks[i - 1]));
	pthread_mutex_destroy(&(data->wr_m));
	free(data->forks);
	free(data);
}
