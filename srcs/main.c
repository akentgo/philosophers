/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:17:58 by akent-go          #+#    #+#             */
/*   Updated: 2023/08/14 15:13:37 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	parser(int t_die, int t_sleep, int t_eat, int max_eat)
{
	if (t_die <= 0)
		return (error_type(3));
	else if (t_sleep <= 0)
		return (error_type(4));
	else if (t_eat <= 0)
		return (error_type(5));
	else if (max_eat != -1 && max_eat < 0)
		return (error_type(11));
}

int	main(int argc, char **argv)
{
	t_master	master;

	if (argc == 5)
	{
		if (ft_atoi(argv[1]) < 1)
			error_type(2);
		parser(ft_atoi(argv[2]), ft_atoi(argv[3]), ft_atoi(argv[4]), \
				-1);
		initialize_all(&master, argv, -1);
		launch_philosophers(&master);
	}
	else if (argc == 6)
	{
		if (ft_atoi(argv[1]) < 1)
			error_type(2);
		parser(ft_atoi(argv[2]), ft_atoi(argv[3]), ft_atoi(argv[4]), \
				ft_atoi(argv[5]));
		initialize_all(&master, argv, ft_atoi(argv[5]));
		launch_philosophers(&master);
	}
	else
		error_type(1);
	return (0);
}
