/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:15:53 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/10/19 12:06:03 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <time.h>

int	put_anim(t_game *game)
{
	static int	i = 0;

	if (game->player_status == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures[0], game->x * (game->img_width),
			game->y * (game->img_height));
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->idle_anim[i], game->x * (game->img_width),
			game->y * (game->img_height));
		i++;
		if (i == 15)
			i = 0;
	}
	return (0);
}

int	put_anim_move_right(t_game *game)
{
	static int	i = 0;

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->walk_right_anim[i], game->x * (game->img_width),
		game->y * (game->img_height));
	i++;
	if (i == 7)
		i = 0;
	return (0);
}

int	put_anim_move_left(t_game *game)
{
	static int	i = 0;

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->walk_left_anim[i], game->x * (game->img_width),
		game->y * (game->img_height));
	i++;
	if (i == 7)
		i = 0;
	return (0);
}

int	idle_anim_delay(t_game *game)
{
	clock_t			current_time;
	clock_t			interval;
	static clock_t	last_time = 0;

	current_time = clock();
	interval = CLOCKS_PER_SEC / 55;
	if (current_time - last_time >= interval)
	{
		last_time = current_time;
		put_anim(game);
	}
	return (0);
}
