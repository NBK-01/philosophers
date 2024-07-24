/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:46:15 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/24 16:46:18 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

/*/////////////////////////////////////////
//		STRUCTS			///
/////////////////////////////////////////*/
typedef struct s_vars
{
	long	nb_of_philos;
	long	time_to_eat;
	long	time_to_die;
	long	time_to_sleep;
	long	nb_of_times_to_eat;
	long	forks;
}	t_vars;

typedef struct s_philo
{
	pthread_mutex_t	philo;

}	t_philo;

/*/////////////////////////////////////////
//		UTILITY			///
/////////////////////////////////////////*/
void	init_philo(char **args, int ac);

/*/////////////////////////////////////////
//		UTILITY			///
/////////////////////////////////////////*/
long	ft_atoll(const char *str);
void	ft_putendl(char	*str);

/*/////////////////////////////////////////
//		VALIDATION		///
/////////////////////////////////////////*/
int	validate_args(char **arg, int ac);

/*/////////////////////////////////////////
//		FUN STUFF		///
/////////////////////////////////////////*/
void	print_red(void);
void	print_yellow(void);
void	print_blue(void);
void	print_green(void);
void	test_table(void);
void	print_final(void);

/*/////////////////////////////////////////
//		ERRORS - ETC.		///
/////////////////////////////////////////*/
int	print_error(char *str);
int	print_warning(char *str);
int	print_random(char *str);
int	print_success(char *str);

#endif
