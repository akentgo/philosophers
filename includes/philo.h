#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct  s_philo //this structure contains the information of each individual philosopher, so each philosopher has all of this information inside
{
    int philo_id;
    int left_fork_id;
    int right_fork_id;
    int times_philo_has_eaten;
    long long time_since_last_meal;
    struct s_master master;

}   t_philo;

typedef struct  s_master
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_sleep;
    int time_to_eat;
    int max_times_eat;
    int philo_has_died;
    int all_philos_have_eaten;
    long long first_timestamp;  //this variable stores the first time the program executes thus starting the philosophers timer
    pthread_mutex_t meal_mutex;
    pthread_mutex_t forks[250];
    pthread_mutex_t write;
    t_philo philos[250];

}   t_master;

void    error_type(int error_code);


#endif