/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:39:22 by milmi             #+#    #+#             */
/*   Updated: 2021/12/12 01:53:53 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	long long			*starttime;
	int					philodeath;
	int					pid;
	int					ac;
	int					n;
	long long			t_d;
	int					t_e;
	int					t_s;
	int					n_t_p_e;
	int					*status;
	int					*timeseat;
	pthread_t			*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		wr_m;
}				t_philo;

int			ft_atoi(const char *str);
long long	get_time(void);
void		mysleep(long long time);
void		eat_sleep_think(t_philo *data, int pid);
void		freealloc(t_philo *data);
int			supervisor1(t_philo *data);

#endif