#include "../includes/main.h"
#include "../includes/utils.h"
#include <stdio.h>

static int	valid_time(char **arg);
static int	valid_format(char **arg);
static int	valid_count(int ac);


/*all things validation. validating the args taken in from user*/
int	validate_args(char **arg, int ac)
{
	if (!(valid_count(ac)))
		return (ERROR);
	if (!(valid_format(arg)))
		return (print_msg("Use only positive integers please :)", ERROR), ERROR);
	if (!(valid_time(arg)))
		return (print_msg("Please use times over 60ms", ERROR), ERROR);
	return (1);
}

/*static	int	valid_limits(char **args)*/
/*{*/
/*	int	i;*/
/**/
/*	i = 1;*/
/*	while (args[i])*/
/*	{*/
/*		if (i == 1 && (ft_atoll(args[i]) < 1 || ft_atoll(args[i]) > MAX_PHILO))*/
/*			return (print_msg("Max number of philosophers is 200", ERROR), ERROR);*/
/*		i++;*/
/*	}*/
/*	return (SUCCESS);*/
/*}*/

static int	valid_time(char **arg)
{
	int	i;

	i = 2;
	while (++i <= 4)
	{
		if (ft_atoll(arg[i]) < 60)
			return (0);
	}
	return (1);
}

static int	valid_format(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (!(arg[i][j] >= '0' && arg[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	valid_count(int ac)
{
	if (ac < 4)
	{
		print_msg("Arguments expected: [nb of philos] [time to die] [time to eat] [time to sleep]", ERROR);
		return (print_msg("[number_of_times_each_philosopher_must_eat] is optional", MSG), ERROR);
	}
	else if (ac != 5)
		print_msg("Did not set no. if times to eat", WARNING);
	return (1);
}
