#include "../../headers/main.h"

static bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

bool	ft_isvalid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

long	ft_atol(const char *str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' 
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return (nbr * sign);
}


