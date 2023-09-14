/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:24:38 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/09/14 12:43:18 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"

typedef struct s_game
{
	char	**map;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		total_coin_count;
	int		current_coin_count;
	int		exit_count;
	int		player_count;
	int		exit_x;
	int		exit_y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[20];
	void	*img_ptr;
	int		player_x;
	int		player_y;
	int		movement_count;
}			t_game;

int			check_valid_path(t_game *game);
void		print_map(char **map);
int			check_valid_path_rec(t_game *game, int x, int y);
int			check_map_invalid_chars(char **game_map);
int			check_map_dimensions(t_game *game_map);
int			check_map_walls(t_game *game);
int			check_map(int fd);
int			check_map_duplicates(t_game *game);
t_list		*store_map_list(int fd);
void		free_map(char **map_copy, int map_height);
int			create_window(t_game *game);
char		**copy_map(t_game *game);
void		initialize_movements(t_game *game);
int			perform_action(int keycode, t_game *game);
int			put_image(t_game *game);
int			render_map(t_game *game);
void		move_right(t_game *game);
void		move_left(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
int			get_map_lines_count(t_list **node);
void		copy_map_to_array(t_list **map_list, t_game *game, int line_count);
void		set_game_dimensions(t_game *game, int line_count);

#endif