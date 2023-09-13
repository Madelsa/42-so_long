/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:56:29 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/09/13 13:07:13 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_game *game)
{
	if (check_map_dimensions(game) == 1)
		return (ft_printf("%s",
				"\033[31mError\ninvalid map dimensions!\033[0m\n"), 1);
	if (check_map_invalid_chars(game->map) == 1)
		return (ft_printf("%s",
				"\033[31mError\ninvalid map char input!\033[0m\n"), 1);
	if (check_map_walls(game) == 1)
		return (ft_printf("%s",
				"\033[31mError\ninvalid map walls!\033[0m\n"), 1);
	if (check_map_duplicates(game) == 1)
		return (ft_printf("%s",
				"\033[31mError\nduplicates/missing chars in map!\033[0m\n"), 1);
	if (check_valid_path(game) == 1)
		return (ft_printf("%s",
				"\033[31mError\ncan't exit map/collect all coins!\033[0m\n"), 1);
	return (0);
}

int	main(void)
{
	int		fd;
	t_list	*map_list;
	t_game	game;
	int		line_count;

	fd = open("./maps/map1.ber", O_RDONLY);
	if (fd < 0)
		return (ft_printf("\033[31mError\ninvalid file descriptor!\033[0m\n"), 0);
	map_list = store_map_list(fd);
	line_count = get_map_lines_count(&map_list);
	game.map = malloc(sizeof(char **) * line_count + 1);
	if (game.map == NULL)
		return (1);
	game.map[line_count] = NULL;
	copy_map_to_array(&map_list, &game, line_count);
	set_game_dimensions(&game, line_count);
	if (validate_map(&game) == 1 || create_window(&game) == 1)
		return (1);
	initialize_movements(&game);
	free_map(game.map, game.map_height);
	return (0);
}
