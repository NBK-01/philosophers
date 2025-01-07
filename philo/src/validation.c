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
	long	nbr;		

	i = 1;
	if (ac < 5 || ac > 6)
		return (logger(USAGE, ERR), false);
	while (i < ac)
	{
		if (!ft_isvalid(av[i]))
			return (logger(INVALID_ARG, ERR), false);
		nbr = ft_atol(av[i]);
		if (i == 1 && (nbr > 200 || nbr < 1))
			return (logger(COUNT, ERR), false);
		i++;
	}
	return (true);
}
