/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   message.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: laura <laura@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 13:06:54 by laura         #+#    #+#                 */
/*   Updated: 2023/09/27 13:06:54 by laura         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include "../../include/philos.h"
#include "../../include/utils.h"

void	phi_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(philo->end);
	if (!*philo->funeral)
	{
		pthread_mutex_lock(philo->message);
		printf("%ld %d %s\n", phi_time() - philo->start, philo->number, message);
		pthread_mutex_unlock(philo->message);
	}
	pthread_mutex_unlock(philo->end);
}

void	phi_fork_message(t_philo *philo, char *message)
{
	long	time;

	time = phi_time() - philo->start;
	pthread_mutex_lock(philo->end);
	if (!*philo->funeral)
	{
		pthread_mutex_lock(philo->message);
		printf("%ld %d %s\n%ld %d %s\n", time, philo->number, message,
			   time, philo->number, message);
		pthread_mutex_unlock(philo->message);
	}
	pthread_mutex_unlock(philo->end);
}