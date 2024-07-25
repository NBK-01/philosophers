/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:47:19 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/24 16:47:23 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int	print_error(char *str)
{
	print_red();
	printf("------Error------\n%s\n\n", str);
	return (0);
}

int	print_warning(char *str)
{
	print_yellow();
	printf("-----Warning-----\n%s\n\n", str);
	return (0);
}

int	print_random(char *str)
{
	print_blue();
	printf("-----Message-----\n%s\n\n", str);
	return (0);
}

int	print_success(char *str)
{
	print_green();
	printf("-----------------\n%s\n", str);
	return (0);
}

