#include "../includes/main.h"
#include "../includes/utils.h"
#include "../includes/philo.h"

void	init_data(t_philo *philo, char **av, int ac)
{
	int	i;

	i = -1;
	while (++i < ft_atoll(av[1]))
	{
		philo[i].id = i + 1;
		philo[i].data = malloc(sizeof(t_data));
		philo[i].data->time_to_die = ft_atoll(av[2]);
		philo[i].data->time_to_eat = ft_atoll(av[3]);
		philo[i].data->time_to_sleep = ft_atoll(av[4]);
		philo[i].data->last_ate = get_timestamp();
		philo[i].data->sim_start = get_timestamp();
		philo[i].times_ate = 0;
		philo[i].nb_of_philos = ft_atoll(av[1]);
		philo[i].data->times_to_eat = -42;
		if (ac == 5)
			philo[i].data->times_to_eat = ft_atoll(av[5]);
	}
}

void	init_routine(t_philo *philo, t_mutex *forks, t_routine *routine)
{
	int	i;

	i = -1;
	while (++i < philo[0].nb_of_philos)
	{
		philo[i].left_fork = &forks[i];
		if (i == 0)
			philo[i].right_fork = &forks[philo[i].nb_of_philos - 1];
		else
			philo[i].right_fork = &forks[i - 1];
		philo[i].logging_mutex = &routine->logging_mutex;
		philo[i].eating_mutex = &routine->eating_mutex;
	}
}
