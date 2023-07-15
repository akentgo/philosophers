#include "../includes/philo.h"

void	philosopher_eats(t_philo *philos)
{
	t_master *master;

	master = philos->master;
	if (master->number_of_philosophers == 1)
	{
		pthread_mutex_lock(&(master->forks[philos->left_fork_id]));
		print_ph(master, philos->philo_id, "has taken left fork");
		philosopher_sleep(master, master->time_to_die + 1);
		master->philo_has_died = 1;
		pthread_mutex_unlock(&(master->meal_mutex));
		print_ph(master, philos->philo_id, "has died");
		return ;
	}
	pthread_mutex_lock(&(master->forks[philos->left_fork_id]));
	print_ph(master, philos->philo_id, "has taken left fork");
	pthread_mutex_lock(&(master->forks[philos->right_fork_id]));
	print_ph(master, philos->philo_id, "has taken right fork");
	pthread_mutex_lock(&(master->meal_mutex));
	print_ph(master, philos->philo_id, "is eating");
	philos->time_since_last_meal = timestamp();
	pthread_mutex_unlock(&(master->meal_mutex));
	philosopher_sleep(master, master->time_to_eat);
	philos->times_philo_has_eaten++;
	pthread_mutex_unlock(&(master->forks[philos->left_fork_id]));
	pthread_mutex_unlock(&(master->forks[philos->right_fork_id]));
}

void	philosopher_sleep(t_master *master, long long t)
{
	long long time;
	
	time = timestamp();
	while (!(master->philo_has_died))
	{
		if (time_difference(time, timestamp() >= t))
			break ;
		usleep(50);
	}
}

void		check_philosopher_dead(t_master *master)
{
	int	philo_ct;

	while (!(master->all_philos_have_eaten))
	{
		philo_ct = 0;
		while (philo_ct < master->number_of_philosophers && !master->philo_has_died)
		{
			pthread_mutex_lock(&(master->meal_mutex));
			if (time_difference(timestamp(), master->philos[philo_ct].time_since_last_meal) > master->philos[philo_ct].master->time_to_die)
			{
				print_ph(master, master->philos[philo_ct].philo_id, "has died");
				master->philo_has_died = 1;
			}
			pthread_mutex_unlock(&(master->meal_mutex));
			philo_ct++;
			usleep(100);
		}
		if (master->philo_has_died)
			break ;
		philo_ct = 0;
		while (master->max_times_eat != -1 && philo_ct < master->number_of_philosophers && master->philos[philo_ct].times_philo_has_eaten >= master->max_times_eat)
			philo_ct++;
		if (philo_ct == master->number_of_philosophers)
			master->all_philos_have_eaten = 1;
	}
}


void    *philo_rutine(void *philo)
{
	t_master	*master;
	t_philo		*philos;
	
	philos = (t_philo *)philo;
	master = philos->master;
	if (philos->philo_id % 2)
		usleep(10000);
	while (!(master->philo_has_died))
	{
		philosopher_eats(philos);
		if (master->number_of_philosophers > 1)
		{
			if (master->all_philos_have_eaten)
				break ;
			print_ph(master, philos->philo_id, "is sleeping");
			philosopher_sleep(master, timestamp());
			print_ph(master, philos->philo_id, "is thinking");
		}
	}
	return (NULL);
}