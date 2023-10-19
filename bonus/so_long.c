/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:56:29 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/10/19 16:12:36 by mabdelsa         ###   ########.fr       */
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
				"\033[31mError\nMap contains an invalid input!\033[0m\n"), 1);
	if (check_map_walls(game) == 1)
		return (ft_printf("%s",
				"\033[31mError\nMap's border must only contain char '1'!\033[0m\n")
			, 1);
	if (check_map_duplicates(game) == 1)
		return (ft_printf("%s",
				"\033[31mError\nMap must contain one 'P', one 'E'"
				" and at least one 'C'!\033[0m\n"), 1);
	if (check_valid_path(game) == 1)
		return (ft_printf("%s",
				"\033[31mError\nPlayer can't exit map and/or"
				" collect all coins!\033[0m\n"), 1);
	return (0);
}

int	validate_file(char *av)
{
	if (ft_strncmp(ft_substr(av, ft_strlen(av) - 4, 4), ".ber", 4) != 0)
		return (ft_printf("%s",
				"\033[31mError\nInvalid map extension!\033[0m\n"), 1);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_list	*map_list;
	t_game	game;
	int		line_count;

	if (ac > 2)
		return (1);
	if (validate_file(av[1]) == 1)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("\033[31mError\nUnable to open the file!\033[0m\n"), 0);
	map_list = store_map_list(fd);
	line_count = get_map_lines_count(map_list);
	game.map = (char **)malloc(sizeof(char **) * line_count + 1);
	if (game.map == NULL)
		return (1);
	game.map[line_count] = NULL;
	copy_map_to_array(map_list, &game, line_count);
	set_game_dimensions(&game, line_count);
	if (validate_map(&game) == 1 || create_window(&game) == 1)
		return (1);
	initialize_movements(&game);
	return (0);
}
