#include "../includes/philo.h"

//in this file we setup the functions for managing time, for now we need 2 functions:
/*
    One function to determine what time it is now and another to
    return the difference between the time now and before, with this last function the 
    philosopher can calculate the ammount of time used to either eat, sleep or think.
    Thus this file being one of the core files for our philosophers to work
*/

/*
    This function is simple, we initialize a timeval struct variable and store the
    current system time, then since we want the miliseconds, we return the seconds / 1000
    plus the microseconds * 1000 (check time sistem if any doubts)
*/
int timestamp(void)
{
    struct timeval time;
    if (gettimeofday(&time, NULL) == -1)
        error_type(9);
    return ((time.tv_sec / 1000) + (time.tv_usec * 1000));
}

long long   time_difference(long long present, long long past)
{
    return (past - present);
}
