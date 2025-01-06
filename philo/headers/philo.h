#ifndef PHILO_H
# define PHILO_H

# include "main.h"

bool	validate_args(int ac, char *av[]);

void	init_data(t_sim *sim, char **av);
t_philo	**init_philos(t_sim *sim);
bool	init_mtx(t_sim *sim);

#endif // !PHILO_H
