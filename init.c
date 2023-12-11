/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:51:45 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/12/11 17:00:24 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

int	init_mutex(t_rules *rules)
{
	int	i;

	i = rules->nb_philo;
	rules->forks = malloc(sizeof(pthread_mutex_t) * i);
	if (!(rules->forks))
		return (free(rules->philosophers), 1);
	if (!destroy_mutex(rules))
		return (free(rules->philosophers), 1);
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
		{
			while (++i < rules->nb_philo)
				pthread_mutex_destroy(&(rules->forks[i]));
			free(rules->philosophers);
			return (chose_mutex(rules, 7), 1);
		}
	}
	return (0);
}

int	destroy_mutex(t_rules *rules)
{
	if (pthread_mutex_init(&(rules->writing), NULL))
		return (0);
	else if (pthread_mutex_init(&(rules->meal_check), NULL))
		return (chose_mutex(rules, 1), 0);
	else if (pthread_mutex_init(&(rules->die_check), NULL))
		return (chose_mutex(rules, 2), 0);
	else if (pthread_mutex_init(&(rules->x_ate_check), NULL))
		return (chose_mutex(rules, 3), 0);
	else if (pthread_mutex_init(&(rules->t_last_meal_check), NULL))
		return (chose_mutex(rules, 4), 0);
	else if (pthread_mutex_init(&(rules->dieded_check), NULL))
		return (chose_mutex(rules, 5), 0);
	else if (pthread_mutex_init(&(rules->all_ate_check), NULL))
		return (chose_mutex(rules, 6), 0);
	else if (pthread_mutex_init(&(rules->die_write), NULL))
		return (chose_mutex(rules, 7), 0);
	return (1);
}

void	chose_mutex(t_rules *rules, int x)
{
	if (x >= 1)
		pthread_mutex_destroy(&(rules->writing));
	if (x >= 2)
		pthread_mutex_destroy(&(rules->meal_check));
	if (x >= 3)
		pthread_mutex_destroy(&(rules->die_check));
	if (x >= 4)
		pthread_mutex_destroy(&(rules->x_ate_check));
	if (x >= 5)
		pthread_mutex_destroy(&(rules->t_last_meal_check));
	if (x >= 6)
		pthread_mutex_destroy(&(rules->dieded_check));
	if (x >= 7)
		pthread_mutex_destroy(&(rules->all_ate_check));
}

int	init_philosophers(t_rules *rules)
{
	int	i;

	i = rules->nb_philo;
	rules->philosophers = malloc(sizeof(t_philosopher) * i);
	if (!(rules->philosophers))
		return (1);
	while (--i >= 0)
	{
		rules->philosophers[i].id = i;
		rules->philosophers[i].x_ate = 0;
		rules->philosophers[i].left_fork_id = i;
		rules->philosophers[i].right_fork_id = (i + 1) % rules->nb_philo;
		rules->philosophers[i].t_last_meal = 0;
		rules->philosophers[i].rules = rules;
	}
	return (0);
}

int	parse(t_rules *rules, char **argv)
{
	rules->nb_philo = ft_atoi(argv[1]);
	if (rules->nb_philo > 200)
		return (write_error("Ayip degil mi?"), 1);
	rules->time_death = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	rules->all_ate = 0;
	rules->dieded = 0;
	if (rules->nb_philo <= 0 || rules->time_death <= 0 || rules->time_eat <= 0
		|| rules->time_sleep <= 0)
		return (1);
	if (argv[5])
	{
		rules->nb_eat = ft_atoi(argv[5]);
		if (rules->nb_eat <= 0)
			return (1);
	}
	else
		rules->nb_eat = -1;
	return (0);
}
