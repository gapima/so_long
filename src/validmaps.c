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
				ft_printf("Invalid Characteres.\n");
				exit (EXIT_FAILURE);
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
		if (data->map->map[0][y] != '1' || data->map->map[data->map->lines - 1][y] != '1')
		{
			ft_printf("Invalid not Surround.\n");
			exit (EXIT_FAILURE);
		}
		y++;
	}
	y = 0;
	while (y < data->map->lines - 1)
	{
		if (data->map->map[y][0] != '1' || data->map->map[y][data->map->collums - 1] != '1')
		{
			ft_printf("Invalid not Surround.\n");
			exit (EXIT_FAILURE);
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
			if (ft_strlen(data->map->map[y]) != ft_strlen(data->map->map[y + 1]) + 1)
			{
				ft_printf("Invalid not Rectangle.\n");
				exit (EXIT_FAILURE);
			}
		}
		else
		{
			if (ft_strlen(data->map->map[y]) != ft_strlen(data->map->map[y + 1]))
			{
				ft_printf("Invalid not Rectangle.\n");
				exit (EXIT_FAILURE);
			}
		}
		y++;
	}
}

void 	f_valid_objects(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	data->map->count_P = 0;
	data->map->count_E = 0;
	data->map->count_coin = 0;
	while (data->map->map[++y])
	{
		x = -1;
		while (data->map->map[y][++x])
		{
			if (data->map->map[y][x] == 'P')
				data->map->count_P++;
			else if(data->map->map[y][x] == 'E')
				data->map->count_E++;
			else if (data->map->map[y][x] == 'C')
				data->map->count_coin++;
		}
	}
	if (data->map->count_P != 1 || data->map->count_E != 1 || data->map->count_coin < 1)
	{
		ft_printf("Invalid Objects.\n");
		exit (EXIT_FAILURE);
	}
}

void	f_valid_map(t_data *data, t_map *copy)
{
	f_valid_difchar(data);
	f_valid_objects(data);
	f_valid_rect_map(data);
	f_valid_surround(data);
	copy->collums = data->map->collums;
	copy->lines = data->map->lines;
	f_floodfill(copy, data->positions.y_player, data->positions.x_player);
	if (copy->count_coin != data->map->count_coin || copy->path_check != 1)
	{
		f_free_map(&copy->map);
		f_free_map(&data->map->map);
		ft_printf("Error\nIt doesn't match the requirements!\n");
	}
}