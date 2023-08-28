/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:56:29 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/08/28 16:49:20 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	check_map(int fd)
// {
// 	char	*line;
// 	char	*temp;
// 	char	**map;
// 	int		i;

// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		if (check_map_invalid_chars(line) == 1)
// 			return (ft_printf("%s", "Error: invalid map character input!"), 0);
// 		if (check_map_dimensions(line) == 1)
// 			return (ft_printf("%s", "Error: invalid map dimensions!"), 0);
// 		temp = ft_strdup(line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	// map = malloc(sizeof(char **) * line_count + 1);
// 	// while (i < line_count)
// 	// {
// 	// 	map[i] = malloc(sizeof(char) * ft_strlen(line));
// 	// 	map[i]close(fd); = get_next_line(fd);
// 	// 	i++;
// 	// }
// 	//test
// 	i = 0;
// 	return (0);
// }

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
		if (ft_strlen(line) == 0)
		{
			line = get_next_line(fd);
			continue ;
		}
		new_node = ft_lstnew(line);
		if (new_node == NULL)
			return (ft_lstclear(&node, free), NULL);
		ft_lstadd_back(&node, new_node);
		line = get_next_line(fd);
	}
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

void	copy_map_to_array(t_list **map_list, t_game game, int line_count)
{
	t_list	*current;
	int		i;

	current = *map_list;
	i = 0;
	while (i < line_count)
	{
		game.map[i] = ft_strdup(current->content);
		i++;
		current = current->next;
	}
}

int	validate_map(t_game game)
{
	if (check_map_invalid_chars(game.map) == 1)
		return (ft_printf("%s",
				"\033[31mError: invalid map character input!\033[0m\n"), 0);
	if (check_map_dimensions(game.map) == 1)
			return (ft_printf("%s", "Error: invalid map dimensions!"), 0);
	return (0);
}

int	main(void)
{
	int		fd;
	t_list	*map_list;
	t_game	game;
	int		line_count;

	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		return (ft_printf("\033[31mError: invalid file descriptor\033[0m\n"),
			0);
	map_list = store_map_list(fd);
	line_count = get_map_lines_count(&map_list);
	game.map = malloc(sizeof(char **) * line_count + 1);
	game.map[line_count] = NULL;
	copy_map_to_array(&map_list, game, line_count);
	validate_map(game);
	return (0);
}
