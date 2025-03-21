/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:52:14 by fses              #+#    #+#             */
/*   Updated: 2025/03/10 17:21:22 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "so_long.h"

static int	ft_return(void)
{
	ft_putstr_fd("Error\nSome texture file missing!\n", 2);
	return (0);
}

int	set_image(t_window *window)
{
	window->img1 = mlx_xpm_file_to_image(window->mlx, "textures/1.xpm",
			&window->img_width, &window->img_height);
	if (!window->img1)
		return (ft_return());
	window->img0 = mlx_xpm_file_to_image(window->mlx, "textures/0.xpm",
			&window->img_width, &window->img_height);
	if (!window->img0)
		return (ft_return());
	window->imgc = mlx_xpm_file_to_image(window->mlx, "textures/C.xpm",
			&window->img_width, &window->img_height);
	if (!window->imgc)
		return (ft_return());
	window->imge = mlx_xpm_file_to_image(window->mlx, "textures/E.xpm",
			&window->img_width, &window->img_height);
	if (!window->imge)
		return (ft_return());
	window->imgp = mlx_xpm_file_to_image(window->mlx, "textures/P.xpm",
			&window->img_width, &window->img_height);
	if (!window->imgp)
		return (ft_return());
	return (1);
}

void	set_win_map(t_map *map, t_window *window, int i, int j)
{
	j = -1;
	while (++j < map->size_y)
	{
		i = -1;
		while (++i < map->size_x)
		{
			if (map->map_matrix[j][i] == '1')
				mlx_put_image_to_window(window->mlx, window->win, window->img1,
					64 * i, 64 * j);
			else if (map->map_matrix[j][i] == '0')
				mlx_put_image_to_window(window->mlx, window->win, window->img0,
					64 * i, 64 * j);
			else if (map->map_matrix[j][i] == 'P')
				mlx_put_image_to_window(window->mlx, window->win, window->imgp,
					64 * i, 64 * j);
			else if (map->map_matrix[j][i] == 'C')
				mlx_put_image_to_window(window->mlx, window->win, window->imgc,
					64 * i, 64 * j);
			else
				mlx_put_image_to_window(window->mlx, window->win, window->imge,
					64 * i, 64 * j);
		}
	}
}

int	exit_check(t_map *map, char **visited)
{
	int	j;
	int	i;
	int	count;
	int	col_count;

	count = 0;
	col_count = 0;
	i = -1;
	while (++i < map->size_y)
	{
		j = -1;
		while (++j < map->size_x)
		{
			if (map->map_matrix[i][j] == 'E')
				count++;
			if (map->map_matrix[i][j] == 'E' && visited[i][j])
				col_count++;
		}
	}
	if (count == col_count && count == 1)
		return (1);
	return (0);
}
