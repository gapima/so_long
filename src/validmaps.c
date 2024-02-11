
#include "so_long.h"

t_map   *f_mallocmap(char *file)
{
    int				fd;
    t_map			*i_map;
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
	if (f_getmap(i_map, fd, 0, len) == 1)
		return (NULL);
	return (i_map);
}

int	f_getmap(t_map *i_map, int fd, int index, unsigned int len)
{
	char	*line;

	while (len)
	{
		line = get_next_line(fd);
		i_map->collums = ft_strlen(line);
		i_map->map[index] = ft_calloc(sizeof(char), ft_strlen(line) + 1);
		if (!i_map->map[index])
		{
			while (--index >= 0)
				free(i_map->map[index]);
			free(i_map->map);
			free(line);
			return (1);
		}
		ft_strlcpy(i_map->map[index++], line, ft_strlen(line) + 1);
		free(line);
		len--;
	}
	return (0);
}

void	f_create_textures(t_textures *textures, mlx_t *mlx)
{
	textures->wall_texture = mlx_load_png(WALL);
	textures->floor_texture = mlx_load_png(FLOOR);
	textures->player_texture = mlx_load_png(PLAYER);
	textures->coin_texture = mlx_load_png(COIN);
	textures->wall_img = mlx_texture_to_image(mlx, textures->wall_texture);
	textures->floor_img = mlx_texture_to_image(mlx, textures->floor_texture);
	textures->player_img = mlx_texture_to_image(mlx, textures->player_texture);
	textures->coin_img = mlx_texture_to_image(mlx, textures->coin_texture);
}

int	f_play(t_map *i_map)
{
	size_t			col;
	size_t			row;
	t_textures		*textures;
	mlx_t			*mlx;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(55 * i_map->collums, 55 * i_map->lines, "start", true);
	if (!mlx)
		return 1;
	textures = ft_calloc(sizeof(t_textures), 1);
	if (!textures)
		return (1);
	f_create_textures(textures, mlx);
	row = 0;
	while (row < i_map->lines)
	{
		col = 0;
		while (col < i_map->collums)
		{
			if (i_map->map[row][col] == '1')
				mlx_image_to_window(mlx, textures->wall_img, col * 55, row * 55);
			else
				mlx_image_to_window(mlx, textures->floor_img, col * 55, row * 55);
			col++;
		}
		row++;
	}
	f_put_player_items(mlx, textures, i_map);
	mlx_loop(mlx);
	return (0);
}

void	f_put_player_items(mlx_t *mlx, t_textures *textures, t_map *i_map)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < i_map->lines)
	{
		col = 0;
		while (col < i_map->collums)
		{
			if (i_map->map[row][col] == 'P')
				mlx_image_to_window(mlx, textures->player_img, col * 55, row * 55);
			else if (i_map->map[row][col] == 'C')
				mlx_image_to_window(mlx, textures->coin_img, col * 55, row * 55);
			col++;
		}
		row++;
	}
}