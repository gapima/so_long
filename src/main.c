#include "../include/so_long.h"

static void f_checkargs( int argc, char *argv[])
{
	unsigned int	len;

	if (!(argc == 2))
	{
		ft_printf("\nInvalid quantities files.\n");
		exit (EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if (!(len >= 4))
	{
		ft_printf("\nFile: %s Invalid extension.\n", argv);
		exit (EXIT_FAILURE);
	}
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4))
	{
		ft_printf("\nFile: %s Invalid extension.\n", argv);
		exit (EXIT_FAILURE);
	}	
}

int main(int argc, char *argv[])
{
	t_data			data;
	
	f_checkargs(argc, argv);
	data.map = f_mallocmap(argv[1]);
	if (!data.map)
		return (1);
	f_start_game(&data);
	return (0);
}