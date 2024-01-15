/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapima <gapima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:03:54 by gapima            #+#    #+#             */
/*   Updated: 2024/01/15 17:04:22 by gapima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MAP_CHARS "01CEP"

# define FINN_D "./textures/finn_down_64.xpm"
# define FINN_L "textures/finn_left_64.xpm"
# define FINN_R "textures/finn_right_64.xpm"
# define FINN_U "textures/finn_up_64.xpm"
# define EXIT1 "textures/exit1_64.xpm"
# define EXIT2 "textures/exit2_64.xpm"
# define EXIT3 "textures/exit3_64.xpm"
# define GROUND "textures/ground_64.xpm"
# define WALL "textures/wall_64.xpm"
# define ICEKING "textures/iceking_64.xpm"
# define BMO "textures/bmo_64.xpm"
# define COIN "textures/coin_64.xpm"
# define DEATH1 "textures/death1_64.xpm"
# define DEATH2 "textures/death2_64.xpm"
# define DEATH3 "textures/death3_64.xpm"
# define DEATH4 "textures/death4_64.xpm"
# define DEATH5 "textures/death5_64.xpm"
# define WIN1 "textures/win1_64.xpm"
# define WIN2 "textures/win2_64.xpm"
# define WIN3 "textures/win3_64.xpm"
# define WIN4 "textures/win4_64.xpm"
# define WIN5 "textures/win5_64.xpm"

typedef struct s_map
{
	char	*file;
	int		fd;
	char	**map;
	int		size;
	int		width;
	int		height;
	int		player;
	int		exit;
	int		coin;
	int		coin_count;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		path_check;
	int		check_format;
}			t_map;

typedef struct s_sprite
{
	void	*finn_d;
	void	*finn_l;
	void	*finn_r;
	void	*finn_u;
	void	*exit1;
	void	*exit2;
	void	*exit3;
	void	*ground;
	void	*wall;
	void	*iceking;
	void	*bmo;
	void	*coin;
	void	*death1;
	void	*death2;
	void	*death3;
	void	*death4;
	void	*death5;
	void	*win1;
	void	*win2;
	void	*win3;
	void	*win4;
	void	*win5;
}			t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			img_width;
	int			img_height;
	int			steps;
	t_sprite	*spt;
	t_map		*map;
}			t_game;

void	valid_map_call(int argc, char *map_path, t_map *map);
void	get_map_size(t_map *map);
void	allocation(t_map *map);
void	valid_map_draw(t_map *map);
void	draw_map(t_map *map);
int		check_for_wall_surround(t_map *map);
int		check_for_player(t_map *map);
int		check_for_exit(t_map *map);
int		check_for_coins(t_map *map);
int		check_for_dif_char(t_map *map);
void	copy_map(t_map *copy, t_map *map);
void	check_for_nopath(t_map *map, int y, int x);

void	game_init(t_game *game);
void	take_sprites(t_game *game, t_sprite *spt);
void	take_exit(t_game *game, t_sprite *spt);
void	take_win(t_game *game, t_sprite *spt);
void	take_death(t_game *game, t_sprite *spt);

void	fill_map(t_map *map, t_game *game);
void	put_player(t_map *map, t_game *game, t_sprite *spt, char direction);
void	put_coin_and_enemy(t_map *map, t_game *game, t_sprite *spt);
void	put_wall_and_ground(t_map *map, t_game *game, t_sprite *spt);
void	put_exit(t_map *map, t_game *game, t_sprite *spt);
void	print_steps(t_game *game);

void	gameplay(t_game *game);
void	step_right(t_map *map, t_game *game);
void	step_left(t_map *map, t_game *game);
void	step_up(t_map *map, t_game *game);
void	step_down(t_map *map, t_game *game);

int		no_input(t_game *game);
int		key_pressed(int key, t_game *game);
int		x_press(t_game *game);

void	bad_ending(t_map *map, t_game *game, t_sprite *spt);
void	good_ending(t_map *map, t_game *game, t_sprite *spt);

void	free_map(t_map *map);
void	free_images(t_game *game);
void	free_exit(t_game *game);
void	free_win(t_game *game);
void	free_death(t_game *game);
void	free_mlx(t_game *game);
void	free_for_finish(t_map *map, t_game *game);
void	error_check(int i, char *errormsg, int program_stage, t_game *game);

#endif