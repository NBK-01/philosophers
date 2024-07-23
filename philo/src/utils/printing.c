
#include "../../includes/main.h"

int	print_error(char *str)
{
	print_red();
	printf("------Error------\n%s\n\n", str);
	return (1);
}

int	print_warning(char *str)
{
	print_yellow();
	printf("-----Warning-----\n%s\n\n", str);
	return (1);
}

int	print_random(char *str)
{
	print_blue();
	printf("-----Message-----\n%s\n\n", str);
	return (1);
}

int	print_success(char *str)
{
	print_green();
	printf("-----------------\n%s\n\n", str);
	return (1);
}
