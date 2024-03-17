
#include "../include/so_long.h"

void	f_paint_wall(t_data *data, int x, int y)
{
	mlx_image_to_window(data->mlx, \
		data->textures->wall_img, x * SIZE_IMG, y * SIZE_IMG);
}

void	f_paint_floor(t_data *data, int x, int y)
{
	mlx_image_to_window(data->mlx, \
		data->textures->floor_img, x * SIZE_IMG, y * SIZE_IMG);
}

void	f_paint_coin(t_data *data, int x, int y)
{
	mlx_image_to_window(data->mlx, \
		data->textures->coin_img, x * SIZE_IMG, y * SIZE_IMG);
}

void	f_paint_shenlong(t_data *data, int x, int y)
{
	mlx_image_to_window(data->mlx, \
		data->textures->shenlong_img, x * SIZE_IMG, y * SIZE_IMG);
}

void	f_paint_radar(t_data *data)
{
	char	*str;

	ft_printf("Moves: %d\n", ++data->move);
	str = ft_itoa(data->move);
	mlx_image_to_window(data->mlx, data->textures->radar_img, 0, 0);
	mlx_put_string(data->mlx, str, 20, 20);
	free(str);
}
