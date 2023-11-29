/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:52:16 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/28 23:18:22 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_philosopher
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_rules		*rules;
	pthread_t			thread_id;
}						t_philosopher;

typedef struct s_rules
{
	int					nb_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	int					dieded;
	int					all_ate;
	long long			first_timestamp;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		*forks;
	pthread_mutex_t		writing;
	t_philosopher		*philosophers;
}						t_rules;

/*
** ----- error_manager.c -----
*/

int						write_error(char *str);
int						error_manager(int error);
void					eat_control(t_rules *r, t_philosopher *p);

/*
** ----- init.c -----
*/

int						init_all(t_rules *rules, char **argv);

/*
** ----- utils.c -----
*/

int						ft_atoi(const char *str);
void					action_print(t_rules *rules, int id, char *string);
long long				timestamp(void);
long long				time_diff(long long past, long long pres);
void					smart_sleep(long long time, t_rules *rules);

/*
** ----- launcher.c -----
*/

int						launcher(t_rules *rules);
void					exit_launcher(t_rules *rules, t_philosopher *philos);

#endif
