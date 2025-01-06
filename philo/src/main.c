#include "../headers/main.h"
#include "../headers/utils.h"
#include "../headers/philo.h"
#include <stdio.h>

static t_sim	*initialize(char **av)
{
	t_sim	*sim;

	sim = malloc(sizeof(t_sim));
	if (!sim)
		return (logger(MALLOC, ERR), NULL);
	init_data(sim, av);
	if ((sim->philos = init_philos(sim)) == NULL)
		return (NULL);
	if (!init_mtx(sim))
		return (NULL);
	print_art(sim->philo_nbr);
	return (sim);
}

static void	launch_sim(t_sim *sim)
{
	int	i;

	sim->sim_start = get_timestamp() + (sim->philo_nbr * 2 * 10);
	i = 0;
	while (i < sim->philo_nbr)
	{
		ft_thread(&sim->philos[i]->tid, THRD_CREATE, &simulation, sim->philos[i]);
		i++;
	}
	ft_thread(&sim->monitor, THRD_CREATE, &monitor, sim);
	return ;
}

static void	kill_sim(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->philo_nbr)
	{
		ft_thread(&sim->philos[i]->tid, THRD_JOIN, NULL, NULL);
		i++;
	}
	ft_thread(&sim->monitor, THRD_JOIN, NULL, NULL);
	clean_mtx(sim);
	ft_clean(sim);
}

int	main(int ac, char *argv[])
{
	t_sim	*sim;

	sim = NULL;
	if (!validate_args(ac, argv))
		ft_exit(NULL,  NULL,  ARG_ERROR, 0);
	sim = initialize(argv);
	launch_sim(sim);
	kill_sim(sim);
	return (EXIT_SUCCESS);
}
