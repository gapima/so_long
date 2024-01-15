/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapima <gapima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:31:43 by gapima            #+#    #+#             */
/*   Updated: 2024/01/15 17:53:58 by gapima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error_check(9, "Error\nCouldn't connect with Xserver!\n", 1, game);
	game->window = mlx_new_window(game->mlx, (game->map->width * 64), (game->map->heigth * 64), "Getting my Coffee?!");
	if (game->window == NULL)
	{
		free(game->mlx);
		error_check(10, "Error\nCouldn't open the window!\n", 1, game);
	}
}