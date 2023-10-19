/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_win_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:57:41 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/10/19 11:39:06 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_images_1(t_game *game)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (game->textures[i] != NULL)
			mlx_destroy_image(game->mlx_ptr, game->textures[i]);
		i++;
	}
	i = 0;
	while (i < 16)
	{
		if (game->idle_anim[i] != NULL)
			mlx_destroy_image(game->mlx_ptr, game->idle_anim[i]);
		i++;
	}
}

void	destroy_images_2(t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (game->walk_right_anim[i] != NULL)
			mlx_destroy_image(game->mlx_ptr, game->walk_right_anim[i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (game->walk_left_anim[i] != NULL)
			mlx_destroy_image(game->mlx_ptr, game->walk_left_anim[i]);
		i++;
	}
}

int	destroy_window(t_game *game)
{
	destroy_images_1(game);
	destroy_images_2(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_maps(game, game->map_height);
	exit(0);
}
