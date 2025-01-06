#include "../../headers/main.h"
#include "../../headers/philo.h"
#include <time.h>

time_t	get_timestamp(void)
{
	t_time	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_sleep(t_sim *sim, time_t time)
{
	time_t	start;
	
	start = get_timestamp() + time;
	while (get_timestamp() < start)
	{
		if (end_sim(sim))
			break ;
		usleep(100);
	}
}

void	delay(time_t start_time)
{
	while (get_timestamp() < start_time)
		continue ;
}
