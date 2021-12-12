/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:39:22 by milmi             #+#    #+#             */
/*   Updated: 2021/12/12 01:37:29 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval		time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	return (((time.tv_sec * 1000) * 1000) + time.tv_usec);
}

void	mysleep(long long time)
{
	long long	curr;
	long long	r;

	curr = get_time();
	r = time - 60;
	usleep(r * 1000);
	while (get_time() - curr < time * 1000)
	{
		continue ;
	}
}

int	ft_atoi(const char *str)
{
	int	j;
	int	c;
	int	f;

	j = 0;
	f = 1;
	c = 0;
	while (str[j] == '\r' || str[j] == '\v' || str[j] == '\b'
		|| str[j] == '\f' || str[j] == '\t'
		|| str[j] == '\n' || str[j] == ' ')
		j++;
	if (str[j] == '+' && str[j + 1] != '-')
		j++;
	if (str[j] == '-')
	{
		f = -1;
		j++;
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		c = c * 10 + str[j] - '0';
		j++;
	}
	return (c * f);
}

int	supervisor1(t_philo *data)
{
	int		i;

	i = 0;
	while (i < data->n)
	{
		if (data->timeseat[i] < data->n_t_p_e)
			break ;
		i++;
	}
	if (i == data->n)
		return (1);
	return (0);
}
