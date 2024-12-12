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
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"

/*-------------------------------ERRORS*/
#define ERROR			0
#define SUCCESS			1
#define WARNING			42

/*-------------------------------LIMITS*/
#define MAX_PHILO	200
#define MIN_TIME	60

/*-------------------------------ACTIONS*/
#define EATING		2
#define THINKING	3
#define SLEEPING	4
#define TAKE_FORK	5

/*-------------------------------ACTIONS*/
#define INIT	6
#define DESTROY	7
#define JOIN	8
#define LOCK	9
#define UNLOCK	10

/*---------------------------------------*/
/*********     REDEFINITIONS    **********/
/*---------------------------------------*/
typedef pthread_mutex_t	t_mutex;

/*---------------------------------------*/
/*********		 STRUCTS		 *********/
/*****************************************/
typedef struct s_philo {
}	t_philo;

typedef struct s_data {
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	uint32_t	nb_of_times_to_eat;
	uint32_t	times_ate;
	long		sim_start;
	bool		sim_end;
}	t_data;


#endif // !MAIN_H
