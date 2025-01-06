#include "../headers/main.h"
#include "../headers/utils.h"
#include <stdbool.h>

static t_mtx *init_forks(t_sim *sim)
{
	t_mtx	*forks;
	int		i;

	i = 0;
	forks = malloc(sizeof(t_mtx) * sim->philo_nbr);
	if (!forks)
		return (logger(MALLOC, ERR), NULL);
	while (i < sim->philo_nbr)
	{
		sim->philos[i]->left_fork = sim->philos[i]->id ;
		sim->philos[i]->right_fork = (sim->philos[i]->id + 1) % sim->philo_nbr;
		if (sim->philos[i]->id % 2)
		{
			sim->philos[i]->left_fork = (sim->philos[i]->id + 1) % sim->philo_nbr;
			sim->philos[i]->right_fork = sim->philos[i]->id;
		}
		ft_mtx(&forks[i], MTX_INIT);
		i++;
	}
	return (forks);

}

bool	init_mtx(t_sim *sim)
{
	if ((sim->forks = init_forks(sim)) == NULL)
		return (logger(MALLOC, ERR), false);
	ft_mtx(&sim->mtx_logger, MTX_INIT);
	ft_mtx(&sim->mtx_running, MTX_INIT);
	return (true);
}

t_philo	**init_philos(t_sim *sim)
{
	int	i;
	t_philo	**philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * sim->philo_nbr);
	if (!philo)
		return (logger(MALLOC, ERR), NULL);
	while (i < sim->philo_nbr)
	{
		philo[i] = malloc(sizeof(t_philo));
		if (!philo[i])
			return (logger(MALLOC, ERR), NULL);
		ft_mtx(&philo[i]->mtx_meal, MTX_INIT);
		philo[i]->sim = sim;
		philo[i]->id = i;
		philo[i]->eat_count = 0;	
		i++;
	}
	return (philo);
}

void	init_data(t_sim *sim, char **av)
{
	sim->philo_nbr = ft_atol(av[1]);
	sim->time_to_die = ft_atol(av[2]);
	sim->time_to_eat = ft_atol(av[3]);
	sim->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		sim->times_must_eat = ft_atol(av[5]);
	else
		sim->times_must_eat = -1;
	sim->running = true;
}
