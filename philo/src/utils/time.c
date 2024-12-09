
#include "../../includes/main.h"

long	to_ms(long nbr)
{
	return (nbr * 1e3);
}

int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep()
{
	printf("hello world");
}
