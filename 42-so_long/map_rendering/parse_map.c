/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:14:27 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/09/01 16:51:00 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	create_window(t_game *game)
{
	int	img_width;
	int	img_height;

	img_width = 32;
	img_height = 32;
	game->x = 0;
	game->y = 0;
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (free(game->mlx_ptr), 1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1920, 1080, "so_long");
	if (game->win_ptr == NULL)
		return (free(game->win_ptr), 1);
	game->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/grass.xpm",
			&img_width, &img_height);
	if (game->img_ptr == NULL)
	{
		perror("Failed to load image");
		return (1);
	}
	while (game->map[game->y] != NULL)
	{
		while (game->map[game->y][game->x])
		{
			if (game->map[game->y][game->x] == '0')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img_ptr, game->x * 2, game->y *2);
				ft_printf("Found: %c\n", game->map[game->y][game->x]);
			}
			game->x++;
		}
		game->x = 0;
		game->y++;
	}
	mlx_loop(game->mlx_ptr);
	return (0);
}
