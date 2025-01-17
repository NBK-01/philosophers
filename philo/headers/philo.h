/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:36:13 by nkanaan           #+#    #+#             */
/*   Updated: 2025/01/09 09:36:14 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "main.h"

bool	validate_args(int ac, char *av[]);
void	init_data(t_sim *sim, char **av);
t_philo	**init_philos(t_sim *sim);
bool	init_mtx(t_sim *sim);
bool	end_sim(t_sim *sim);
bool	philos_full(t_sim *sim);
void	*monitor(void *ptr);
void	*simulation(void *ptr);
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_eat(t_philo *philo);
bool	philos_dead(t_philo *philo);

#endif // !PHILO_H
