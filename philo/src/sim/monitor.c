/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:00:20 by nkanaan           #+#    #+#             */
/*   Updated: 2025/01/07 10:00:21 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/main.h"
#include "../../headers/utils.h"
#include "../../headers/philo.h"

bool	end_sim(t_sim *sim)
{
	bool	running;

	running = false;
	ft_mtx(&sim->mtx_running, MTX_LOCK);
	if (sim->running == false)
		running = true;
	ft_mtx(&sim->mtx_running, MTX_UNLOCK);
	return (running);
}

void	*monitor(void *ptr)
{
	t_sim	*sim;

	sim = (t_sim *)ptr;
	if (sim->times_must_eat == 0)
		return (NULL);
	ft_mtx(&sim->mtx_running, MTX_LOCK);
	sim->running = true;
	ft_mtx(&sim->mtx_running, MTX_UNLOCK);
	delay(sim->sim_start);
	while (true)
	{
		if (philos_full(sim) == true)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

bool	philos_dead(t_philo *philo)
{
	time_t	timestamp;

	timestamp = get_timestamp();
	if ((timestamp - philo->last_ate) >= philo->sim->time_to_die)
	{
			ft_mtx(&philo->sim->mtx_running, MTX_LOCK);
			philo->sim->running = false;
			ft_mtx(&philo->sim->mtx_running, MTX_UNLOCK);
			action_logger(DIE, philo);
			ft_mtx(&philo->mtx_meal, MTX_UNLOCK);
			return (true);
	}
	return (false);
}

bool	philos_full(t_sim *sim)
{
	int		i;
	bool	full;

	full = true;
	i = 0;
	while (i < sim->philo_nbr)
	{
		ft_mtx(&sim->philos[i]->mtx_meal, MTX_LOCK);
		if (philos_dead(sim->philos[i]))
			return (true);
		if (sim->philos[i]->eat_count < sim->times_must_eat)
			full = false;
		ft_mtx(&sim->philos[i]->mtx_meal, MTX_UNLOCK);
		i++;
	}
	if (sim->times_must_eat != -1 && full == true)
	{
		ft_mtx(&sim->mtx_running, MTX_LOCK);
		sim->running = false;
		ft_mtx(&sim->mtx_running, MTX_UNLOCK);
		return (true);
	}
	return (false);
}
