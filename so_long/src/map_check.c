/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:51:47 by fses              #+#    #+#             */
/*   Updated: 2025/03/10 17:17:34 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <stdlib.h>

static int	rectangle_check(t_map *map)
{
	int	y;
	int	size;
	int	tmp;

	y = 0;
	if (!map->map_matrix[0])
		return (0);
	tmp = ft_strlen(map->map_matrix[0]);
	while (++y < map->size_y)
	{
		size = ft_strlen(map->map_matrix[y]);
		if (map->map_matrix[y][size - 1] != '\n')
			size++;
		if (tmp != size)
			return (0);
		tmp = size;
	}
	map->size_x = size - 1;
	return (1);
}

static int	surround_check(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->size_x)
		if (map->map_matrix[0][i] != '1')
			return (0);
	i = -1;
	while (++i < map->size_y)
		if (map->map_matrix[i][0] != '1')
			return (0);
	i = map->size_x;
	while (--i)
		if (map->map_matrix[map->size_y - 1][i] != '1')
			return (0);
	i = map->size_y;
	while (--i)
		if (map->map_matrix[i][map->size_x - 1] != '1')
			return (0);
	return (1);
}

static int	inv_char_check(t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map->size_y)
	{
		i = -1;
		while (++i < map->size_x)
		{
			if (map->map_matrix[j][i] != '1' && map->map_matrix[j][i] != '0'
				&& map->map_matrix[j][i] != 'P' && map->map_matrix[j][i] != 'C'
				&& map->map_matrix[j][i] != 'E')
				return (0);
		}
	}
	return (1);
}

static int	ft_error(char **visited, int size_y)
{
	ft_putstr_fd("Error\nInvalid map file!\n", 2);
	return (free_matrix(visited, size_y));
}

int	map_check(t_map *map, char *file)
{
	int		i;
	char	**visited;
	char	*path;

	path = ft_strjoin("maps/", file);
	i = set_map(map, path);
	if (!path || i == 0)
		return (0);
	free(path);
	if (i == -1 || !map->size_y || !rectangle_check(map) || !inv_char_check(map)
		|| !player_check(map) || !surround_check(map))
	{
		ft_putstr_fd("Error\nInvalid map file!\n", 2);
		return (0);
	}
	visited = ft_calloc(map->size_y, sizeof(char *));
	i = -1;
	while (++i < map->size_y)
		visited[i] = ft_calloc(map->size_x, sizeof(char));
	fill(map, visited, map->cur_x, map->cur_y);
	if (!exit_check(map, visited) || !coin_check(map, visited))
		return (ft_error(visited, map->size_y));
	free_matrix(visited, map->size_y);
	return (1);
}
