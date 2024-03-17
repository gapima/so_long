#include "../include/so_long.h"

void	f_valid_difchar(t_data *data)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (x < data->map->collums)
		{
			if (ft_strrchr("10ECP", data->map->map[y][x]) == NULL)
			{
				f_free_map2(data);
				f_exit_error("Invalid Characteres.\n");
			}
			x++;
		}
		y++;
	}
}

void	f_valid_surround(t_data *data)
{
	size_t	y;

	y = 0;
	while (y < data->map->collums - 1)
	{
		if (data->map->map[0][y] != '1' \
			|| data->map->map[data->map->lines - 1][y] != '1')
		{
			f_free_map2(data);
			f_exit_error("Invalid not Surround.\n");
		}
		y++;
	}
	y = 0;
	while (y < data->map->lines - 1)
	{
		if (data->map->map[y][0] != '1' \
			|| data->map->map[y][data->map->collums - 1] != '1')
		{
			f_free_map2(data);
			f_exit_error("Invalid not Surround.\n");
		}
		y++;
	}
}

void	f_valid_rect_map(t_data *data)
{
	size_t	y;

	y = 0;
	while (data->map->map[y + 1])
	{
		if (y + 1 == data->map->lines - 1)
		{
			if (ft_strlen(data->map->map[y]) \
				!= ft_strlen(data->map->map[y + 1]) + 1)
			{
				f_free_map2(data);
				f_exit_error("Invalid not Rectangle.\n");
			}
		}
		else
		{
			if (ft_strlen(data->map->map[y]) \
				!= ft_strlen(data->map->map[y + 1]))
			{
				f_free_map2(data);
				f_exit_error("Invalid not Rectangle.\n");
			}
		}
		y++;
	}
}

void	f_valid_objects(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	f_init_objects(data);
	while (data->map->map[++y])
	{
		x = -1;
		while (data->map->map[y][++x])
		{
			if (data->map->map[y][x] == 'P')
				data->map->count_p++;
			else if (data->map->map[y][x] == 'E')
				data->map->count_e++;
			else if (data->map->map[y][x] == 'C')
				data->map->count_coin++;
		}
	}
	if (data->map->count_p != 1 || data->map->count_e != 1 \
		|| data->map->count_coin < 1)
	{
		f_free_map2(data);
		f_exit_error("Invalid Objects.\n");
	}
}

void	f_valid_map(t_data *data, char *file)
{
	t_data	copy;

	f_valid_difchar(data);
	f_valid_objects(data);
	f_valid_rect_map(data);
	f_valid_surround(data);
	copy.map = f_mallocmap(file);
	if (!copy.map)
	{
		f_free_map2(data);
		f_exit_error("Invalid malloc.\n");
	}
	f_get_position(&copy);
	copy.map->count_coin = 0;
	f_floodfill(&copy, copy.positions.y_player, copy.positions.x_player);
	if (copy.map->count_coin != data->map->count_coin \
		|| copy.map->path_check != 1)
	{
		f_free_map2(&copy);
		f_free_map2(data);
		f_exit_error("Invalid Path!\n");
	}
	f_free_map2(&copy);
}
