/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:14:27 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/10/19 11:53:22 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	assign_images(t_game *game)
{
	game->textures[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/grass.xpm", &game->img_width, &game->img_height);
	game->textures[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/elmer.xpm", &game->img_width, &game->img_height);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/tree.xpm", &game->img_width, &game->img_height);
	game->textures[3] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/rock.xpm", &game->img_width, &game->img_height);
	game->textures[4] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/exit.xpm", &game->img_width, &game->img_height);
	game->textures[5] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/carrot.xpm", &game->img_width, &game->img_height);
	game->textures[6] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/black_bar.xpm", &game->img_width, &game->img_height);
	if (game->textures[0] == NULL || game->textures[1] == NULL
		|| game->textures[2] == NULL || game->textures[3] == NULL
		|| game->textures[4] == NULL || game->textures[5] == NULL
		|| game->textures[6] == NULL)
		return (1);
	return (0);
}

void	put_image(t_game *game)
{
	if (game->current_coin_count == game->total_coin_count)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[4],
			game->exit_x * (game->img_width),
			game->exit_y * (game->img_height));
	if (game->map[game->y][game->x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->textures[0], game->x * (game->img_width), game->y
			* (game->img_height));
	else if (game->y == 0 || game->y == game->map_height - 1 || game->x == 0
		|| game->x == game->map_width - 1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[2],
			game->x * (game->img_width), game->y * (game->img_height));
	else if (game->map[game->y][game->x] == 'M')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[1],
			game->x * (game->img_width), game->y * (game->img_height));
	else if (game->map[game->y][game->x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[3],
			game->x * (game->img_width), game->y * (game->img_height));
	else if (game->map[game->y][game->x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[5],
			game->x * (game->img_width), game->y * (game->img_height));
}

void	render_map(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->current_coin_count = 0;
	while (game->map[game->y] != NULL)
	{
		while (game->map[game->y][game->x] != '\0')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->textures[0], game->x * (game->img_width), game->y
				* (game->img_height));
			put_image(game);
			game->x++;
		}
		game->x = 0;
		game->y++;
	}
}

void	initialize_movements(t_game *game)
{
	game->x = game->player_x;
	game->y = game->player_y;
	game->movement_count = 0;
	game->message_printed = 0;
	game->player_status = 0;
	game->exit_placed = 0;
	display_movement_count(game);
	put_anim(game);
	mlx_loop_hook(game->mlx_ptr, idle_anim_delay, game);
	mlx_hook(game->win_ptr, 17, 1L << 17, destroy_window, game);
	mlx_hook(game->win_ptr, 2, 1L << 0, perform_action, game);
	mlx_hook(game->win_ptr, 3, 1L << 1, switch_to_idle, game);
	mlx_loop(game->mlx_ptr);
}

int	create_window(t_game *game)
{
	game->img_height = 64;
	game->img_width = 64;
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_width
			* game->img_width, game->map_height * game->img_height + 30,
			"so_long");
	if (game->win_ptr == NULL)
		return (1);
	if (assign_images(game) == 1)
		return (1);
	assign_idle_anim(game);
	render_map(game);
	return (0);
}
