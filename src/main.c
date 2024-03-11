#include "../include/so_long.h"

static void f_checkargs( int argc, char *argv[])
{
	unsigned int	len;

	if (!(argc == 2))
	{
		ft_printf("Invalid quantities files.\n");
		exit (EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if (!(len >= 4) || ft_strncmp(&argv[1][len - 4], ".ber", 4))
	{
		ft_printf("File: %s Invalid extension.\n", argv[1]);
		exit (EXIT_FAILURE);
	}	
}

int main(int argc, char *argv[])
{
	t_data	data;
	
	f_checkargs(argc, argv);
	data.map = f_mallocmap(argv[1]);
	if (!data.map)
		return (1);
	f_valid_map(&data);
	f_start_game(&data);
	return (0);
}