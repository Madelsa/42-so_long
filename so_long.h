/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:24:38 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/08/29 16:49:28 by mabdelsa         ###   ########.fr       */
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
	int				map_width;
	int				map_height;
	int				x;
	int				y;
	int				coin_count;
	int				exit_count;
	int				player_count;
}					t_game;

char				*ft_strchr(const char *str, int c);
int					check_map_invalid_chars(char **game_map);
int					check_map_dimensions(t_game *game_map);
int					check_map_walls(t_game *game);
int					check_map(int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new_nodes);
void				ft_lstclear(t_list **lst, void (*del)(void *));
char				*ft_strtrim(char const *s1, char const *set);
int					check_map_duplicates(t_game *game);
t_list				*store_map_list(int fd);
#endif