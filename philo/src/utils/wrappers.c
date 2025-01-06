
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

void	ft_clean(t_sim *sim, t_philo *philo)
{
	free(philo);
	free(sim);
}

void	ft_exit(t_sim *sim, t_philo *philo, t_error error, int free)
{
	if (error == ARG_ERROR)
		printf("philo: exiting due to invalid args....\n");
	else if (error == THREAD_ERROR)
		printf("philo: exiting due to thread error....\n");
	else if (error == MTX_ERROR)
		printf("philo: exiting due to mutex error...\n");
	else if (error == ERR)
		printf("philo: exiting due to [error]...\n");
	if (free == 1)
		ft_clean(sim, philo);
	else
		exit(EXIT_FAILURE);
}
