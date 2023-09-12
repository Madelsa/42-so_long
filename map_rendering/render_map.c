/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:14:27 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/09/12 22:35:57 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	assign_images(t_game *game, int *img_width, int *img_height)
{
	game->textures[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/grass.xpm", img_width, img_height);
	game->textures[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/tiles.xpm", img_width, img_height);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/tree.xpm", img_width, img_height);
	game->textures[3] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/rock.xpm", img_width, img_height);
	game->textures[4] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/exit.xpm", img_width, img_height);
	game->textures[5] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/gem.xpm", img_width, img_height);
	game->textures[6] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/player.xpm", img_width, img_height);
	// if (game->img_ptr == NULL)
	// {
	// 	perror("Failed to load image");
	// 	return (1);
	// }
	return (1);
}

int	put_image(t_game *game, int *img_width, int *img_height)
{
	if (game->map[game->y][game->x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures[0], game->x * (*img_width), game->y 
			* (*img_height));
	else if (game->y == 0 || game->y == game->map_height - 1 || game->x == 0
		|| game->x == game->map_width - 1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[2],
			game->x * (*img_width), game->y * (*img_height));
	else if (game->map[game->y][game->x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[3],
			game->x * (*img_width), game->y * (*img_height));
	if (game->map[game->y][game->x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[4],
			game->x * (*img_width), game->y * (*img_height));
	else if (game->map[game->y][game->x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[5],
			game->x * (*img_width), game->y * (*img_height));
	else if (game->map[game->y][game->x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[6],
			game->x * (*img_width), game->y * (*img_height));
	return (0);
}

int	render_map(t_game *game, int *img_width, int *img_height)
{
	game->x = 0;
	game->y = 0;
	while (game->map[game->y] != NULL)
	{
		while (game->map[game->y][game->x] != '\0')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->textures[0], game->x * (*img_width), game->y 
				* (*img_height));
			put_image(game, img_width, img_height);
			game->x++;
		}
		game->x = 0;
		game->y++;
	}
	test(game, img_width, img_height);
	return (0);
}

int	create_window(t_game *game)
{
	int	img_width;
	int	img_height;

	img_width = 64;
	img_height = 64;
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (free(game->mlx_ptr), 1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_width * img_width,
			game->map_height * img_height, "so_long");
	if (game->win_ptr == NULL)
		return (free(game->win_ptr), 1);
	assign_images(game, &img_width, &img_height);
	ft_printf("width: %d height: %d\n", img_width, img_height);
	render_map(game, &img_width, &img_height);
	return (0);
}
