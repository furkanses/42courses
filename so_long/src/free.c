/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:12:47 by fses              #+#    #+#             */
/*   Updated: 2025/03/10 17:17:21 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "so_long.h"
#include <stdlib.h>

int	free_matrix(char **str, int size)
{
	int	i;

	if (str == NULL || size <= 0)
		return (0);
	i = 0;
	while (i < size)
	{
		if (str[i])
		{
			free(str[i]);
			str[i] = NULL;
		}
		i++;
	}
	free(str);
	str = NULL;
	return (0);
}

static void	free_map(t_map *map)
{
	if (map != NULL)
	{
		if (map->map_matrix)
		{
			free_matrix(map->map_matrix, map->size_y);
			map->map_matrix = NULL;
		}
		free(map);
		map = NULL;
	}
}

static void	free_textures(t_window *window)
{
	if (!window)
		return ;
	if (window->img0)
		mlx_destroy_image(window->mlx, window->img0);
	if (window->img1)
		mlx_destroy_image(window->mlx, window->img1);
	if (window->imgc)
		mlx_destroy_image(window->mlx, window->imgc);
	if (window->imge)
		mlx_destroy_image(window->mlx, window->imge);
	if (window->imgp)
		mlx_destroy_image(window->mlx, window->imgp);
}

static void	free_window(t_window *window)
{
	if (!window)
		return ;
	free_textures(window);
	if (window->mlx && window->win)
	{
		mlx_destroy_window(window->mlx, window->win);
		window->win = NULL;
	}
	if (window->mlx)
		mlx_loop_end(window->mlx);
	if (window->mlx)
	{
		mlx_destroy_display(window->mlx);
		free(window->mlx);
		window->mlx = NULL;
	}
	free(window);
	window = NULL;
}

int	free_main(t_main *main)
{
	if (main)
	{
		if (main->window)
		{
			free_window(main->window);
			main->window = NULL;
		}
		if (main->map)
		{
			free_map(main->map);
			main->map = NULL;
		}
		free(main);
		main = NULL;
	}
	exit(0);
}
