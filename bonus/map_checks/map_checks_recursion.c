/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_recursion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:02:11 by mabdelsa          #+#    #+#             */
/*   Updated: 2024/02/01 12:09:19 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_duplicates_rec(t_game *game, int i, int j)
{
	if (i == game->map_height - 1 || game->exit_count > 1
		|| game->player_count > 1)
		return ;
	if (game->map[i][j] != '\0')
	{
		if (game->map[i][j] == 'C')
			game->total_coin_count++;
		else if (game->map[i][j] == 'P')
		{
			game->player_count++;
			game->player_x = j;
			game->player_y = i;
		}
		else if (game->map[i][j] == 'E')
		{
			game->exit_count++;
			game->exit_x = j;
			game->exit_y = i;
		}
		check_map_duplicates_rec(game, i, j + 1);
	}
	else
		check_map_duplicates_rec(game, i + 1, 0);
}

int	check_map_duplicates(t_game *game)
{
	game->total_coin_count = 0;
	game->player_count = 0;
	game->exit_count = 0;
	check_map_duplicates_rec(game, 1, 0);
	if (game->total_coin_count < 1 || game->player_count != 1
		|| game->exit_count != 1)
		return (1);
	return (0);
}

int	check_valid_path_rec(t_game *game, int x, int y)
{
	static int	coins_collected = 0;
	static int	exit_found = 0;

	if (game->mapped_map[y][x] == '0' || game->mapped_map[y][x] == 'E'
		|| game->mapped_map[y][x] == 'C')
	{
		if (game->mapped_map[y][x] == 'C')
			coins_collected++;
		if (game->mapped_map[y][x] == 'E')
			exit_found = 1;
		game->mapped_map[y][x] = 'X';
		if (x != 1)
			check_valid_path_rec(game, x - 1, y);
		if (x < game->map_width)
			check_valid_path_rec(game, x + 1, y);
		if (y != 1)
			check_valid_path_rec(game, x, y - 1);
		if (y < game->map_height)
			check_valid_path_rec(game, x, y + 1);
	}
	if (coins_collected == game->total_coin_count && exit_found == 1)
		return (0);
	return (1);
}

int	check_valid_path(t_game *game)
{
	int		x;
	int		y;
	int		map_valid;

	x = game->player_x;
	y = game->player_y;
	game->mapped_map = copy_map(game);
	game->mapped_map[y][x] = '0';
	map_valid = check_valid_path_rec(game, x, y);
	print_map(game->mapped_map);
	print_map(game->map);
	return (map_valid);
}
