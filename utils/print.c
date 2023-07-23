/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:18:16 by akent-go          #+#    #+#             */
/*   Updated: 2023/07/23 10:00:15 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_ph(t_master *master, int philo_id, char *to_print)
{
	pthread_mutex_lock(&(master->write));
	printf("%lli %i %s\n", timestamp() - \
			master->first_timestamp, philo_id, to_print);
	pthread_mutex_unlock(&(master->write));
}
