#include "../include/so_long.h"

void	f_delete_textures(t_data *data)
{
	mlx_delete_texture(data->textures->floor_texture);
	mlx_delete_texture(data->textures->wall_texture);
	mlx_delete_texture(data->textures->player_texture);
	mlx_delete_texture(data->textures->coin_texture);
	mlx_delete_texture(data->textures->shenlong_texture);
	mlx_delete_texture(data->textures->radar_texture);
}

void	f_delete_images(t_data *data)
{
	mlx_delete_image(data->mlx, data->textures->floor_img);
	mlx_delete_image(data->mlx, data->textures->wall_img);
	mlx_delete_image(data->mlx, data->textures->player_img);
	mlx_delete_image(data->mlx, data->textures->coin_img);
	mlx_delete_image(data->mlx, data->textures->shenlong_img);
	mlx_delete_image(data->mlx, data->textures->radar_img);
}

void	f_free_map2(t_data *data)
{
	if (data->map)
	{
		if (data->map->map)
			f_free_map(data->map->map);
		free(data->map);
	}
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
	f_delete_textures(data);
	f_delete_images(data);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	f_free_map2(data);
	exit (EXIT_SUCCESS);
}
