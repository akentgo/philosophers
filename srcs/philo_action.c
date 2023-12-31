/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:18:05 by akent-go          #+#    #+#             */
/*   Updated: 2023/08/14 15:11:53 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philosopher_eats(t_philo *philos)
{
	t_master	*master;

	master = philos->master;
	pthread_mutex_lock(&(master->forks[philos->left_fork_id]));
	print_ph(master, philos->philo_id, "has taken a fork");
	pthread_mutex_lock(&(master->forks[philos->right_fork_id]));
	print_ph(master, philos->philo_id, "has taken a fork");
	pthread_mutex_lock(&(master->meal_mutex));
	print_ph(master, philos->philo_id, "is eating");
	philos->t_l_m = timestamp();
	pthread_mutex_unlock(&(master->meal_mutex));
	philos->times_philo_has_eaten++;
	philosopher_sleep(master, master->time_to_eat);
	pthread_mutex_unlock(&(master->forks[philos->left_fork_id]));
	pthread_mutex_unlock(&(master->forks[philos->right_fork_id]));
}

void	philosopher_sleep(t_master *master, long long t)
{
	long long	time;

	time = timestamp();
	while (!(master->philo_has_died))
	{
		check_philosopher_dead(master, master->philos);
		if (master->philo_has_died)
			return ;
		if (time_difference(timestamp(), time) >= t)
			return ;
		usleep(50);
	}
}

void	check_philosopher_dead(t_master *m, t_philo *p)
{
	if (time_difference(timestamp(), p[p->philo_id].t_l_m) > m->t_d)
	{
		print_ph(m, p->philo_id, "has died");
		m->philo_has_died = 1;
	}
	check_all_philos_have_eaten(m);
}

void	one_philo(t_master *master)
{
	pthread_mutex_lock(&(master->forks[0]));
	print_ph(master, 1, "has taken left fork");
	philosopher_sleep(master, master->t_d);
	pthread_mutex_unlock(&(master->forks[0]));
	print_ph(master, 1, "has died");
	free_philosopher(master);
}

void	*philo_rutine(void *philo)
{
	t_master	*master;
	t_philo		*philos;

	philos = (t_philo *)philo;
	master = philos->master;
	if (philos->philo_id % 2)
		usleep(15000);
	while (!(master->philo_has_died))
	{
		philosopher_eats(philos);
		if (master->all_philos_have_eaten)
			break ;
		if (master->philo_has_died)
			return (NULL);
		print_ph(master, philos->philo_id, "is sleeping");
		philosopher_sleep(master, master->time_to_sleep);
		if (master->all_philos_have_eaten)
			break ;
		if (master->philo_has_died)
			return (NULL);
		print_ph(master, philos->philo_id, "is thinking");
		if (master->all_philos_have_eaten)
			break ;
	}
	return (NULL);
}
