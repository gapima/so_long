
#include "so_long.h"

t_map   *f_validmaps(char *file)
{
    int	fd;
    t_map			*i_map;
	int	index;
	char			*line;
	unsigned int 	len;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (get_next_line(fd))
		len++;
	close(fd);
	i_map = ft_calloc(sizeof(t_map), 1);
	if (!i_map)
		return (NULL);
	i_map->lines = len;
	i_map->map = ft_calloc(sizeof(char *), len + 1);
	if (!i_map->map)
	{
		free(i_map);
		return (NULL);
	}
	fd = open(file, O_RDONLY);
	index = 0;
	while (len)
	{
		line = get_next_line(fd);
		i_map->collums = ft_strlen(line);
		i_map->map[index] = ft_calloc(sizeof(char), ft_strlen(line) + 1);
		if (!i_map->map[index])
		{
			while (--index >= 0)
			{
				free(i_map->map[index]);
			}
			free(i_map->map);
			free(line);
			return (NULL);
		}
		ft_strlcpy(i_map->map[index++], line, ft_strlen(line) + 1);
		free(line);
		len--;
	}
	return (i_map);
}

void	f_create_textures(t_textures *textures, mlx_t *mlx)
{
	textures->wall_texture = mlx_load_png(WALL);
	textures->floor_texture = mlx_load_png(FLOOR);
	textures->wall_img = mlx_texture_to_image(mlx, textures->wall_texture);
	textures->floor_img = mlx_texture_to_image(mlx, textures->floor_texture);

}