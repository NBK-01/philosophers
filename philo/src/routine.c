#include "../includes/main.h"
#include "../includes/utils.h"
#include <pthread.h>

static void	*monitor(void *thread);

void	init_sim(int philos, t_routine	*routine)
{
	int			i;
	t_thread_id	monitor_thread;

	pthread_create(&monitor_thread, NULL, &monitor, routine->philos);
}

static void	*monitor(void *thread)
{
	t_philo	*philos;
	int		i;
	
	philos = (t_philo *)thread;
	while (1)
	{
		i = -1;
		while (++i < philos->nb_of_philos)
		{
			ft_mutex(philos->eating_mutex, LOCK);
			if (philos[i].data->last_ate + philos[i].data->time_to_die < get_timestamp())
			{
				print_msg("died", philos[i].id);
				ft_mutex(philos->logging_mutex, LOCK);
				philos->is_dead = 1;
				ft_mutex(philos->logging_mutex, UNLOCK);
				ft_mutex(philos->eating_mutex, UNLOCK);
				return (NULL);
			}
		}
	}
}
