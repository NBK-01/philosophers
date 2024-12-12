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
void	*ft_mutex(void *mutex, int action);
void	*ft_malloc(void *ptr, size_t size, uint32_t count);


/*---------------------------------------*/
/*********      PRINTING		**********/
/*****************************************/
void	print_msg(char *msg, int type);
void	print_final(t_philo *philo);
void	print_art(); 

#endif // !UTILS_H
