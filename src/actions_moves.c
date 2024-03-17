#include "../include/so_long.h"

static void	f_next_action(t_data *data, int y, int x)
{
	char	*str;

	data->map->map[data->positions.y_player][data->positions.x_player] = '0';
	f_render_move_player(data, y, x);
	ft_printf("Moves: %d\n", ++data->move);
	str = ft_itoa(data->move);
	mlx_image_to_window(data->mlx, data->textures->radar_img, 0, 0);
	mlx_put_string(data->mlx, str, 20, 20);
	free(str);
	if ((data->map->map[y][x] == 'C'))
	{
		data->map->count_coin--;
		data->map->map[y][x] = '0';
		f_paint_floor(data, x, y);
		f_paint_player(data, x, y);
	}
	if (data->map->count_coin == 0)
		f_paint_shenlong(data, data->positions.x_shenlong, \
			data->positions.y_shenlong);
	if (data->positions.y_shenlong == y \
		&& data->positions.x_shenlong == x && data->map->count_coin == 0)
	{
		ft_printf("Finsh Game!!!\n");
		f_free_end_game(data);
	}
	data->map->map[y][x] = 'P';
}

void	f_action_left(t_data *data, int m_y, int m_x)
{
	int	x;
	int	y;

	x = m_x - 1;
	y = m_y;
	data->textures->last_move_player = 1;
	if (data->map->map[y][x] != '1')
	{
		f_next_action(data, y, x);
		m_x--;
	}
}

void	f_action_right(t_data *data, int m_y, int m_x)
{
	int	x;
	int	y;

	x = m_x + 1;
	y = m_y;
	data->textures->last_move_player = 0;
	if (data->map->map[y][x] != '1')
	{
		f_next_action(data, y, x);
		m_x++;
	}
}

void	f_action_up(t_data *data, int m_y, int m_x)
{
	int	x;
	int	y;

	x = m_x;
	y = m_y - 1;
	if (data->map->map[y][x] != '1')
	{
		f_next_action(data, y, x);
		m_y--;
	}
}

void	f_action_down(t_data *data, int m_y, int m_x)
{
	int	x;
	int	y;

	x = m_x;
	y = m_y + 1;
	if (data->map->map[y][x] != '1')
	{
		f_next_action(data, y, x);
		m_y++;
	}
}
