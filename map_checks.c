/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 07:18:48 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/08/31 15:49:50 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line/get_next_line.h"
#include "so_long.h"

int	check_map_invalid_chars(char **game_map)
{
	int		i;
	char	*valid_chars;
	int		j;

	i = 0;
	valid_chars = "01CEP";
	while (game_map[i] != NULL)
	{
		j = 0;
		while (game_map[i][j] != '\0')
		{
			if (ft_strchr(valid_chars, game_map[i][j]) == NULL)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_dimensions(t_game *game)
{
	int				i;
	int				line_length;

	i = 1;
	line_length = 0;
	if (game->map_width <= 1 || game->map_height <= 1)
		return (1);
	if (line_length == 0)
		line_length = game->map_width;
	if (line_length == game->map_height)
		return (1);
	while (game->map[i] != NULL)
	{
		if (ft_strlen(game->map[i]) != line_length)
			return (1);
		i++;
	}
	return (0);
}

int	check_map_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (i == 0 && game->map[i][j] != '1')
				return (1);
			if ((i > 0 && i < game->map_height - 1) && (j == 0
					|| j == game->map_width - 1) && (game->map[i][0] != '1'
				|| game->map[i][game->map_width - 1] != '1'))
				return (1);
			if (i == game->map_height - 1 && game->map[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_map_duplicates_rec(t_game *game, int i, int j)
{
	if (i == game->map_height - 1 || game->exit_count > 1 
		|| game->player_count > 1)
		return ;
	if (game->map[i][j] != '\0')
	{
		if (game->map[i][j] == 'C')
			game->coin_count++;
		else if (game->map[i][j] == 'P' && game->player_count < 1)
		{
			game->player_count++;
			game->x = j;
			game->y = i;
		}
		else if (game->map[i][j] == 'E')
			game->exit_count++;
		check_map_duplicates_rec(game, i, j + 1);
	}
	else
		check_map_duplicates_rec(game, i + 1, 0);
}

int	check_map_duplicates(t_game *game)
{
	game->coin_count = 0;
	game->player_count = 0;
	game->exit_count = 0;
	check_map_duplicates_rec(game, 1, 0);
	if (game->coin_count < 1 || game->player_count != 1 
		|| game->exit_count != 1)
		return (1);
	return (0);
}

int	check_valid_path(t_game game)
{
	if (game.x < 0 || game.x >= game.map_width || game.y < 0
		|| game.y >= game.map_height 
		|| game.map[game.x][game.y] != '0')
		return (1);
	
	game.map[game.x][game.y] = 'T';
	check_valid_path(game)
}