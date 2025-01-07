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

void	*simulation(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	ft_mtx(&philo->mtx_meal, MTX_LOCK);
	philo->last_ate = philo->sim->sim_start;
	ft_mtx(&philo->mtx_meal, MTX_UNLOCK);
	delay(philo->sim->sim_start);
	if (philo->id % 2)
		philo_think(philo, true);
	while (!(end_sim(philo->sim)))
	{
		philo_eat(philo);
		philo_think(philo, false);
	}
	return (NULL);
}
