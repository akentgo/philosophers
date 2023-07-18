/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:17:49 by akent-go          #+#    #+#             */
/*   Updated: 2023/07/18 17:17:51 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	initialize_philo(t_master *master)
{
	int	philo_ct;

	philo_ct = 0;
	while (++philo_ct <= master->number_of_philos)
	{
		master->philos[philo_ct].philo_id = philo_ct;
		master->philos[philo_ct].left_fork_id = philo_ct;
		master->philos[philo_ct].right_fork_id = (philo_ct + 1) % \
				master->number_of_philos;
		master->philos[philo_ct].times_philo_has_eaten = 0;
		master->philos[philo_ct].t_l_m = 0;
		master->philos[philo_ct].master = master;
	}
}

void	initialize_mutexes(t_master *master)
{
	int	philo_ct;

	philo_ct = 0;
	while (philo_ct < master->number_of_philos)
	{
		if (pthread_mutex_init(&(master->forks[philo_ct]), NULL))
			return (error_type(6));
		philo_ct++;
	}
	if (pthread_mutex_init(&(master->write), NULL))
		return (error_type(7));
	if (pthread_mutex_init(&(master->meal_mutex), NULL))
		return (error_type(8));
}

void	initialize_master(t_master *master, char **argv, int max_eat)
{
	master->philo_has_died = 0;
	master->all_philos_have_eaten = 0;
	master->number_of_philos = ft_atoi(argv[1]);
	master->t_d = ft_atoi(argv[2]);
	master->time_to_sleep = ft_atoi(argv[3]);
	master->time_to_eat = ft_atoi(argv[4]);
	if (max_eat != -1)
		master->m_t_e = ft_atoi(argv[5]);
	else
		master->m_t_e = -1;
}

void	initialize_all(t_master *master, char **argv, int extra_arg)
{
	initialize_master(master, argv, extra_arg);
	initialize_mutexes(master);
	initialize_philo(master);
}
