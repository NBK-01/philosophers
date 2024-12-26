/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:26:06 by nkanaan           #+#    #+#             */
/*   Updated: 2024/12/26 11:26:07 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"
#include "../../includes/utils.h"

int	ft_mutex(t_mutex *mutex, t_action action)
{
	if (action == LOCK)
		return (pthread_mutex_lock(mutex));
	else if (action == UNLOCK)
		return (pthread_mutex_unlock(mutex));
	else if (action == INIT)
		return (pthread_mutex_init(mutex, NULL));
	else if (action == DESTROY)
		return (pthread_mutex_destroy(mutex));
	return (0);
}

void	ft_destroy_mtx(t_routine *routine)
{
	int	i;

	i = -1;
	while (++i < routine->philos->nb_of_philos)
		ft_mutex(&routine->forks[i], DESTROY);
	ft_mutex(&routine->eating_mutex, DESTROY);
	ft_mutex(&routine->logging_mutex, DESTROY);
}

int	ft_thread(t_thread_id id, t_action action, t_routine *routine)
{
	if (action == JOIN)
	{
		if (pthread_join(id, NULL) != 0)
			ft_destroy_mtx(routine);
	}
	else if (action == DETACH)
	{
		if (pthread_detach(id) != 0)
			ft_destroy_mtx(routine);
	}
	return (0);
}

long	get_timestamp(void)
{
	struct timeval	time;
	long			timestamp;

	gettimeofday(&time, NULL);
	timestamp = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (timestamp);
}

void	ft_sleep(long ms)
{
	long	start;

	start = get_timestamp();
	while (get_timestamp() - start < ms)
		usleep(500);
}
