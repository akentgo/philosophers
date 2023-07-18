#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include "../libft_full/libft/libft.h"

struct	s_master;

typedef struct s_philo
{
	int				philo_id;
	int				left_fork_id;
	int				right_fork_id;
	int				times_philo_has_eaten;
	long long		time_since_last_meal;
	pthread_t		thread_id;
	struct s_master	*master;
}	t_philo;

typedef struct s_master
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				max_times_eat;
	int				philo_has_died;
	int				all_philos_have_eaten;
	long long		first_timestamp;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	write;
	t_philo			philos[250];
}	t_master;

//ERROR_MSG.C//
void		error_type(int error_code);
//INIT.C//
void		initialize_all(t_master *master, char **argv, int extra_arg);
//PHILO_ACTION.C//
void		*philo_rutine(void *philo);
void		one_philo(t_master *master);
void		check_philosopher_dead(t_master *master);
void		philosopher_sleep(t_master *master, long long t);
//PHILO_EXECUTE.C//
void		launch_philosophers(t_master *master);
void		free_philosopher(t_master *master);
//PRINT.C//
void		print_ph(t_master *master, int philo_id, char *to_print);
//TIME.C//
long long	timestamp(void);
long long	time_difference(long long present, long long past);

#endif
