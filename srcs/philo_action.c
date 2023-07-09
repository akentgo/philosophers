#include "../includes/philo.h"

void	philosopher_eats(t_philo *philos)
{
	t_master *master;

	master = &(philos->master);
	pthread_mutex_lock(&(master->forks[philos->left_fork_id]));
	print_ph(master, philos->philo_id, "has taken left fork");
	pthread_mutex_lock(&(master->forks[philos->right_fork_id]));
	print_ph(master, philos->philo_id, "has taken right fork");
	pthread_mutex_lock(&(master->meal_mutex));
	print_ph(master, philos->philo_id, "is eating");
	philos->time_since_last_meal = timestamp;
	if (master->max_times_eat != -1)
		philos->times_philo_has_eaten++;
	pthread_mutex_unlock(&(master->meal_mutex));
	pthread_mutex_unlock(&(master->forks[philos->right_fork_id]));
	pthread_mutex_unlock(&(master->forks[philos->left_fork_id]));
	//make a function that checks if all philosophers have eaten
}

void    *philo_rutine(void *philo)
{
	t_master	*master;
	t_philo		*philos;
	
	philos = philo;
	master = &(philos->master);
	if (philos->philo_id % 2 == 0)
		usleep(15000);
	while (!(master->philo_has_died))
	{
		philosopher_eats(master);
		
	}
}