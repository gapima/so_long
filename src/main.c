
#include "../include/so_long.h"

int main(int argc, char *argv[])
{
	unsigned int	len;
	t_data			data;

	if (!(argc == 2))
		return (1);
	len = ft_strlen(argv[1]);
	if (!(len >= 4))
		return (1);
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4))
		return (1);
	data.map = f_mallocmap(argv[1]);
	if (!data.map)
		return (1);
	// for (size_t i = 0; i <  data.map->lines; i++)
	// 	ft_printf("%s", data.map->map[i]);
	f_start_game(&data);
	return (0);
}