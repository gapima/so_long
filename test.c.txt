#include <mlx.h>
#include <X11/X.h>
#include <stdio.h>

int main()
{
	void *point;
	void *windows;
	int i = 0;
	void *wall;
	void *ground;
	int height;
	int width;

	point = mlx_init();
	windows = mlx_new_window(point, 800, 400, "teste");
	wall = mlx_xpm_file_to_image(point, "wall.xpm", &width, &height);
	printf("%p\n", wall);
	ground = mlx_xpm_file_to_image(point, "floor.xpm", &width, &height);
	while (i < 400)
	{
		int j = 0;
		while (j < 800)
		{
			if (i == 0 || i == 350 || j == 0 || j == 700)
				mlx_put_image_to_window(point, windows, wall, j, i);
			else
				mlx_put_image_to_windo1w(point, windows, ground, j, i);
			j += width;
		}
		i += height;
	}
	mlx_loop(point);
}