/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:24:38 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/08/28 16:32:11 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_game
{
	char			**map;
	int				map_length;
	int				map_width;
	int				x;
	int				y;
}					t_game;

char				*ft_strchr(const char *str, int c);
int					check_map_invalid_chars(char **game_map);
int					check_map_dimensions(char **game_map);
int					check_map(int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new_nodes);
void				ft_lstclear(t_list **lst, void (*del)(void *));
char				*ft_strtrim(char const *s1, char const *set);
t_list				*store_map_list(int fd);
#endif