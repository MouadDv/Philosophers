/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:39:22 by milmi             #+#    #+#             */
/*   Updated: 2021/12/07 15:23:05 by milmi            ###   ########.fr       */
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
	t_stack	stack;
	t_philo *data;

	data = (t_philo *)arg;
	stack.starttime = get_time();
	if (stack.starttime == 0)
		return (NULL);
	stack.pid = data->pid;
	stack.timeseat = 0;
	while (1)
	{
		if (data->ac == 6 && stack.timeseat == data->n_t_p_e)
			break ;
		usleep(100);
		eat(data, &stack);
	}
	usleep(1000);
	data->status[stack.pid] = 1;
	return (NULL);
}

int	init_threads(t_philo *data)
{
	int		i;

	i = 0;
	data->philos = malloc(sizeof(pthread_t) * data->n);
	if (!data->philos)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n);
	if (!data->forks)
		return (0);
	data->status = malloc(sizeof(int) * data->n);
	if (!data->status)
		return (0);
	i = 0;
	while (i++ < data->n)
		data->status[i - 1] = 0;
	while (i++ < data->n)
		pthread_mutex_init(&(data->forks[i]), NULL);
	pthread_mutex_init(&(data->wr_m), NULL);
	i = 0;
	while (i < data->n)
	{
		data->pid = i;
		pthread_create(&(data->philos[i]), NULL, philosopher, data);
		usleep(10);
		i++;
	}
	// i = 0;
	// while (i++ < data->n)
	// 	pthread_join(data->philos[i], NULL);
	return (1);
	
}

int	main(int argc, char **argv)
{
	t_philo		*data;
	int			i;

	if (argc == 5 || argc == 6)
	{
		data = malloc(sizeof(t_philo));
		if (!init_struct(data, argc, argv))
			return (1);
		if (!init_threads(data))
			return (1);
		while (1)
		{
			usleep(100);
			if (data->philodeath)
				return (0);
			i = 0;
			while (i < data->n)
			{
				if (data->status[i % data->n] == 0)
					break ;
				i++;
			}
			if (i == data->n)
				return (0);
		}
	}
	return (0);
}
