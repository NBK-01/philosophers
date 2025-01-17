/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:36:25 by nkanaan           #+#    #+#             */
/*   Updated: 2025/01/09 09:36:33 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "main.h"

void	ft_mtx(t_mtx *mutex, t_action action);
void	print_art(long nbr);
int		ft_atol(char *str);
bool	ft_isvalid(char *str);
void	ft_exit(t_sim *sim, t_philo *philo, t_error error, int free);
void	logger(char *str, t_error status);
long	get_timestamp(void);
int		ft_thread(t_id *thread, t_action action,
			void *(*func)(void *), void *arg);
void	ft_clean(t_sim *sim);
void	delay(long start_time);
void	action_logger(char *str, t_philo *philo);
void	ft_sleep(t_sim *sim, long time);
void	clean_mtx(t_sim *sim);
void	print_death(t_philo *philo);

#endif // !UTILS_H
