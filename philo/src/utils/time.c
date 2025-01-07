/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:00:42 by nkanaan           #+#    #+#             */
/*   Updated: 2025/01/07 10:00:42 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
