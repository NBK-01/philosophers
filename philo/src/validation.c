/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:00:52 by nkanaan           #+#    #+#             */
/*   Updated: 2025/01/07 10:00:53 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"
#include "../headers/utils.h"

bool	validate_args(int ac, char *av[])
{
	int		i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (logger(USAGE, ERR), false);
	while (i < ac)
	{
		if (!ft_isvalid(av[i]))
			return (logger(INVALID_ARG, ERR), false);
		if (ft_atol(av[1]) > 200 || ft_atol(av[1]) < 1)
			return (logger(COUNT, ERR), false);
		i++;
	}
	return (true);
}
