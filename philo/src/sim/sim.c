/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:00:23 by nkanaan           #+#    #+#             */
/*   Updated: 2025/01/07 10:00:24 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/main.h"
#include "../../headers/utils.h"
#include "../../headers/philo.h"

static void	*solo_sim(t_philo *philo)
{
	long	timestamp;

	ft_mtx(&philo->sim->forks[philo->left_fork], MTX_LOCK);
	ft_mtx(&philo->sim->mtx_logger, MTX_LOCK);
	timestamp = get_timestamp() - philo->sim->sim_start;
	printf("-- %ld philo [#%d] %s\n", timestamp, philo->id + 1, FORK);
	ft_mtx(&philo->sim->mtx_logger, MTX_UNLOCK);
	ft_sleep(philo->sim, philo->sim->time_to_die);
	print_death(philo);
	ft_mtx(&philo->sim->forks[philo->left_fork], MTX_UNLOCK);
	return (NULL);
}

void	*simulation(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->sim->times_must_eat == 0)
		return (NULL);
	ft_mtx(&philo->mtx_meal, MTX_LOCK);
	philo->last_ate = philo->sim->sim_start;
	ft_mtx(&philo->mtx_meal, MTX_UNLOCK);
	delay(philo->sim->sim_start);
	if (philo->sim->philo_nbr == 1)
		return (solo_sim(philo));
	if (philo->id % 2)
		philo_think(philo);
	while (!(end_sim(philo->sim)))
	{
		philo_eat(philo);
		philo_think(philo);
	}
	return (NULL);
}
