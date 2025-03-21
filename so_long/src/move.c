/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:52:04 by fses              #+#    #+#             */
/*   Updated: 2025/03/10 17:14:49 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move1(t_map *map)
{
	char	tmp;

	if (map->map_matrix[map->cur_y + 1][map->cur_x] == '1')
		return (0);
	tmp = map->map_matrix[map->cur_y + 1][map->cur_x];
	map->map_matrix[map->cur_y + 1][map->cur_x] = 'P';
	if (map->cur_char != 'E')
		map->map_matrix[map->cur_y][map->cur_x] = '0';
	else
		map->map_matrix[map->cur_y][map->cur_x] = 'E';
	map->cur_char = tmp;
	if (map->cur_char == 'C')
		map->collectible--;
	map->cur_y++;
	return (1);
}

static int	move2(t_map *map)
{
	char	tmp;

	if (map->map_matrix[map->cur_y][map->cur_x + 1] == '1')
		return (0);
	tmp = map->map_matrix[map->cur_y][map->cur_x + 1];
	map->map_matrix[map->cur_y][map->cur_x + 1] = 'P';
	if (map->cur_char != 'E')
		map->map_matrix[map->cur_y][map->cur_x] = '0';
	else
		map->map_matrix[map->cur_y][map->cur_x] = 'E';
	map->cur_char = tmp;
	if (map->cur_char == 'C')
		map->collectible--;
	map->cur_x++;
	return (1);
}

static int	move3(t_map *map)
{
	char	tmp;

	if (map->map_matrix[map->cur_y - 1][map->cur_x] == '1')
		return (0);
	tmp = map->map_matrix[map->cur_y - 1][map->cur_x];
	map->map_matrix[map->cur_y - 1][map->cur_x] = 'P';
	if (map->cur_char != 'E')
		map->map_matrix[map->cur_y][map->cur_x] = '0';
	else
		map->map_matrix[map->cur_y][map->cur_x] = 'E';
	map->cur_char = tmp;
	if (map->cur_char == 'C')
		map->collectible--;
	map->cur_y--;
	return (1);
}

static int	move4(t_map *map)
{
	char	tmp;

	if (map->map_matrix[map->cur_y][map->cur_x - 1] == '1')
		return (0);
	tmp = map->map_matrix[map->cur_y][map->cur_x - 1];
	map->map_matrix[map->cur_y][map->cur_x - 1] = 'P';
	if (map->cur_char != 'E')
		map->map_matrix[map->cur_y][map->cur_x] = '0';
	else
		map->map_matrix[map->cur_y][map->cur_x] = 'E';
	map->cur_char = tmp;
	if (map->cur_char == 'C')
		map->collectible--;
	map->cur_x--;
	return (1);
}

int	move(t_map *map, int move)
{
	if (move == 1)
		return (move1(map));
	else if (move == 2)
		return (move2(map));
	else if (move == 3)
		return (move3(map));
	return (move4(map));
}
