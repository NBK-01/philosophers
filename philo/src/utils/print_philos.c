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

void	test_table(void)
{
	int column_width = 18;

	print_blue();
	printf("\n");
	printf("%-*s | %-*s | %-*s\n", column_width, "Elapsed", column_width, "Philo 1", column_width, "Philo 2");
	printf("%-*c | %-*c | %-*c\n", column_width, '-', column_width, '-', column_width, '-');
	printf("%-*d | %-*s | %.*s\n", column_width, 10, column_width, "is eating", column_width, "is sleeping");
	printf("%-*d | %-*s | %.*s\n", column_width, 110, column_width, "is sleeping", column_width, "is thinking");
	printf("%-*d | %-*s | %.*s\n", column_width, 210, column_width, "is thinking", column_width, "died");
	printf("\n");
}

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
