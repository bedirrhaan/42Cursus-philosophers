/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:52:04 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/12/05 06:10:38 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc != 5 && argc != 6)
		return (write_error("Invalid Argument"), 0);
	if (ft_isdigit(argv))
		return (write_error("Invalid Character Argument"), 0);
	if (parse(&rules, argv))
		return (write_error("Mutex Start Error"), 0);
	if (init_mutex(&rules))
		return (write_error("Mutex Init Error"), 0);
	if (init_philosophers(&rules))
		return (write_error("Philosophers Init Error"), 0);
	if (launcher(&rules))
		return (write_error("Thread Create Error"), 0);
}
