#include "so_long.h"

static void	f_map(t_map *map, unsigned int len, char *file)
{
	map->lines = len;
	map->map = ft_calloc(sizeof(char *), len + 1);
	if (!map->map)
	{
		free(map);
		f_exit_error("Invalid malloc.\n");
	}
	if (f_getmap(map, file, 0, len) == 1)
	{
		free(map->map);
		free(map);
		f_exit_error("Invalid get map.\n");
	}
}

t_map	*f_mallocmap(char *file)
{
	int				fd;
	t_map			*map;
	unsigned int	len;
	char			*str;

	len = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = get_next_line(fd);
	if (!str)
		f_exit_error("Invalid map.\n");
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		if (str)
			len++;
	}
	close(fd);
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
	f_map(map, len, file);
	return (map);
}

int	f_getmap(t_map *map, char *file, int index, unsigned int len)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	while (len)
	{
		line = get_next_line(fd);
		map->collums = ft_strlen(line);
		map->map[index] = ft_calloc(sizeof(char), ft_strlen(line) + 1);
		if (!map->map[index])
		{
			while (--index >= 0)
				free(map->map[index]);
			free(map->map);
			free(line);
			free(map);
			close(fd);
			return (1);
		}
		ft_strlcpy(map->map[index++], line, ft_strlen(line) + 1);
		free(line);
		len--;
	}
	close(fd);
	return (0);
}

void	f_create_textures(t_data *data)
{
	data->textures->wall_texture = mlx_load_png(WALL);
	data->textures->floor_texture = mlx_load_png(FLOOR);
	data->textures->player_texture = mlx_load_png(PLAYER);
	data->textures->coin_texture = mlx_load_png(COIN);
	data->textures->shenlong_texture = mlx_load_png(SHENLONG);
	data->textures->wall_img = mlx_texture_to_image(data->mlx, \
		data->textures->wall_texture);
	data->textures->floor_img = mlx_texture_to_image(data->mlx, \
		data->textures->floor_texture);
	data->textures->player_img = mlx_texture_to_image(data->mlx, \
		data->textures->player_texture);
	data->textures->coin_img = mlx_texture_to_image(data->mlx, \
		data->textures->coin_texture);
	data->textures->shenlong_img = mlx_texture_to_image(data->mlx, \
		data->textures->shenlong_texture);
}
