#include "../../includes/main.h"
#include "../../includes/utils.h"

void	*ft_mutex(void *mutex, int action)
{

	if (action == LOCK)
		pthread_mutex_lock(mutex);
	else if (action == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (action == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (action == DESTROY)
		pthread_mutex_destroy(mutex);
	return (NULL);

}

void	*ft_malloc(void *ptr, size_t size, uint32_t count)
{
	if (!ptr || !size || !count)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
	{
		print_msg("Failed allocation", ERROR);
		exit(ERROR);
	}
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;

	if (size != 0 && count > 2147483647 / size)
		return (0);
	temp = (void *)malloc(count * size);
	if (!temp)
		return (NULL);
	return (temp);
}

