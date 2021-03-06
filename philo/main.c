/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:39:22 by milmi             #+#    #+#             */
/*   Updated: 2021/12/13 00:12:46 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_struct(t_philo *data, int argc, char **argv)
{
	data->ac = argc;
	data->philodeath = 0;
	data->n = ft_atoi(argv[1]);
	if (data->n > 200 || data->n < 0)
		return (0);
	data->t_d = ft_atoi(argv[2]);
	if (data->t_d < 60)
		return (0);
	data->t_e = ft_atoi(argv[3]);
	if (data->t_e < 60)
		return (0);
	data->t_s = ft_atoi(argv[4]);
	if (data->t_s < 60)
		return (0);
	if (argc == 6)
	{
		data->n_t_p_e = ft_atoi(argv[5]);
		if (data->n_t_p_e < 0)
			return (0);
	}
	return (1);
}

void	*philosopher(void *arg)
{
	int		pid;
	t_philo	*data;

	data = (t_philo *)arg;
	pid = data->pid;
	data->starttime[pid] = get_time();
	if (data->starttime[pid] == 0)
		return (NULL);
	data->timeseat[pid] = 0;
	while (1)
		eat_sleep_think(data, pid);
	return (NULL);
}

int	init_threads(t_philo *data, int i)
{
	data->philos = malloc(sizeof(pthread_t) * data->n);
	if (!data->philos)
		return (0);
	data->starttime = malloc(sizeof(long long) * data->n);
	if (!data->starttime)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n);
	if (!data->forks)
		return (0);
	data->timeseat = malloc(sizeof(int) * data->n);
	if (!data->timeseat)
		return (0);
	i = -1;
	while (++i < data->n)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			return (0);
	}
	if (pthread_mutex_init(&(data->wr_m), NULL))
		return (0);
	return (1);
}

void	mythreadjoin(t_philo *data)
{
	int	i;

	usleep(50000);
	while (1)
	{
		if (data->ac == 6)
		{
			if (supervisor1(data))
				return ;
		}
		i = -1;
		while (++i < data->n)
		{
			if ((data->ac == 6 && data->timeseat[i] < data->n_t_p_e)
				|| data->ac == 5)
			{
				if ((get_time() - data->starttime[i]) >= (data->t_d) * 1000)
				{
					pthread_mutex_lock(&(data->wr_m));
					printf("%lld %d died\n", get_time() / 1000, i + 1);
					return ;
				}
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_philo		*data;
	int			i;

	if (argc == 5 || argc == 6)
	{
		data = malloc(sizeof(t_philo));
		if (!data)
			return (1);
		if (!init_struct(data, argc, argv))
			return (1);
		if (!init_threads(data, 0))
			return (1);
		i = 0;
		while (i < data->n)
		{
			data->pid = i;
			if (pthread_create(&(data->philos[i]), 0, philosopher, data) != 0)
				return (1);
			usleep(100);
			i++;
		}
		mythreadjoin(data);
		freealloc(data);
	}
	return (0);
}
