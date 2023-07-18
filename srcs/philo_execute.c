#include "../includes/philo.h"

void	launch_philosophers(t_master *master)
{
	t_philo	*philo;
	int		philo_ct;

	philo_ct = -1;
	philo = master->philos;
	master->first_timestamp = timestamp();
	while (++philo_ct < master->number_of_philos)
	{
		if (pthread_create(&(philo[philo_ct].thread_id), NULL, \
					philo_rutine, (&philo[philo_ct])))
			return (error_type(10));
		philo[philo_ct].t_l_m = timestamp();
	}
	if (master->number_of_philos > 1)
		check_philosopher_dead(master);
	else
		one_philo(master);
	free_philosopher(master);
}

void	free_philosopher(t_master *master)
{
	int	philo_ct;

	philo_ct = master->number_of_philos + 1;
	while (--philo_ct >= 0)
		pthread_join(master->philos[philo_ct].thread_id, NULL);
	while (philo_ct <= master->number_of_philos)
	{
		pthread_mutex_destroy(&(master->forks[philo_ct]));
		philo_ct++;
	}
	pthread_mutex_destroy(&(master->write));
	pthread_mutex_destroy(&(master->meal_mutex));
}
