/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:47:11 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/24 16:47:12 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

/*misc stuff mostly unused*/
void	header_table(char *philo)
{
	int	column_width = 10;

	print_purp();
	printf("%-*s", column_width, philo);
}

/*don't know what this was*/
void	test_table(void)
{
	int column_width = 18;

	print_cyan();
	printf("%-*d | %-*s | %.*s\n", column_width, 10, column_width, "is eating", column_width, "is sleeping");
}


/*will probably not use, was a cool idea at the time*/
void	print_final(void)
{
	print_success("All done, here's an overview");

	int column_width = 18;

	print_green();
	printf("\n");
	printf("%-*s | %-*s | %-*s\n", column_width, "Philo 1", column_width, "Philo 2", column_width, "Philo 3");
	printf("%-*c | %-*c | %-*c\n", column_width, '-', column_width, '-', column_width, '-');
	printf("%-*s | %-*s | %.*s\n", column_width, "Ate 3 times", column_width, "Ate 3 times", column_width, "Died");
	printf("\n");
}
