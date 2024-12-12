/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:46:41 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/24 16:46:42 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
#include <stdint.h>
#include <stdio.h>

void	*routine(void *routine)
{
	t_routine	*data;

	data = (t_routine *)routine;
	printf("Hello world");

	return (NULL);
}
