/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_original_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:55:50 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/09/13 12:56:44 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	set_game_dimensions(t_game *game, int line_count)
{
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = line_count;
}
