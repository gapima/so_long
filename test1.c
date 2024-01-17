#include "so_long.h"

int main(int argc, char *argv[])
{
	unsigned int	len;
	int				fd;
	t_map			i_map;

	if (!argc == 2)
		return (1);
	len = ft_strlen(argv[1]);
	if (!len >= 4)
		return (1);
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4))
		return (1);
	len = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd))
		len++;
	close(fd);
	i_map.map = ft_calloc(sizeof(char *), len + 1);
	if (!i_map.map)
		return (1);

	//fazer while para salvar as strings, igual a logica da split.

	return (0);
}