
#include "../include/so_long.h"

int main(int argc, char *argv[])
{
	unsigned int	len;
	t_map			*i_map;
	size_t			col;
	size_t			row;
	t_textures		*textures;

	if (!(argc == 2))
		return (1);
	len = ft_strlen(argv[1]);
	if (!(len >= 4))
		return (1);
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4))
		return (1);
	i_map = f_validmaps(argv[1]);

	if (!i_map)
		return (1);

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t *mlx = mlx_init(55 * i_map->collums, 55 * i_map->lines, "start", true);
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
			else if (i_map->map[row][col] == '0')
				mlx_image_to_window(mlx, textures->floor_img, col * 55, row * 55);
			col++;
		}
		row++;
	}
	mlx_loop(mlx);
	return (0);
}