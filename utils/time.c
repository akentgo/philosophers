#include "../includes/philo.h"

long long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	time_difference(long long present, long long past)
{
	return (present - past);
}
