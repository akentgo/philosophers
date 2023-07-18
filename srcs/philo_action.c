#include "../includes/philo.h"

void	philosopher_eats(t_philo *philos)
{
	t_master	*master;

	master = philos->master;
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
	print_ph(master, philos->philo_id, "has put down left fork");
	pthread_mutex_unlock(&(master->forks[philos->right_fork_id]));
	print_ph(master, philos->philo_id, "has put down right fork");
}

void	philosopher_sleep(t_master *master, long long t)
{
	long long	time;

	time = timestamp();
	while (!(master->philo_has_died))
	{
		if (time_difference(timestamp(), time) >= t)
			break ;
		usleep(50);
	}
}

void	check_philosopher_dead(t_master *m)
{
	int	philo_ct;

	while (!(m->all_philos_have_eaten))
	{
		philo_ct = -1;
		while (++philo_ct < m->number_of_philosophers && !m->philo_has_died)
		{
			pthread_mutex_lock(&(m->meal_mutex));
			if (time_difference(m->philos[philo_ct].time_since_last_meal, timestamp()) > m->time_to_die)
			{
				print_ph(m, philo_ct, "has died");
				m->philo_has_died = 1;
			}
			pthread_mutex_unlock(&(m->meal_mutex));
			usleep(100);
		}
		if (m->philo_has_died)
			break ;
		philo_ct = 0;
		while (m->max_times_eat != -1 && philo_ct < m->number_of_philosophers \
			&& m->philos[philo_ct].times_philo_has_eaten >= m->max_times_eat)
			philo_ct++;
		if (philo_ct == m->number_of_philosophers)
			m->all_philos_have_eaten = 1;
	}
}

void	one_philo(t_master *master)
{
	pthread_mutex_lock(&(master->forks[1]));
	print_ph(master, 1, "has taken left fork");
	while (master->philos[0].time_since_last_meal < master->time_to_eat)
		usleep(50);
	pthread_mutex_unlock(&(master->forks[1]));
	print_ph(master, 1, "has put down left fork");
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
		print_ph(master, philos->philo_id, "is sleeping");
		philosopher_sleep(master, master->time_to_sleep);
		print_ph(master, philos->philo_id, "is thinking");
	}
	return (NULL);
}
