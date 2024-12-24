#ifndef PHILO_H
# define PHILO_H

# include "main.h"

/*---------------------------------------*/
/*********       VALIDATION		**********/
/*****************************************/
int		validate_args(char **arg, int ac);

/*---------------------------------------*/
/*********        INIT			**********/
/*****************************************/
void	init_data(t_philo *philo, char **av, int ac);
void	init_routine(t_philo *philo, t_mutex *forks, t_routine *routine);

/*---------------------------------------*/
/*********        ROUTINE		**********/
/*****************************************/
void	init_sim(int philos, t_routine *routine);
bool	philos_full(t_philo	*philos);
void	exec_action(t_philo *philo, t_action action);

/*---------------------------------------*/
/*********        TBD			**********/
/*****************************************/

#endif
