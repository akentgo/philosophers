#include "../includes/philo.h"

//the philosophers program must take either 4 or 5 arguments:
/*
    1-Number of philosophers
    2-time to die
    3-time to eat
    4-time to sleep
    5-OPTIONAL: Max number of times a philosopher has to eat
*/

void parser(int n_philo, int t_die, int t_sleep, int t_eat, int max_eat)
{
    if (n_philo <= 0)
        error_type(2);
    else if (t_die <= 0)
        error_type(3);
    else if (t_sleep <= 0)
        error_type(4);
    else if (t_eat <= 0)
        error_type(5);
    else if (max_eat != -1 && max_eat < 0)
        error_type(11);
}

int main(int argc, char **argv)
{
    t_master master;

    if (argc == 5)
    {
        parser(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]), \
                ft_atoi(argv[4]), -1);
        launch_philosophers();
    }
    else if (argc == 6)
    {
        parser(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]), \
                ft_atoi(argv[4]), ft_atoi(argv[5]));
        launch_philosophers();
    }
    else
        error_type(1);
    return (0);
}
