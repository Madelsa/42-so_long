/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:15:34 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/10/19 11:51:32 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_movement_count(t_game *game)
{
	char	*move_count;

	move_count = ft_itoa(game->movement_count);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->textures[6], 0, game->map_height
		* (game->img_height));
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, game->map_height
		* game->img_height + 20, 0xFFFFFF, 
		ft_strjoin("Movement count: ", move_count));
	free(move_count);
}
