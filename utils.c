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
	while (get_time() - curr < time * 1000);
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