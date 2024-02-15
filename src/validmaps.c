
#include "so_long.h"

t_map   *f_mallocmap(char *file)
{
    int				fd;
    t_data			*data;
	unsigned int 	len;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (get_next_line(fd))
		len++;
	close(fd);
	data->map = ft_calloc(sizeof(t_map), 1);
	if (!data->map)
		return (NULL);
	data->map->lines = len;
	data->map->map = ft_calloc(sizeof(char *), len + 1);
	if (!data->map->map)
	{
		free(data->map);
		return (NULL);
	}
	fd = open(file, O_RDONLY);
	if (f_getmap(data->map, fd, 0, len) == 1)
		return (NULL);
	return (data->map);
}

int	f_getmap(t_data *data, int fd, int index, unsigned int len)
{
	char	*line;

	while (len)
	{
		line = get_next_line(fd);
		data->map->collums = ft_strlen(line);
		data->map->map[index] = ft_calloc(sizeof(char), ft_strlen(line) + 1);
		if (!data->map->map[index])
		{
			while (--index >= 0)
				free(data->map->map[index]);
			free(data->map->map);
			free(line);
			return (1);
		}
		ft_strlcpy(data->map->map[index++], line, ft_strlen(line) + 1);
		free(line);
		len--;
	}
	return (0);
}

void	f_create_textures(t_data *data)
{
	data->textures->wall_texture = mlx_load_png(WALL);
	data->textures->floor_texture = mlx_load_png(FLOOR);
	data->textures->player_texture = mlx_load_png(PLAYER_D);
	data->textures->coin_texture = mlx_load_png(COIN);
	data->textures->wall_img = mlx_texture_to_image(data->mlx, data->textures->wall_texture);
	data->textures->floor_img = mlx_texture_to_image(data->mlx, data->textures->floor_texture);
	data->textures->player_img = mlx_texture_to_image(data->mlx, data->textures->player_texture);
	data->textures->coin_img = mlx_texture_to_image(data->mlx, data->textures->coin_texture);
}