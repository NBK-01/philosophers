/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:46:25 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/24 16:46:27 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	init_vars(char **args, int ac, t_vars *vars);

void	init_philo(char **args, int ac)
{
	int i;
	t_vars	vars;
	t_philo	*philo;
	
	init_vars(args, ac, &vars);
}

void	init_vars(char **args, int ac, t_vars *vars)
{
	vars->nb_of_philos = (ft_atoll(args[1]));
	vars->time_to_die = to_ms((ft_atoll(args[2])));
	vars->time_to_eat = to_ms((ft_atoll(args[3])));
	vars->time_to_sleep = to_ms((ft_atoll(args[4])));
	if (ac == 5)
		vars->nb_of_times_to_eat = (ft_atoll(args[5]));
	else
		vars->nb_of_times_to_eat = -42;
}
