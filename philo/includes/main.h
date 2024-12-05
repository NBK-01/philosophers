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
# include <stdbool.h>
# include <sys/time.h>

/*/////////////////////////////////////////
//				STRUCTS					///
/////////////////////////////////////////*/
typedef struct	s_fork
{
	int				id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_vars {
	long	nb_of_philos;
	long	time_to_eat;
	long	time_to_die;
	long	time_to_sleep;
	long	nb_of_times_to_eat;
}	t_vars;

typedef struct s_philo {
	int			id;
	float		last_ate;
	bool		is_dead;
	int			nb_of_times_ate;
	bool		full;
	t_fork		*fork_one;
	t_fork		*fork_two;
	pthread_t	tid;
	t_vars		*vars;
}	t_philo;

typedef struct s_routine {
	t_philo	*philos;
	t_fork	*forks;
	t_vars	*vars;
	long	sim_start;
	bool	sim_end;
}	t_routine;



/*/////////////////////////////////////////
//				INIT					///
/////////////////////////////////////////*/
void	init_philo(char **args, int ac);

/*/////////////////////////////////////////
//				PHILO					///
/////////////////////////////////////////*/

/*/////////////////////////////////////////
//				UTILITY					///
/////////////////////////////////////////*/
long	ft_atoll(const char *str);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
long	to_ms(long nbr);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_mutex(char *action, pthread_mutex_t *mutex);


/*/////////////////////////////////////////
//				VALIDATION				///
/////////////////////////////////////////*/
int		validate_args(char **arg, int ac);

/*/////////////////////////////////////////
//				FUN STUFF				///
/////////////////////////////////////////*/
void	print_red(void);
void	print_yellow(void);
void	print_purp(void);
void	print_cyan(void);
void	print_green(void);
void	test_table(void); // GET BACK TO THIS
void	print_final(void); // GET BACK TO THIS
void	header_table(char *philo);
void	print_art();

/*/////////////////////////////////////////
//				ERRORS - ETC.			///
/////////////////////////////////////////*/
int	print_error(char *str);
int	print_warning(char *str);
int	print_random(char *str);
int	print_success(char *str);

#endif
