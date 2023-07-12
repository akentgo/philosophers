#include "../includes/philo.h"

void	philosopher_eats(t_philo *philos)
{
	t_master *master;

	master = philos->master;
	pthread_mutex_lock(&(master->forks[philos->left_fork_id]));
	print_ph(master, philos->philo_id, "has taken left fork");
	pthread_mutex_lock(&(master->forks[philos->right_fork_id]));
	print_ph(master, philos->philo_id, "has taken right fork");
	pthread_mutex_lock(&(master->meal_mutex));
	print_ph(master, philos->philo_id, "is eating");
	philos->time_since_last_meal = timestamp();
	if (master->max_times_eat != -1)
		philos->times_philo_has_eaten++;
	pthread_mutex_unlock(&(master->meal_mutex));
	pthread_mutex_unlock(&(master->forks[philos->right_fork_id]));
	pthread_mutex_unlock(&(master->forks[philos->left_fork_id]));
	check_all_philos_have_eaten(master);
	if (master->all_philos_have_eaten == 1)
	{
		free_philosopher(master);
		printf("All philosophers have eaten %i times.", master->max_times_eat);
		exit(0);
	}
}

void	philosopher_sleep(t_master *master)
{
	long long time;
	
	time = timestamp();
	while (!master->philo_has_died)
	{
		if (time >= master->time_to_sleep)
			return ;
		usleep(50);
	}
}

int		check_philosopher_dead(t_philo *philos)
{
	if (philos->time_since_last_meal > philos->master->time_to_eat)
	{
		print_ph(philos->master, philos->philo_id, "is dead");
		philos->master->philo_has_died = 1;
		return (1);
	}
	return (0);
}

void check_all_philos_have_eaten(t_master *master)
{
	int i;

	i = -1;
	while (++i <= master->number_of_philosophers)
	{
		if (&(master)->philos[i].times_philo_has_eaten >= &(master)->max_times_eat)
			master->all_philos_have_eaten = 1;
	}
}

void    *philo_rutine(void *philo)
{
	t_master	*master;
	t_philo		*philos;
	
	philos = (t_philo *)philo;
	master = philos->master;
	if (philos->philo_id % 2 == 0)
		usleep(15000);
	while (!(master->philo_has_died))
	{
		philosopher_eats(philos);
		if (master->all_philos_have_eaten)
			break ;
		print_ph(master, philos->philo_id, "is sleeping");
		philosopher_sleep(master);
		print_ph(master, philos->philo_id, "is thinking");
		if (!check_philosopher_dead(philos))
			break ;
	}
	return (NULL);
}