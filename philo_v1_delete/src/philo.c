/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:46:33 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/24 16:46:35 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"


/*project entry point, clean and simple*/
int	main(int ac, char **av)
{
	print_art();
	if (!validate_args(av, ac - 1))
		exit(1);
	else
		init_philo(av, ac - 1);
}
