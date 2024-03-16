#include "../include/so_long.h"

void	f_get_position(t_data *copy)
{
	size_t	y;
	size_t	x;

	y = 0;

	while(y < copy->map->lines)
	{
		x = 0;
		while (x < copy->map->collums)
		{
			if (copy->map->map[y][x] == 'P')
			{
				copy->positions.y_player = y;
				copy->positions.x_player = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	f_floodfill(t_data *copy, size_t y, size_t x)
{
	if (copy->map->map[y][x] == 'C')
		copy->map->count_coin++;
	if (y == 0 || y == copy->map->lines - 1 || x == 0 || x == copy->map->collums - 1)
		return ;
	copy->map->map[y][x] = '1';
	if (copy->map->map[y - 1][x] == 'E' || copy->map->map[y + 1][x] == 'E' ||
		copy->map->map[y][x - 1] == 'E' || copy->map->map[y][x + 1] == 'E')
		copy->map->path_check = 1;
	if (ft_strrchr("1", copy->map->map[y - 1][x]) == NULL)
		f_floodfill(copy, y - 1, x);
	if (ft_strrchr("1", copy->map->map[y + 1][x]) == NULL)
		f_floodfill(copy, y + 1, x);
	if (ft_strrchr("1", copy->map->map[y][x - 1]) == NULL)
		f_floodfill(copy, y, x - 1);
	if (ft_strrchr("1", copy->map->map[y][x + 1]) == NULL)
		f_floodfill(copy, y, x + 1);
}