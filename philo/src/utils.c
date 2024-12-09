/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 08:48:11 by nkanaan           #+#    #+#             */
/*   Updated: 2024/12/06 08:48:12 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/main.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (1);
	return (0);
}

/*mutex helper func, takes in args depending on action needed*/
void	*ft_mutex(char *action, pthread_mutex_t *mutex)
{
	if (ft_strcmp(action, "lock") == 0)
		pthread_mutex_lock(mutex);
	else if (ft_strcmp(action, "unlock") == 0)
		pthread_mutex_unlock(mutex);
	else if (ft_strcmp(action, "init") == 0)
		pthread_mutex_init(mutex, NULL);
	else if (ft_strcmp(action, "destroy") == 0)
		pthread_mutex_destroy(mutex);
	return (NULL);
}
