
#include "../../headers/main.h"

int	ft_thread(t_id *thread, t_action action, void *(*func)(void *), void *arg)
{
	if (action == THRD_CREATE)
		return (pthread_create(thread, NULL, func, arg));
	else if (action == THRD_JOIN)
		return (pthread_join(*thread, NULL));
	else if (action == THRD_DETACH)
		return (pthread_detach(*thread));
	return (0);
}

int	ft_mtx(t_mtx *mutex, t_action action)
{
	if (action == MTX_INIT)
		return (pthread_mutex_init(mutex, NULL));
	else if (action == MTX_LOCK)
		return(pthread_mutex_lock(mutex));
	else if (action == MTX_UNLOCK)
		return(pthread_mutex_unlock(mutex));
	else if (action == MTX_DESTROY)
		return(pthread_mutex_destroy(mutex));
	return (0);
}

void	*ft_clean(t_sim *sim)
{
	int	i;

	i = 0;
	if (!sim)
		return (NULL);
	if (sim->forks)
		free(sim->forks);
	if (sim->philos)
	{
		i = 0;
		while (i < sim->philo_nbr)
		{
			if (sim->philos[i])
				free(sim->philos[i]);
			i++;
		}
		free(sim->philos);
	}
	free(sim);
	return (NULL);
}

void	clean_mtx(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->philo_nbr)
	{
		ft_mtx(&sim->forks[i], MTX_DESTROY);
		ft_mtx(&sim->philos[i]->mtx_meal, MTX_DESTROY);
		i++;
	}
	ft_mtx(&sim->mtx_logger, MTX_DESTROY);
	ft_mtx(&sim->mtx_running, MTX_DESTROY);
}

void	ft_exit(t_sim *sim, t_philo *philo, t_error error, int free)
{
	(void)philo;
	if (error == ARG_ERROR)
		printf("philo: exiting due to invalid args....\n");
	else if (error == THREAD_ERROR)
		printf("philo: exiting due to thread error....\n");
	else if (error == MTX_ERROR)
		printf("philo: exiting due to mutex error...\n");
	else if (error == ERR)
		printf("philo: exiting due to [error]...\n");
	if (free == 1)
		ft_clean(sim);
	else
		exit(EXIT_FAILURE);
}
