
#include "../include/so_long.h"

void	f_paint_player(t_data *data, int x, int y)
{
	mlx_image_to_window(data->mlx, data->textures->player_img, x * SIZE_IMG, y * SIZE_IMG);
}

void	f_render_move_player(t_data *data, int y, int x)
{
	if (data->textures->last_move_player == 0)
	{
		mlx_delete_image(data->mlx, data->textures->player_img);
		mlx_delete_texture(data->textures->player_texture);
		data->textures->player_texture = mlx_load_png(PLAYER_R);
		data->textures->player_img = mlx_texture_to_image(data->mlx, \
			data->textures->player_texture);
		mlx_resize_image(data->textures->player_img, SIZE_IMG, SIZE_IMG);
		mlx_image_to_window(data->mlx, data->textures->player_img, \
			(SIZE_IMG * x), (SIZE_IMG * y));
	}
	else if (data->textures->last_move_player == 1)
	{
		mlx_delete_image(data->mlx, data->textures->player_img);
		mlx_delete_texture(data->textures->player_texture);
		data->textures->player_texture = mlx_load_png(PLAYER_L);
		data->textures->player_img = mlx_texture_to_image(data->mlx, \
			data->textures->player_texture);
		mlx_resize_image(data->textures->player_img, SIZE_IMG, SIZE_IMG);
		mlx_image_to_window(data->mlx, data->textures->player_img, \
			(SIZE_IMG * x), (SIZE_IMG * y));
	}
}
