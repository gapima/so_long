#include "../include/so_long.h"

void	f_put_player_items(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->map->lines)
	{
		x = 0;
		while (x < data->map->collums)
		{
			if (data->map->map[y][x] == 'P')
				f_paint_player(data, x, y);
			else if (data->map->map[y][x] == 'C')
				f_paint_coin(data, x, y);
			x++;
		}
		y++;
	}
}

static void	f_paint_map(t_data *data)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < data->map->lines)
	{
		x = 0;
		while (x < data->map->collums)
		{
			f_paint_floor(data, x, y);
			if (data->map->map[y][x] == '1')
				f_paint_wall(data, x, y);
			if (data->map->map[y][x] == 'E')
			{
				data->positions.y_shenlong = y;
				data->positions.x_shenlong = x;
			}
			x++;
		}
		y++;
	}
}

void	f_start_game(t_data *data)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	data->move = 0;
	data->mlx = mlx_init(SIZE_IMG * data->map->collums, \
		SIZE_IMG * data->map->lines, "Dragon Ball", true);
	data->textures = ft_calloc(sizeof(t_textures), 1);
	f_create_textures(data);
	f_paint_map(data);
	f_put_player_items(data);
	mlx_key_hook(data->mlx, &f_control_player, data);
	mlx_loop_hook(data->mlx, &f_close_window, data);
	mlx_loop(data->mlx);
}
