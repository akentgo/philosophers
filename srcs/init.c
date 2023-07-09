#include "../includes/philo.h"

//this file is for the functions that will initialize both structures

/*
    Here we initialize the values for each philosopher let me explain line 
    Why don't I just write down the right fork id as philo_ct? Because there would be a conflict between the first
    and last philosopher when it is time to grab the fork, say there are 6 philosophers, the first philo (id = 0)
    would take for 0 and (0 + 1) % 6 = 1 so on and so forth, what happens with philosopher 6?
    He takes fork 6 as his left fork but fork 7 does not exist because fork 7 is actually the first fork, so fork 0
    (5 + 1) % 6 = 0, the last philosopher takes the first fork and that is how you would make the round table
*/
void    initialize_philo(t_master *master)
{
    int id;
    int philo_ct;

    philo_ct = master->number_of_philosophers + 1;
    id = 0;
    while (--philo_ct >= 0)
    {
        master->philos[philo_ct].philo_id = id;
        master->philos[philo_ct].left_fork_id = id;
        master->philos[philo_ct].right_fork_id = (philo_ct + 1) % \
                master->number_of_philosophers;
        master->philos[philo_ct].times_philo_has_eaten = 0;
        master->philos[philo_ct].time_since_last_meal = 0;
        master->philos[philo_ct].master = master;
    }
}

/*
    Here we initialize every mutex so that 2 philosophers can't grab the same fork at the same time
    As well as initializing the mutexes for write, so that we don't have data races when writing on screen
    Lastly I initialize a meal mutex so that nothing else can happen while the philosopher is eating
*/
void    initialize_mutexes(t_master *master)
{
    int philo_ct;

    philo_ct = master->number_of_philosophers + 1;
    while (--philo_ct >= 0)
    {
       if (pthread_mutex_init(&(master->forks[philo_ct]), NULL) != 0) //we are initializing a mutex for each fork and setting the attributes to the default
            error_type(6);
    }
    if (pthread_mutex_init(&(master->write), NULL) != 0)
        error_type(7);
    if (pthread_mutex_init(&(master->meal_mutex), NULL) != 0)
        error_type(8);
}


/*
    This function initializes the base variables set by the user at the beginning of the program
*/
void    initialize_master(t_master *master, char **argv, int max_eat)
{
    master->philo_has_died = 0;
    master->all_philos_have_eaten = 0;
    master->number_of_philosophers = ft_atoi(argv[1]);
    master->time_to_die = ft_atoi(argv[2]);
    master->time_to_sleep = ft_atoi(argv[3]);
    master->time_to_eat = ft_atoi(argv[4]);
    if (max_eat != -1)
        master->max_times_eat = ft_atoi(argv[5]);
    else
        master->max_times_eat = -1;
}

int initialize_all(t_master *master, char **argv, int extra_arg)
{
    initialize_master(master, argv, extra_arg);
    initialize_mutexes(master);
    initialize_philo(master);
}
