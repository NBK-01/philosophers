/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:00:38 by nkanaan           #+#    #+#             */
/*   Updated: 2025/01/07 10:00:39 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/main.h"
#include "../../headers/utils.h"

void	print_art(long nbr)
{
	printf(GREEN "         _      _  _        _  _  ___  \n");
	printf("        | |    (_)| |      | || ||__ \\ \n");
	printf("  _ __  | |__   _ | |  ___ | || |_  ) | \n");
	printf(" | '_ \\ | '_ \\ | || | / _ \\|__   _|/ /  \n");
	printf(" | |_) || | | || || || (_) |  | | / /_  \n");
	printf(" | .__/ |_| |_||_||_| \\___/   |_||____| \n");
	printf(" | |                                   \n");
	printf(" |_|                                   \n\n");
	printf(WHITE "Philosophers at the table: " RED "%ld\n" RESET, nbr);
}

void	logger(char *str, t_error status)
{
	if (status == ERR)
		printf(RED "------------ERROR----------------\n%s\n" RESET, str);
	else if (status == WARN)
		printf(YELLOW "------------WARNING--------------\n%s\n" RESET, str);
	else if (status == SUCCESS)
		printf(GREEN "------------SUCCESS--------------\n%s\n" RESET, str);
}

void	action_logger(char *str, t_philo *philo)
{
	long	timestamp;

	ft_mtx(&philo->sim->mtx_logger, MTX_LOCK);
	timestamp = get_timestamp() - philo->sim->sim_start;
	ft_mtx(&philo->sim->mtx_running, MTX_LOCK);
	if (philo->sim->running)
		printf("-- %ld philo [#%d] %s\n", timestamp, philo->id + 1, str);
	ft_mtx(&philo->sim->mtx_running, MTX_UNLOCK);
	ft_mtx(&philo->sim->mtx_logger, MTX_UNLOCK);
}

void	print_death(t_philo *philo)
{
	long	timestamp;

	ft_mtx(&philo->sim->mtx_logger, MTX_LOCK);
	timestamp = get_timestamp() - philo->sim->sim_start;
	printf(BLACK "      %s  ☠️----%ld philo [#%d] has died!----☠️  %s    \n\n",
		BG_RED, timestamp, philo->id + 1, RESET);
	ft_mtx(&philo->sim->mtx_logger, MTX_UNLOCK);
}
