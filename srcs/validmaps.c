/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmaps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima <glima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:25:59 by gapima            #+#    #+#             */
/*   Updated: 2024/01/19 15:53:23 by glima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map   f_validmaps(char *file)
{
    unsigned int	fd;
    t_map			i_map;
	unsigned int	index;
	char			*line;
	unsigned int 	len;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (get_next_line(fd))
		len++;
	close(fd);
	i_map.map = ft_calloc(sizeof(char *), len + 1);
	if (!i_map.map)
		return (NULL);
		fd = open(argv[1], O_RDONLY);
	index = 0;
	while (len)
	{
		line = get_next_line(fd);
		i_map.map[index] = ft_calloc(sizeof(char), ft_strlen(line) + 1);
		if (!i_map.map[index])
		{
			while (--index >= 0)
			{
				free(i_map.map[index]);
			}
			free(i_map.map);
			free(line);
			return (NULL);
		}
		ft_strlcpy(i_map.map[index++], line, ft_strlen(line) + 1);
		free(line);
		len--;
	}
	return (i_map);
}
