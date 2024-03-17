#include "../include/so_long.h"

void	f_exit_error(char *error)
{
	ft_printf("%s", error);
	exit(EXIT_FAILURE);
}
