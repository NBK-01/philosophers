/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:25:37 by nkanaan           #+#    #+#             */
/*   Updated: 2024/12/26 11:25:39 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
#include "../includes/utils.h"
#include "../includes/philo.h"

static void	initialize(char	*av[], int ac);

int	main(int ac, char *av[])
{
	print_art();
	if (!validate_args(av, ac - 1))
		exit (ERROR);
	else
		initialize(av, ac - 1);
}

static void	initialize(char	*av[], int ac)
{
	t_philo		philo[MAX_PHILO];
	t_mutex		forks[MAX_PHILO];
	t_routine	routine;
	int			i;

	routine.forks = forks;
	routine.philos = philo;
	if (ft_mutex(&routine.logging_mutex, INIT != 0)
		|| ft_mutex(&routine.eating_mutex, INIT) != 0)
		ft_destroy_mtx(&routine);
	i = -1;
	while (++i < ft_atoll(av[1]))
	{
		if (ft_mutex(&forks[i], INIT) != 0)
			ft_destroy_mtx(&routine);
	}
	init_data(philo, av, ac);
	init_routine(philo, forks, &routine);
	init_sim(philo->nb_of_philos, &routine);
	ft_destroy_mtx(&routine);
	return ;
}
