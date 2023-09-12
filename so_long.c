/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:56:29 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/09/12 23:33:08 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*store_map_list(int fd)
{
	t_list	*node;
	char	*line;
	t_list	*new_node;

	node = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = ft_strtrim(line, "\n");
		new_node = ft_lstnew(line);
		if (new_node == NULL)
			return (ft_lstclear(&node, free), NULL);
		ft_lstadd_back(&node, new_node);
		line = get_next_line(fd);
	}
	free(line);
	return (node);
}

int	get_map_lines_count(t_list **node)
{
	t_list	*current;
	int		line_count;

	line_count = 0;
	current = *node;
	while (current != NULL)
	{
		line_count++;
		current = current->next;
	}
	return (line_count);
}

void	copy_map_to_array(t_list **map_list, t_game *game, int line_count)
{
	t_list	*current;
	int		i;

	current = *map_list;
	i = 0;
	while (i < line_count)
	{
		game->map[i] = ft_strdup(current->content);
		i++;
		current = current->next;
	}
}

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

void	set_game_dimensions(t_game *game, int line_count)
{
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = line_count;
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
	game.map[line_count] = NULL;
	copy_map_to_array(&map_list, &game, line_count);
	set_game_dimensions(&game, line_count);
	if (validate_map(&game) == 1)
		return (1);
	create_window(&game);
	free_map(game.map, game.map_height);
	return (0);
}
