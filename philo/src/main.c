#include "../headers/main.h"
#include "../headers/utils.h"
#include "../headers/philo.h"

static bool	initialize(t_sim *sim, char **av)
{
	sim = malloc(sizeof(t_sim));
	if (!sim)
		return (logger(MALLOC, ERR), false);
	init_data(sim, av);
	if ((sim->philos = init_philos(sim)) == NULL)
		return (false);
	if (!init_mtx(sim))
		return (false);
	printf("left fork id is %d\n", sim->philos[0]->left_fork);
	print_art(sim->philo_nbr);
	return (true);
}

int	main(int ac, char *argv[])
{
	t_sim	sim;

	if (!validate_args(ac, argv))
		ft_exit(NULL,  NULL,  ARG_ERROR, 0);
	if (!initialize(&sim, argv))
		ft_exit(&sim, NULL, ERR, 1);
	return (EXIT_SUCCESS);
}
