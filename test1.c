#include "so_long.h"

int main(int argc, char *argv[])
{
	unsigned int	len;
	int				fd;
	t_map			i_map;
	char			*line;
	unsigned int	index;

	if (!argc == 2)
		return (1);
	len = ft_strlen(argv[1]);
	if (!len >= 4)
		return (1);
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4))
		return (1);
	len = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	while (get_next_line(fd))
		len++;
	close(fd);
	i_map.map = ft_calloc(sizeof(char *), len + 1);
	if (!i_map.map)
		return (1);
	fd = open(argv[1], O_RDONLY);
	index = 0;
	while (len)
	{
		line = get_next_line(fd);
		i_map.map[index] = ft_calloc(sizeof(char), ft_strlen(line) + 1);
		if (!i_map.map[index])
		{
			while (--index >= 0)
			{
				free(i_map.map[index]);
			}
			free(i_map.map);
			free(line);
			return (1);
		}
		ft_strlcpy(i_map.map[index++], line, ft_strlen(line) + 1);
		free(line);
		len--;
	}
	return (0);
}