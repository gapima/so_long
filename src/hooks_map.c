
#include "../include/so_long.h"

void	f_control_player(mlx_key_data_t keyd, void *param)
{
	int		y;
	int		x;
	t_data	*data;

	data = (t_data *)param;
	data->positions.x_player = data->textures->player_img->instances->x \
		/ TILE_SIZE;
	data->positions.y_player = data->textures->player_img->instances->y \
		/ TILE_SIZE;
	x = data->positions.x_player;
	y = data->positions.y_player;
	if (keyd.key == MLX_KEY_W && keyd.action == MLX_PRESS \
		&& data->map->map[y - 1][x] != '1')
		f_action_up(data, y, x);
	if (keyd.key == MLX_KEY_A && keyd.action == MLX_PRESS \
		&& data->map->map[y][x - 1] != '1')
		f_action_left(data, y, x);
	if (keyd.key == MLX_KEY_S && keyd.action == MLX_PRESS \
		&& data->map->map[y + 1][x] != '1')
		f_action_down(data, y, x);
	if (keyd.key == MLX_KEY_D && keyd.action == MLX_PRESS \
		&& data->map->map[y][x + 1] != '1')
		f_action_right(data, y, x);
}

void	f_close_window(void *key)
{
	t_data	*data;

	data = (t_data *)key;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		f_free_end_game(data);
}
