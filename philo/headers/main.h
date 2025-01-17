/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:36:05 by nkanaan           #+#    #+#             */
/*   Updated: 2025/01/09 09:36:06 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>

/////////////////////////////////////////
//////////		DEFS		////////////
# define RESET       "\033[0m"
# define BLACK       "\033[0;30m"
# define RED         "\033[1;31m"
# define GREEN       "\033[0;32m"
# define YELLOW      "\033[0;33m"
# define MAGENTA     "\033[0;35m"
# define CYAN        "\033[0;36m"
# define WHITE       "\033[0;37m"
# define BG_RED     "\033[41m"
# define BG_GREEN   "\033[42m"
# define BG_YELLOW  "\033[43m"
# define BG_WHITE   "\033[47m"

# define USAGE "Usage: ./philo number_of_philosophers time_to_die\
	time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"
# define COUNT "Restrict: use of range [1-200] philos\n"
# define INVALID_ARG "Args must be positive integers\n"
# define MALLOC "Malloc failed\n"
# define FORK "\033[0;36m 🍴has taken a fork🍴\n\033[0m"
# define EAT  "\033[0;32m 🍝is eating🍝\n\033[0m"
# define SLEEP "\033[0;33m 💤is sleeping💤\n\033[0m"
# define THINK "\033[0;33m 🤔is thinking🤔\n\033[0m"
/////////////////////////////////////////
//////////		REDEF		////////////
typedef pthread_mutex_t			t_mtx;
typedef pthread_t				t_id;
typedef struct timeval			t_time;
/////////////////////////////////////////
//////////		ENUMS		////////////
typedef enum e_error
{
	ARG_ERROR = -1,
	THREAD_ERROR = -2,
	MTX_ERROR = -3,
	WARN = 42,
	SUCCESS = 0,
	ERR = 1,
}	t_error;

typedef enum e_action
{
	MTX_LOCK,
	MTX_UNLOCK,
	MTX_DESTROY,
	MTX_INIT,
	THRD_CREATE,
	THRD_JOIN,
	THRD_DETACH,
}	t_action;

/////////////////////////////////////////
//////////		STRUCTS		////////////
typedef struct s_philo
{
	t_id			tid;
	uint32_t		id;
	int32_t			eat_count;
	time_t			last_ate;
	int				left_fork;
	int				right_fork;
	t_mtx			mtx_meal;
	struct s_sim	*sim;
}	t_philo;

typedef struct s_sim
{
	t_id				monitor;
	long				philo_nbr;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	int32_t				times_must_eat;
	time_t				sim_start;
	bool				running;
	t_mtx				mtx_logger;
	t_mtx				mtx_running;
	t_mtx				*forks;
	t_philo				**philos;
}	t_sim;

#endif // !MAIN_H
