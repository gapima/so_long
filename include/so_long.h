
#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42/MLX42.h"

# define WALL "./textures/wall.png"
# define FLOOR "./textures/floor.png"
# define PLAYER_R "./textures/player.png"
# define PLAYER_L "./textures/player.png"
# define PLAYER_U "./textures/player.png"
# define PLAYER_D "./textures/player.png"
# define COIN "./textures/coin.png"

# define SIZE_IMG 64
# define TILE_SIZE 64

typedef struct s_positions
{
	int		x_player;
	int		y_player;
	int		x_out;
	int		y_out;
} t_positions;

typedef struct s_map
{
	char	**map;
	size_t	collums;
	size_t	lines;
	int		count_coin;
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
	int				last_move_player;
} t_textures;

typedef struct s_data
{
	t_textures	*textures;
	t_map		*map;
	t_positions	positions;
	mlx_t		*mlx;
	int			move;

} t_data;


t_map   *f_mallocmap(char *file);

void	f_create_textures(t_data *data);
void	f_put_player_items(t_data *data);
void	f_start_game(t_data *data);
void	f_action_up(t_data *data, int y, int x);
void	f_action_down(t_data *data, int y, int x);
void	f_action_right(t_data *data, int y, int x);
void	f_action_left(t_data *data, int y, int x);
void	f_control_player(mlx_key_data_t keyd, void *param);
void	f_paint_wall(t_data *data, int x, int y);
void	f_paint_floor(t_data *data, int x, int y);
void	f_paint_coin(t_data *data, int x, int y);
void	f_paint_player(t_data *data, int x, int y);
void	f_render_move_player(t_data *data, int y, int x);
void	f_free_map(char **map);
void	f_delete_images(t_data data);
void	f_delete_textures(t_data *data);
void	f_close_window(void *key);

int		f_getmap(t_data *data, int fd, int index, unsigned int len);
int	f_free_end_game(t_data *data);

#endif