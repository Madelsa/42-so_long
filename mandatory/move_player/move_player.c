/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:46:14 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/10/09 14:26:15 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_game *game)
{
	ft_printf("Movement count: %d\n", ++game->movement_count);
	game->map[game->exit_y][game->exit_x] = 'E';
	if (game->map[game->y][game->x + 1] == 'C')
		game->current_coin_count++;
	if (game->current_coin_count == game->total_coin_count && 
		game->exit_placed == 0)
	{
		put_image(game);
		game->exit_placed = 1;
	}
	if (game->current_coin_count == game->total_coin_count
		&& game->map[game->y][game->x + 1] == 'E')
		destroy_window(game);
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
	if (game->current_coin_count == game->total_coin_count && 
		game->exit_placed == 0)
	{
		put_image(game);
		game->exit_placed = 1;
	}
	if (game->current_coin_count == game->total_coin_count
		&& game->map[game->y][game->x - 1] == 'E')
		destroy_window(game);
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
	if (game->current_coin_count == game->total_coin_count && 
		game->exit_placed == 0)
	{
		put_image(game);
		game->exit_placed = 1;
	}
	if (game->current_coin_count == game->total_coin_count
		&& game->map[game->y - 1][game->x] == 'E')
		destroy_window(game);
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
	if (game->current_coin_count == game->total_coin_count && 
		game->exit_placed == 0)
	{
		put_image(game);
		game->exit_placed = 1;
	}
	if (game->current_coin_count == game->total_coin_count
		&& game->map[game->y + 1][game->x] == 'E')
		destroy_window(game);
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
	if (keycode == 53)
		destroy_window(game);
	else if ((keycode == 2 || keycode == 124) 
		&& game->map[game->y][game->x + 1] != '1')
		move_right(game);
	else if ((keycode == 0 || keycode == 123) 
		&& game->map[game->y][game->x - 1] != '1')
		move_left(game);
	else if ((keycode == 13 || keycode == 126) 
		&& game->map[game->y - 1][game->x] != '1')
		move_up(game);
	else if ((keycode == 1 || keycode == 125) 
		&& game->map[game->y + 1][game->x] != '1')
		move_down(game);
	if (game->current_coin_count == game->total_coin_count
		&& game->message_printed == 0)
	{
		game->message_printed = 1;
		printf("\x1b[32mAll carrots collected, exit is now open!\x1b[0m\n");
	}
	return (0);
}
