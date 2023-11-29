/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:52:04 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/11/29 11:17:08 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc != 5 && argc != 6)
		return (write_error("Invalid Argument"));
	if (parse(&rules, argv))
		return (write_error("Mutex Start Error"));
	if (init_philosophers(&rules))
		return (write_error("Philosophers Init Error"));
	if (init_mutex(&rules))
		return (write_error("Mutex Init Error"));
	if (launcher(&rules))
		return (write_error("Thread Create Error"));
	ft_free(&rules);
}
