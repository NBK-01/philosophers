/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:25:50 by nkanaan           #+#    #+#             */
/*   Updated: 2024/12/26 11:25:57 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"
#include "../../includes/utils.h"
#include "../../includes/philo.h"

static void	*monitor(void *thread);
static void	*run_sim(void *thread);

void	init_sim(int philos, t_routine	*routine)
{
	int			i;
	t_thread_id	monitor_thread;

	i = -1;
	if (pthread_create(&monitor_thread, NULL, &monitor, routine->philos) != 0)
	{
		print_msg("Failed to create monitor thread", ERROR);
		ft_destroy_mtx(routine);
	}
	while (++i < philos)
	{
		if (pthread_create(&routine->philos[i].thread_id, NULL, \
					&run_sim, &routine->philos[i]) != 0)
		{
			print_msg("Failed to create philo thread", ERROR);
			ft_destroy_mtx(routine);
		}
	}
	ft_thread(monitor_thread, JOIN, routine);
	i = -1;
	while (++i < philos)
		ft_thread(routine->philos[i].thread_id, DETACH, routine);
}

void	print_s(t_philo	*philo, t_action action)
{
	long	time;

	pthread_mutex_lock(philo->logging_mutex);
	time = get_timestamp() - philo->data->sim_start;
	print_action(philo->logging_mutex, time, philo->id, action);
	pthread_mutex_unlock(philo->logging_mutex);
}

void	ft_routine(t_philo *philo)
{
	ft_mutex(philo->left_fork, LOCK);
	print_s(philo, FORK);
	ft_mutex(philo->right_fork, LOCK);
	print_s(philo, FORK);
	ft_mutex(philo->eating_mutex, LOCK);
	print_s(philo, EAT);
	philo->data->last_ate = get_timestamp();
	philo->times_ate += 1;
	ft_mutex(philo->eating_mutex, UNLOCK);
	ft_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	log_wrapper(philo, SLEEP);
	ft_sleep(philo->data->time_to_sleep);
	log_wrapper(philo, THINK);
}

static void	*run_sim(void *thread)
{
	t_philo	*philo;

	philo = (t_philo *)thread;
	if (philo->id % 2 == 0)
		ft_sleep(1);
	ft_mutex(philo->eating_mutex, LOCK);
	philo->data->sim_start = get_timestamp();
	philo->data->last_ate = get_timestamp();
	ft_mutex(philo->eating_mutex, UNLOCK);
	while (1)
		ft_routine(philo);
	return (NULL);
}

static void	*monitor(void *thread)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)thread;
	while (1)
	{
		i = -1;
		while (++i < philos->nb_of_philos)
		{
			ft_mutex(philos->eating_mutex, LOCK);
			if (philos[i].data->last_ate + \
					philos[i].data->time_to_die < get_timestamp())
			{
				ft_mutex(philos->eating_mutex, UNLOCK);
				log_wrapper(&philos[i], DIE);
				ft_mutex(philos->logging_mutex, LOCK);
				return (NULL);
			}
			ft_mutex(philos->eating_mutex, UNLOCK);
		}
		if (philos_full(philos))
			return (NULL);
	}
	return (NULL);
}
