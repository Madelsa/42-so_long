/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_win_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:57:41 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/10/09 14:52:59 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (game->textures[i] != NULL)
			mlx_destroy_image(game->mlx_ptr, game->textures[i]);
		i++;
	}
}

int	destroy_window(t_game *game)
{
	destroy_images(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_maps(game, game->map_height);
	exit(0);
}
