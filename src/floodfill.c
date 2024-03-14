#include "../include/so_long.h"

void	f_floodfill(t_map *map, int y, int x)
{
	if (map->map[y][x] == 'C')
		map->count_coin++;
	if (y == 0 || y == map->lines - 1 || x == 0 || x == map->collums - 1)
		return ;
	map->map[y][x] = '1';
	if (map->map[y - 1][x] == 'E' || map->map[y + 1][x] == 'E' ||
		map->map[y][x - 1] == 'E' || map->map[y][x + 1] == 'E')
		map->path_check = 1;
	if (ft_strchr("1E", map->map[y - 1][x]) == NULL)
		f_floodfill(map, y - 1, x);
	if (ft_strchr("1E", map->map[y + 1][x]) == NULL)
		f_floodfill(map, y + 1, x);
	if (ft_strchr("1E", map->map[y][x - 1]) == NULL)
		f_floodfill(map, y, x - 1);
	if (ft_strchr("1E", map->map[y][x + 1]) == NULL)
		f_floodfill(map, y, x + 1);
}