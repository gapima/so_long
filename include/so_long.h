
#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define WALL "./textures/wall.png"
# define FLOOR "./textures/floor.png"

typedef struct s_map
{
	char	**map;
	size_t	collums;
	size_t	lines;
} t_map;

typedef struct s_textures
{
	mlx_image_t		*wall_img;
	mlx_image_t 	*floor_img;
	mlx_texture_t 	*wall_texture;
	mlx_texture_t 	*floor_texture;
} t_textures;


t_map   *f_validmaps(char *file);
void	f_create_textures(t_textures *textures, mlx_t *mlx);

#endif