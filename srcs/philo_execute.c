/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:18:10 by akent-go          #+#    #+#             */
/*   Updated: 2023/08/11 18:43:33 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	launch_philosophers(t_master *master)
{
	t_philo	*philo;
	int		philo_ct;

	philo_ct = -1;
	philo = master->philos;
	master->first_timestamp = timestamp();
	while (++philo_ct < master->number_of_philos && \
			master->number_of_philos > 1)
	{
		if (pthread_create(&(philo[philo_ct].thread_id), NULL, \
					philo_rutine, &(philo[philo_ct])))
			return (error_type(10));
		philo[philo_ct].t_l_m = timestamp();
	}
	if (master->number_of_philos == 1)
		one_philo(master);
	free_philosopher(master);
}

void	free_philosopher(t_master *master)
{
	int	philo_ct;

	philo_ct = -1;
	while (++philo_ct < master->number_of_philos)
		pthread_join(master->philos[philo_ct].thread_id, NULL);
	philo_ct = -1;
	while (++philo_ct < master->number_of_philos)
		pthread_mutex_destroy(&(master->forks[philo_ct]));
	pthread_mutex_destroy(&(master->write));
	pthread_mutex_destroy(&(master->meal_mutex));
}

void	check_all_philos_have_eaten(t_master *master)
{
	int	i;
	int	ct;

	ct = 0;
	i = -1;
	while (++i < master->number_of_philos)
	{
		if (master->m_t_e > -1 && \
			master->philos[i].times_philo_has_eaten >= master->m_t_e)
			ct++;
	}
	if (ct == master->number_of_philos && master->m_t_e > -1)
		master->all_philos_have_eaten = 1;
}
