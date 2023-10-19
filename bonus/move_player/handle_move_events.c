/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:18:20 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/10/19 09:47:16 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	right_event(t_game *game)
{
	if (game->map[game->y][game->x + 1] == 'C')
		game->current_coin_count++;
	if (game->current_coin_count == game->total_coin_count && 
		game->exit_placed == 0)
	{
		put_image(game);
		game->exit_placed = 1;
	}
	if (game->map[game->y][game->x + 1] == 'M')
	{
		ft_printf("%s", "\033[31mYou got caught by elmer!\033[0m\n");
		destroy_window(game);
	}
	if (game->current_coin_count == game->total_coin_count
		&& game->map[game->y][game->x + 1] == 'E')
	{
		destroy_window(game);
		exit(0);
	}
}

void	left_event(t_game *game)
{
	if (game->map[game->y][game->x - 1] == 'C')
		game->current_coin_count++;
	if (game->current_coin_count == game->total_coin_count && 
		game->exit_placed == 0)
	{
		put_image(game);
		game->exit_placed = 1;
	}
	if (game->map[game->y][game->x - 1] == 'M')
	{
		ft_printf("%s", "\033[31mYou got caught by elmer!\033[0m\n");
		destroy_window(game);
	}
	if (game->current_coin_count == game->total_coin_count
		&& game->map[game->y][game->x - 1] == 'E')
	{
		destroy_window(game);
		exit(0);
	}
}

void	up_event(t_game *game)
{
	if (game->map[game->y - 1][game->x] == 'C')
		game->current_coin_count++;
	if (game->current_coin_count == game->total_coin_count && 
		game->exit_placed == 0)
	{
		put_image(game);
		game->exit_placed = 1;
	}
	if (game->map[game->y - 1][game->x] == 'M')
	{
		ft_printf("%s", "\033[31mYou got caught by elmer!\033[0m\n");
		destroy_window(game);
	}
	if (game->current_coin_count == game->total_coin_count
		&& game->map[game->y - 1][game->x] == 'E')
	{
		destroy_window(game);
		exit(0);
	}
}

void	down_event(t_game *game)
{
	if (game->map[game->y + 1][game->x] == 'C')
		game->current_coin_count++;
	if (game->current_coin_count == game->total_coin_count && 
		game->exit_placed == 0)
	{
		put_image(game);
		game->exit_placed = 1;
	}
	if (game->map[game->y + 1][game->x] == 'M')
	{
		ft_printf("%s", "\033[31mYou got caught by elmer!\033[0m\n");
		destroy_window(game);
	}
	if (game->current_coin_count == game->total_coin_count
		&& game->map[game->y + 1][game->x] == 'E')
	{
		destroy_window(game);
		exit(0);
	}
}
