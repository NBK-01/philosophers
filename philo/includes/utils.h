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
int		ft_mutex(void *mutex, t_action action);
void	*ft_malloc(void *ptr, size_t size, uint32_t count);
void	ft_destroy_mtx(t_routine *routine);
long	get_timestamp(void);
void	ft_sleep(long ms);
int		ft_thread(t_thread_id id, t_action action,
			t_routine *routine);
/*---------------------------------------*/
/*********      PRINTING		**********/
/*****************************************/
void	print_msg(char *msg, int type);
void	print_final(t_philo *philo);
void	print_art(); 

#endif // !UTILS_H
