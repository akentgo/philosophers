#include "../includes/philo.h"

void    error_type(int error_code)
{
    if (error_code == 1)
        printf("Error 1: Number of arguments invalid");
    else if (error_code == 2)
        printf("Error 2: Invalid number of Philosophers");
    else if (error_code == 3)
        printf("Error 3: Time to die smaller than 1, Philo can't die");
    else if (error_code == 4)
        printf("Error 4: Time to sleep must be greater than 0");
    else if (error_code == 5)
        printf("Error 5: Time to sleep must be greater than 0");
    exit(-1);
}

