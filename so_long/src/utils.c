/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:52:12 by fses              #+#    #+#             */
/*   Updated: 2025/03/13 21:11:17 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	arg_check(int ac, char **av)
{
	int		fd;
	char	*path;

	fd = 0;
	if (ac != 2)
	{
		ft_putstr_fd("Error\nInvalid argument!\n", 2);
		return (0);
	}
	path = ft_strjoin("maps/", av[1]);
	if (!path)
		return (0);
	fd = open(path, O_RDONLY);
	if (ft_strlen(av[1]) < 5 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber",
			5) != 0 || fd == -1)
	{
		if (fd)
			close(fd);
		ft_putstr_fd("Error\nInvalid argument!\n", 2);
		free(path);
		return (0);
	}
	free(path);
	close(fd);
	return (1);
}

void	fill(t_map *map, char **visited, int x, int y)
{
	if ((y < 0) || (x < 0) || (y >= map->size_y) || (x >= map->size_x)
		|| map->map_matrix[y][x] == '1' || visited[y][x] == 1)
		return ;
	visited[y][x] = 1;
	fill(map, visited, x - 1, y);
	fill(map, visited, x + 1, y);
	fill(map, visited, x, y - 1);
	fill(map, visited, x, y + 1);
}

int	player_check(t_map *map)
{
	int	j;
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (++i < map->size_y)
	{
		j = -1;
		while (++j < map->size_x)
		{
			if (map->map_matrix[i][j] == 'P')
			{
				count++;
				map->cur_x = j;
				map->cur_y = i;
			}
		}
	}
	map->cur_char = '0';
	if (count == 1)
		return (1);
	return (0);
}

int	coin_check(t_map *map, char **visited)
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
			if (map->map_matrix[i][j] == 'C')
				count++;
			if (map->map_matrix[i][j] == 'C' && visited[i][j])
				col_count++;
		}
	}
	map->collectible = count;
	if (count == col_count && count)
		return (1);
	return (0);
}
