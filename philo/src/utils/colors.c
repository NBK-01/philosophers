/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:46:57 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/24 16:46:59 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/main.h"

void	print_red(void)
{
	printf("\033[1;31m");
}

void	print_yellow(void)
{
	printf("\033[0;33m");
}

void	print_blue(void)
{
	printf("\033[0;36m");
}

void	print_green(void)
{
	printf("\033[0;32m");
}
