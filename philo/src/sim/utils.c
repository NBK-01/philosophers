/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:00:26 by nkanaan           #+#    #+#             */
/*   Updated: 2025/01/07 10:00:26 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/main.h"
#include "../../headers/utils.h"
#include "../../headers/philo.h"
#include <stdbool.h>

void	philo_eat(t_philo *philo)
{
	ft_mtx(&philo->sim->forks[philo->left_fork],  MTX_LOCK);
	action_logger(FORK, philo);
	ft_mtx(&philo->sim->forks[philo->right_fork],  MTX_LOCK);
	action_logger(FORK, philo);
	action_logger(EAT, philo);
	ft_mtx(&philo->mtx_meal, MTX_LOCK);
	philo->last_ate = get_timestamp();
	ft_mtx(&philo->mtx_meal, MTX_UNLOCK);
	ft_sleep(philo->sim, philo->sim->time_to_eat);
	if (!(end_sim(philo->sim)))
	{
		ft_mtx(&philo->mtx_meal, MTX_LOCK);
		philo->eat_count++;
		ft_mtx(&philo->mtx_meal, MTX_UNLOCK);
	}
	action_logger(SLEEP, philo);
	ft_mtx(&philo->sim->forks[philo->right_fork],  MTX_UNLOCK);
	ft_mtx(&philo->sim->forks[philo->left_fork],  MTX_UNLOCK);
	ft_sleep(philo->sim, philo->sim->time_to_sleep);
}

void	philo_sleep(t_philo *philo)
{
	action_logger(SLEEP, philo);
	ft_mtx(&philo->sim->forks[philo->right_fork],  MTX_UNLOCK);
	ft_mtx(&philo->sim->forks[philo->left_fork],  MTX_UNLOCK);
	ft_sleep(philo->sim, philo->sim->time_to_sleep);
}

void	philo_think(t_philo *philo, bool print)
{
	long	ttt;

	ft_mtx(&philo->mtx_meal, MTX_LOCK);
	ttt = (philo->sim->time_to_die
			- (get_timestamp() - philo->last_ate)
			- philo->sim->time_to_eat) / 2;
	ft_mtx(&philo->mtx_meal, MTX_UNLOCK);
	if (ttt < 0)
		ttt = 0;
	if (ttt == 0 && print == true)
		ttt = 1;
	if (ttt > 600)
		ttt = 200;
	if (print == false)
		action_logger(THINK, philo);
	ft_sleep(philo->sim, ttt);
}


