#include "../includes/philo.h"

void	print_ph(t_master *master, int philo_id, char *to_print)
{
	pthread_mutex_lock(&(master->write));
	printf("%lli: Philosopher %i %s\n", timestamp() - \
			master->first_timestamp, philo_id, to_print);
	pthread_mutex_unlock(&(master->write));
}
