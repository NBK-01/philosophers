

#ifndef MAIN_H
# define MAIN_H
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>


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

/*/////////////////////////////////////////
//		ERRORS - ETC.		///
/////////////////////////////////////////*/
int	print_error(char *str);
int	print_warning(char *str);
int	print_random(char *str);
int	print_success(char *str);

#endif
