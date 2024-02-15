#include "../include/so_long.h"

void	f_delete_textures(t_data *data)
{
	mlx_delete_texture(data->textures->floor_texture);
	mlx_delete_texture(data->textures->wall_texture);
	mlx_delete_texture(data->textures->player_texture);
	mlx_delete_texture(data->textures->coin_texture);
	//mlx_delete_texture(data->textures->end_png);
}

void	f_delete_images(t_data *data)
{
	mlx_delete_image(data->mlx, data->textures->floor_img);
	mlx_delete_image(data->mlx, data->textures->wall_img);
	mlx_delete_image(data->mlx, data->textures->player_img);
	mlx_delete_image(data->mlx, data->textures->coin_img);
}

void	f_free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

int	f_free_end_game(t_data *data)
{
	delete_textures(data->textures);
	delete_images(data->mlx, data->textures);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	free_matrix(data->map->map);
	exit (EXIT_SUCCESS);
}