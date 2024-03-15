#include "../include/so_long.h"

void	f_floodfill(t_data *copy, size_t y, size_t x)
{
	// ft_printf("%d\n%d\n", y, x);
	// if (copy->map->map[1][0] == 'C')
	// 	copy->map->count_coin++;
	// ft_printf("a\n");
	if (y == 0 || y == copy->map->lines - 1 || x == 0 || x == copy->map->collums - 1)
		return ;
	copy->map->map[y][x] = '1';
	if (copy->map->map[y - 1][x] == 'E' || copy->map->map[y + 1][x] == 'E' ||
		copy->map->map[y][x - 1] == 'E' || copy->map->map[y][x + 1] == 'E')
		copy->map->path_check = 1;
	if (ft_strrchr("1E", copy->map->map[y
	 - 1][x]) == NULL)
		f_floodfill(copy, y - 1, x);
	if (ft_strrchr("1E", copy->map->map[y + 1][x]) == NULL)
		f_floodfill(copy, y + 1, x);
	if (ft_strrchr("1E", copy->map->map[y][x - 1]) == NULL)
		f_floodfill(copy, y, x - 1);
	if (ft_strrchr("1E", copy->map->map[y][x + 1]) == NULL)
		f_floodfill(copy, y, x + 1);
}