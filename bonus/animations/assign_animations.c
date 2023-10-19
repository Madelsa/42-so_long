/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_animations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:35:59 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/09/20 13:58:10 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	assign_move_right_anim(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		game->walk_right_anim[i] = mlx_xpm_file_to_image(game->mlx_ptr,
				ft_strjoin(ft_strjoin("./animations/walk_right_anim/walk_r_",
						ft_itoa(i)), ".xpm"),
				&game->img_width, &game->img_height);
	}
}

void	assign_move_left_anim(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		game->walk_left_anim[i] = mlx_xpm_file_to_image(game->mlx_ptr,
				ft_strjoin(ft_strjoin("./animations/walk_left_anim/walk_l_",
						ft_itoa(i)), ".xpm"),
				&game->img_width, &game->img_height);
	}
}

void	assign_idle_anim(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		game->idle_anim[i] = mlx_xpm_file_to_image(game->mlx_ptr,
				ft_strjoin(ft_strjoin("./animations/idle_anim/idle_",
						ft_itoa(i)), ".xpm"),
				&game->img_width, &game->img_height);
	}
	assign_move_right_anim(game);
	assign_move_left_anim(game);
}
