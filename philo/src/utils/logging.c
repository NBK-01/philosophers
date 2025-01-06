# include "../../headers/main.h"
# include "../../headers/utils.h"

void	print_art(long nbr)
{
	printf(GREEN "         _      _  _        _  _  ___  \n");
    printf("        | |    (_)| |      | || ||__ \\ \n");
    printf("  _ __  | |__   _ | |  ___ | || |_  ) | \n");
    printf(" | '_ \\ | '_ \\ | || | / _ \\|__   _|/ /  \n");
    printf(" | |_) || | | || || || (_) |  | | / /_  \n");
    printf(" | .__/ |_| |_||_||_| \\___/   |_||____| \n");
    printf(" | |                                   \n");
    printf(" |_|                                   \n\n");
	printf(WHITE "Philosophers at the table: " RED "%ld\n" RESET, nbr);
}

void	logger(char *str, t_error status)
{
	if (status == ERR)
		printf(RED "------------ERROR----------------\n%s\n" RESET, str);
	else if (status == WARN)
		printf(YELLOW "------------WARNING--------------\n%s\n" RESET, str);
	else if (status == SUCCESS)
		printf(GREEN "------------SUCCESS--------------\n%s\n" RESET, str);
}

void	action_logger(char *str, t_philo *philo)
{
	long	timestamp;

	ft_mtx(&philo->sim->mtx_logger, MTX_LOCK);
	timestamp = get_timestamp() - philo->sim->sim_start;
	printf("----%ld philo [#%d] %s\n", timestamp, philo->id + 1, str);
	ft_mtx(&philo->sim->mtx_logger, MTX_UNLOCK);
}

