/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:52:09 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/12/04 04:57:52 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include "philo.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' && str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

long long	timestamp(void)
{
	struct timeval	t;
	long long		time;

	gettimeofday(&t, NULL);
	time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	return (time);
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	smart_sleep(long long time, t_rules *rules)
{
	long long	i;

	i = timestamp();
	while (!(rules->dieded))
	{
		if (time_diff(i, timestamp()) >= time)
			break ;
		usleep(5);
	}
}

int	ft_isdigit(char **array)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (!(array[i][j] >= '0' && array[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
