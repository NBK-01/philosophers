#include "../../includes/main.h"
#include <stdbool.h>
#include <stdint.h>
#include "../../includes/utils.h"

bool	philos_full(t_philo	*philos)
{
	uint16_t	ate;
	int			i;

	i = -1;
	ate = 0;
	if (philos[0].data->times_to_eat < 0)
		return (false);
	while (++i < philos->nb_of_philos)
	{
		ft_mutex(philos->eating_mutex, LOCK);
		if (philos[i].times_ate >= philos[i].data->times_to_eat)
			ate++;
		ft_mutex(philos->eating_mutex, UNLOCK);
	}
	if (ate == philos->nb_of_philos)
		return (ft_mutex(philos->eating_mutex, LOCK), true);
	return (false);
}

void	exec_action(t_philo *philo, t_action action)
{
	if (action == EAT)
	{
		ft_mutex(philo->left_fork, LOCK);
		ft_mutex(philo->logging_mutex, LOCK);
		log_wrapper(philo, FORK);
		ft_mutex(philo->logging_mutex, UNLOCK);
		ft_mutex(philo->right_fork, LOCK);
		ft_mutex(philo->logging_mutex, LOCK);
		log_wrapper(philo, FORK);
		ft_mutex(philo->logging_mutex, UNLOCK);
		ft_mutex(philo->eating_mutex, LOCK);
		ft_mutex(philo->logging_mutex, LOCK);
		log_wrapper(philo, action);
		ft_mutex(philo->logging_mutex, UNLOCK);
	}
	if (action == SLEEP)
	{
		log_wrapper(philo, action);
		ft_sleep(philo->data->time_to_sleep);
	}
	if (action == THINK)
		log_wrapper(philo, action);
}
