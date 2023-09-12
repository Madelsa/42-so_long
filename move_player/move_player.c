/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:46:14 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/09/12 23:18:46 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_right(t_game *game)
{
	game->map[game->y][game->x] = '0';
	put_image(game);
	game->x++;
	game->map[game->y][game->x] = '0';
	put_image(game);
	ft_printf("player y: %d player x: %d\n", game->y, game->x);
	game->map[game->y][game->x] = 'P';
	put_image(game);
	return (0);
}

int	move_left(t_game *game)
{
	if (game->map[game->y][game->x - 1] == 'E')
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		exit(0);
	}
	game->map[game->y][game->x] = '0';
	put_image(game);
	game->x--;
	game->map[game->y][game->x] = '0';
	put_image(game);
	ft_printf("player y: %d player x: %d\n", game->y, game->x);
	game->map[game->y][game->x] = 'P';
	put_image(game);
	return (0);
}

int	move_up(t_game *game)
{
	game->map[game->y][game->x] = '0';
	put_image(game);
	game->y--;
	game->map[game->y][game->x] = '0';
	put_image(game);
	ft_printf("player y: %d player x: %d\n", game->y, game->x);
	game->map[game->y][game->x] = 'P';
	put_image(game);
	return (0);
}

int	move_down(t_game *game)
{
	game->map[game->y][game->x] = '0';
	put_image(game);
	game->y++;
	game->map[game->y][game->x] = '0';
	put_image(game);
	ft_printf("player y: %d player x: %d\n", game->y, game->x);
	game->map[game->y][game->x] = 'P';
	put_image(game);
	return (0);
}

int	perform_action(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		exit(0);
	}
	else if (keycode == 2 && game->map[game->y][game->x + 1]
		!= '1')
		move_right(game);
	else if (keycode == 0 && game->map[game->y][game->x - 1] 
		!= '1')
		move_left(game);
	else if (keycode == 13 && game->map[game->y - 1][game->x] 
		!= '1')
		move_up(game);
	else if (keycode == 1 && game->map[game->y + 1][game->x] 
		!= '1')
		move_down(game);
	return (0);
}

void	test(t_game *game)
{
	game->x = game->player_x;
	game->y = game->player_y;
	ft_printf("player y: %d player x: %d\n", game->y, game->x);
	mlx_hook(game->win_ptr, 2, 1L << 0, perform_action, game);
	mlx_loop(game->mlx_ptr);
}
