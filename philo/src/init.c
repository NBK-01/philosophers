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

void init_vars(char **args, int ac, t_vars *vars);
void init_mutex(t_vars *vars, t_routine *routine);

void init_philo(char **args, int ac)
{
	int i;
	t_vars vars;
	t_routine *routine;

	i = 0;
	init_vars(args, ac, &vars);
	routine = malloc(sizeof(t_routine));
	init_mutex(&vars, routine);

}

void init_mutex(t_vars *vars, t_routine *routine)
{
	int i;

	i = 0;
	routine->vars = vars;
	routine->sim_end = false; 
	routine->philos = malloc(sizeof(t_philo) * vars->nb_of_philos);
	routine->forks = malloc(sizeof(t_fork) * vars->nb_of_philos);
	while (i < vars->nb_of_philos) 
	{
		ft_mutex("init", &routine->forks[i].fork);
		routine->forks[i].id = i;
		i++;
	}
}

void	init_threads(t_routine *routine)
{
	int	i;
	t_philo *philo;

	i = -1;
	while (++i < routine->vars->nb_of_philos)
	{
		philo = routine->philos + i;
		philo->id = i - 1;
		philo->vars = routine->vars;
		philo->is_dead = false;
		philo->nb_of_times_ate = 0;
		philo->full = false;
		philo->fork_one = &routine->forks[i];
		philo->fork_two = &routine->forks[(i + 1) % routine->vars->nb_of_philos];
		pthread_create(&philo->tid, NULL, &routine, philo);
		i++;
	}
}

void init_vars(char **args, int ac, t_vars *vars) {
  vars->nb_of_philos = (ft_atoll(args[1]));
  vars->time_to_die = to_ms((ft_atoll(args[2])));
  vars->time_to_eat = to_ms((ft_atoll(args[3])));
  vars->time_to_sleep = to_ms((ft_atoll(args[4])));
  if (ac == 5)
    vars->nb_of_times_to_eat = (ft_atoll(args[5]));
  else
    vars->nb_of_times_to_eat = -42;
}
