
#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_map
{
	char	**map;
} t_map;

t_map   *f_validmaps(char *file);

#endif