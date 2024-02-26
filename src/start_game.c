#include "../include/so_long.h"

void	f_put_player_items(t_data *data)
{
	size_t	x;
	size_t	y;
	
	data->map->count_coin = 0;
	y = 0;
	while (y < data->map->lines)
	{
		x = 0;
		while (x < data->map->collums)
		{
			if (data->map->map[y][x] == 'P')
				f_paint_player(data, x, y);
			else if (data->map->map[y][x] == 'C')
			{
				f_paint_coin(data, x, y);
				data->map->count_coin++;
			}
			x++;
		}
		y++;
	}
}

void	f_start_game(t_data *data)
{
	size_t			y;
	size_t			x;

	mlx_set_setting(MLX_MAXIMIZED, true);
	data->move = 0;
	data->mlx = mlx_init(SIZE_IMG * data->map->collums, SIZE_IMG * data->map->lines, "Plus Ultra", true);
	// if (!mlx)
	// 	return (false);
	data->textures = ft_calloc(sizeof(t_textures), 1);
	// if (!data->textures)
	// 	return (false);
	f_create_textures(data);
	y = 0;
	while (y < data->map->lines)
	{
		x = 0;
		while (x < data->map->collums)
		{
			if (data->map->map[y][x] == '1')
				f_paint_wall(data, x, y);
			else
				f_paint_floor(data, x, y);
			if (data->map->map[y][x] == 'E')
			{
				data->positions.y_fissure = y;
				data->positions.x_fissure = x;
			}	
			x++;
		}
		y++;
	}
	ft_printf("a\n");
	f_put_player_items(data);
	mlx_key_hook(data->mlx, &f_control_player, data);
	mlx_loop_hook(data->mlx, &f_close_window, data);
	mlx_loop(data->mlx);

}