#ifndef MAIN_H
# define MAIN_H

# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/*---------------------------------------*/
/***********   DEFINITIONS    ************/
/*---------------------------------------*/

/*-------------------------------COLORS*/
#define RESET	"\033[0m"
#define RED		"\033[1;31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[0;33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[0;36m"

/*-------------------------------ERRORS*/
#define ERROR			0
#define SUCCESS			1
#define WARNING			42
#define MSG				-42

/*-------------------------------LIMITS*/
#define MAX_PHILO	200
#define MIN_TIME	60

/*-------------------------------ACTIONS*/
typedef enum e_action {
	EAT,
	SLEEP,
	THINK,
	FORK,
	DIE,
	INIT,
	DESTROY,
	JOIN,
	LOCK,
	UNLOCK,
	CREATE,
	DETACH,
}	t_action;

/*---------------------------------------*/
/*********     REDEFINITIONS    **********/
/*---------------------------------------*/
typedef pthread_t		t_thread_id;
typedef pthread_mutex_t	t_mutex;

/*---------------------------------------*/
/*********		 STRUCTS		 *********/
/*****************************************/
typedef struct s_data {
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		last_ate;
	int			times_to_eat;
	long		sim_start;
}	t_data;

typedef struct s_philo {
	uint8_t		id;
	t_thread_id	thread_id;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_mutex		*logging_mutex;
	t_mutex		*eating_mutex;
	uint32_t	times_ate;
	int			nb_of_philos;
	t_data		*data;
}	t_philo;

typedef struct s_routine {
	t_philo		*philos;
	t_mutex		*forks;
	t_mutex		logging_mutex;
	t_mutex		eating_mutex;
}	t_routine;

#endif // !MAIN_H
