
#include "../include/so_long.h"

static void	f_next_action(t_data *data, int y, int x)
{
	data->map->map[data->positions.y_player][data->positions.x_player] = '0';
	f_render_move_player(data, y, x);
	ft_printf("Move: %d\n", ++data->move);
	if ((data->map->map[y][x] = 'C'))
	{
		data->map->count_coin--;
		data->map->map[y][x] = '0';
		f_paint_floor(data, (x * SIZE_IMG), (y * SIZE_IMG));
		f_paint_player(data, (x * SIZE_IMG), (y * SIZE_IMG));
	}
	data->map->map[y][x] = 'P';
}

void	f_action_left(t_data *data, int m_y, int m_x)
{
	int x;
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
	int x;
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
	int x;
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
	int x;
	int	y;

	x = m_x;
	y = m_y + 1;
	if (data->map->map[y][x] != '1')
	{
		f_next_action(data, y, x);
		m_y++;
	}
}