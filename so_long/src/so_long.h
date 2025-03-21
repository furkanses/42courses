/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:52:18 by fses              #+#    #+#             */
/*   Updated: 2025/03/10 17:12:52 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
	int			size_y;
	int			size_x;
	int			collectible;
	char		**map_matrix;
	int			cur_x;
	int			cur_y;
	char		cur_char;
}				t_map;

typedef struct s_window
{
	void		*win;
	void		*mlx;
	void		*img1;
	void		*img0;
	void		*imgc;
	void		*imge;
	void		*imgp;
	int			img_width;
	int			img_height;
}				t_window;

typedef struct s_main
{
	t_map		*map;
	t_window	*window;
}				t_main;

int				set_map(t_map *map, const char *file);
int				free_matrix(char **str, int size);
void			fill(t_map *map, char **visited, int x, int y);
int				coin_check(t_map *map, char **visited);
int				map_check(t_map *map, char *file);
int				move(t_map *map, int move);
int				arg_check(int ac, char **av);
void			set_win_map(t_map *map, t_window *window, int i, int j);
int				set_image(t_window *window);
int				free_main(t_main *main);
int				player_check(t_map *map);
int				exit_check(t_map *map, char **visited);
int				set_map(t_map *map, const char *file);

#endif