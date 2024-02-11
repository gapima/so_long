
#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define WALL "./textures/wall.png"
# define FLOOR "./textures/floor.png"
# define PLAYER "./textures/player.png"
# define COIN "./textures/coin.png"

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
	mlx_image_t 	*player_img;
	mlx_image_t 	*coin_img;
	mlx_texture_t 	*wall_texture;
	mlx_texture_t 	*floor_texture;
	mlx_texture_t 	*player_texture;
	mlx_texture_t 	*coin_texture;
} t_textures;


t_map   *f_mallocmap(char *file);

void	f_create_textures(t_textures *textures, mlx_t *mlx);
void	f_put_player_items(mlx_t *mlx, t_textures *textures, t_map *i_map);

int		f_getmap(t_map *i_map, int fd, int index, unsigned int len);
int		f_play(t_map *i_map);

#endif