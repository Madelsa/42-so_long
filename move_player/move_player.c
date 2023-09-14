/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:46:14 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/09/14 15:54:27 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_game *game)
{
	ft_printf("Movement count: %d\n", ++game->movement_count);
	game->map[game->exit_y][game->exit_x] = 'E';
	if (game->map[game->y][game->x + 1] == 'C')
		game->current_coin_count++;
	if (game->current_coin_count == game->total_coin_count)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[4],
			game->exit_x * (game->img_width),
			game->exit_y * (game->img_height));
	if (game->current_coin_count == game->total_coin_count
		&& game->map[game->y][game->x + 1] == 'E')
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		exit(0);
	}
	game->map[game->y][game->x] = '0';
	put_image(game);
	game->x++;
	game->map[game->y][game->x] = '0';
	put_image(game);
	game->map[game->y][game->x] = 'P';
	put_image(game);
	return ;
}

void	move_left(t_game *game)
{
	ft_printf("Movement count: %d\n", ++game->movement_count);
	game->map[game->exit_y][game->exit_x] = 'E';
	if (game->map[game->y][game->x - 1] == 'C')
		game->current_coin_count++;
	if (game->current_coin_count == game->total_coin_count)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[4],
			game->exit_x * (game->img_width),
			game->exit_y * (game->img_height));
	if (game->current_coin_count == game->total_coin_count
		&& game->map[game->y][game->x - 1] == 'E')
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		exit(0);
	}
	game->map[game->y][game->x] = '0';
	put_image(game);
	game->x--;
	game->map[game->y][game->x] = '0';
	put_image(game);
	game->map[game->y][game->x] = 'P';
	put_image(game);
	return ;
}

void	move_up(t_game *game)
{
	ft_printf("Movement count: %d\n", ++game->movement_count);
	game->map[game->exit_y][game->exit_x] = 'E';
	if (game->map[game->y - 1][game->x] == 'C')
		game->current_coin_count++;
	if (game->current_coin_count == game->total_coin_count)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[4],
			game->exit_x * (game->img_width),
			game->exit_y * (game->img_height));
	if (game->current_coin_count == game->total_coin_count
		&& game->map[game->y - 1][game->x] == 'E')
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		exit(0);
	}
	game->map[game->y][game->x] = '0';
	put_image(game);
	game->y--;
	game->map[game->y][game->x] = '0';
	put_image(game);
	game->map[game->y][game->x] = 'P';
	put_image(game);
	return ;
}

void	move_down(t_game *game)
{
	ft_printf("Movement count: %d\n", ++game->movement_count);
	game->map[game->exit_y][game->exit_x] = 'E';
	if (game->map[game->y + 1][game->x] == 'C')
		game->current_coin_count++;
	if (game->current_coin_count == game->total_coin_count)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->textures[4],
			game->exit_x * (game->img_width),
			game->exit_y * (game->img_height));
	if (game->current_coin_count == game->total_coin_count
		&& game->map[game->y + 1][game->x] == 'E')
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		exit(0);
	}
	game->map[game->y][game->x] = '0';
	put_image(game);
	game->y++;
	game->map[game->y][game->x] = '0';
	put_image(game);
	game->map[game->y][game->x] = 'P';
	put_image(game);
	return ;
}

int	perform_action(int keycode, t_game *game)
{
	static int	message_printed = 0;

	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		exit(0);
	}
	else if (keycode == 2 && game->map[game->y][game->x + 1] != '1')
		move_right(game);
	else if (keycode == 0 && game->map[game->y][game->x - 1] != '1')
		move_left(game);
	else if (keycode == 13 && game->map[game->y - 1][game->x] != '1')
		move_up(game);
	else if (keycode == 1 && game->map[game->y + 1][game->x] != '1')
		move_down(game);
	if (game->current_coin_count == game->total_coin_count)
	{
		message_printed = 1;
		printf("\x1b[32mAll carrots collected, exit is now open!\x1b[0m\n");
	}
	return (0);
}
