/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:35:27 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/09/10 16:12:30 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = (char **)malloc(game->map_height * sizeof(char *) + 1);
	if (map_copy == NULL)
		return (NULL);
	while (i < game->map_height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	print_map(char **map)
{
	while (*map)
	{
		ft_printf("%s\n", *map);
		map++;
	}
	write(1, "\n", 1);
}

void	free_map(char **map_copy, int map_height)
{
	int	i;

	i = 0;
	while (i < map_height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}
