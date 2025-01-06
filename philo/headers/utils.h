#ifndef UTILS_H
# define UTILS_H

# include "main.h"

void	ft_mtx(t_mtx *mutex, t_action action);
void	print_art(long nbr);
long	ft_atol(const char *str);
bool	ft_isvalid(char *str);
void	ft_exit(t_sim *sim, t_philo *philo, t_error error, int free);
void	logger(char *str, int status);

#endif // !UTILS_H
