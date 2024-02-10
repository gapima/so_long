
#include "../include/so_long.h"

int main(int argc, char *argv[])
{
	unsigned int	len;
	t_map			*i_map;
	if (!(argc == 2))
		return (1);
	len = ft_strlen(argv[1]);
	if (!(len >= 4))
		return (1);
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4))
		return (1);
	i_map = f_validmaps(argv[1]);
	if (!i_map)
		return (1);
	return (0);
}