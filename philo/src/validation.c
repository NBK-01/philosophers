/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:46:48 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/24 16:46:49 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static int	valid_time(char **arg);
static int	valid_format(char **arg);
static int	valid_count(int ac);

int	validate_args(char **arg, int ac)
{
	if (!(valid_count(ac)))
		return (1);
	if (!(valid_format(arg)))
		return (print_error("Use only digits please :)"));
	if (!(valid_time(arg)))
		return (print_error("Please use times under 60ms"));
	return (0);
}

static int	valid_time(char **arg)
{
	int	i;

	i = 2;
	while (arg[i])
	{
		if (ft_atoll(arg[i]) < 59)
			return (0);
		i++;
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
		print_error("Args should be [nb of philos] [time to die] [time to eat] [time to sleep]");
		return (print_random("[number_of_times_each_philosopher_must_eat] is optional"));
	}
	else if (ac != 5)
	{
		print_warning("Did set no. of times to eat");
		sleep(1);
	}
	else
		return (0);
}

