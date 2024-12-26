/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:53:34 by nkanaan           #+#    #+#             */
/*   Updated: 2024/12/26 11:53:34 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "main.h"

/*---------------------------------------*/
/*********        LIB			**********/
/*****************************************/
long	ft_atoll(const char *str);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

/*---------------------------------------*/
/*********	WRAPPERS & HELPERS	 *********/
/*****************************************/
int		ft_mutex(t_mutex *mutex, t_action action);
void	*ft_malloc(void *ptr, size_t size, uint32_t count);
void	ft_destroy_mtx(t_routine *routine);
long	get_timestamp(void);
void	ft_sleep(long ms);
int		ft_thread(t_thread_id id, t_action action, \
			t_routine *routine);
/*---------------------------------------*/
/*********      PRINTING		**********/
/*****************************************/
void	print_msg(char *msg, int type);
void	print_action(t_mutex *mutex, int time, \
		uint8_t id, t_action action);
void	print_final(t_routine *routine);
void	print_art(void);
void	log_wrapper(t_philo *philo, t_action action);

#endif // !UTILS_H
