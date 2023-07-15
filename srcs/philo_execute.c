#include "../includes/philo.h"

/*
    Right, from this point on it gets complicated, we are going to need 2 variables, one will be a counter for the philosophers
    and another, a structure t_philo variable which will be our threads
    We need to store the first timestamp for when our program starts so we can calculate time properly
    Now, for each philosopher we create a thread and execute the philosopher's respective routine so whilst philosophers are
    created, others are already starting their rutine
    We set the timestamp to the current time and move onto the next philosopher
*/
void    launch_philosophers(t_master *master)
{
    t_philo *philo;
    int     philo_ct;

    philo_ct = -1;
    philo = master->philos;
    master->first_timestamp = timestamp();
    while (++philo_ct < master->number_of_philosophers)
    {
        if (pthread_create(&(philo[philo_ct].thread_id), NULL, \
                        philo_rutine, (&philo[philo_ct])))
                return (error_type(10));
        philo[philo_ct].time_since_last_meal = timestamp();
    }
    if (master->number_of_philosophers > 1)
        check_philosopher_dead(master);
    free_philosopher(master);
}

void    free_philosopher(t_master *master)
{
    int philo_ct;

    philo_ct = master->number_of_philosophers + 1;
    while (--philo_ct >= 0)
        pthread_join(master->philos[philo_ct].thread_id, NULL);
    while (philo_ct <= master->number_of_philosophers)
    {
        pthread_mutex_destroy(&(master->forks[philo_ct]));
        philo_ct++;
    }
    pthread_mutex_destroy(&(master->write));
    pthread_mutex_destroy(&(master->meal_mutex));
}
