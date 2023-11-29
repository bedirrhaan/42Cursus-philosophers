/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:51:52 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/29 11:01:23 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdlib.h>

int	write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

void	ft_free(t_rules *rules)
{
	free (rules->forks);
	free (rules->philosophers);
}

void	eat_control(t_rules *r, t_philosopher *p)
{
	int	i;

	i = 0;
	while (r->nb_eat != -1 && i < r->nb_philo && p[i].x_ate >= r->nb_eat)
		i++;
	if (i == r->nb_philo)
		r->all_ate = 1;
}
