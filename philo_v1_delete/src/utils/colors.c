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


/*dont do this and define macros for this stuff like a normal sane person
 * I didnt't know any better back then */
void	print_red(void)
{
	printf("\033[1;31m");
}

void	print_yellow(void)
{
	printf("\033[0;33m");
}

void	print_purp(void)
{
	printf("\033[0;35m");
}

void	print_cyan(void)
{
	printf("\033[0;36m");
}

void	print_green(void)
{
	printf("\033[0;32m");
}
