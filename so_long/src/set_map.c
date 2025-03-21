/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:17:11 by fses              #+#    #+#             */
/*   Updated: 2025/03/13 21:42:41 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	is_all_ws(const char *str)
{
	int	i;
	int	l;

	l = 0;
	i = -1;
	while (str[++i])
		if (str[i] == ' ' || str[i] == '\n' || (str[i] <= '\r'
				&& str[i] >= '\t'))
			l++;
	if (l == (int)ft_strlen(str))
		return (1);
	return (0);
}

static char	*skip_ws(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str && is_all_ws(str))
	{
		free(str);
		str = get_next_line(fd);
	}
	return (str);
}

static int	ft_return(int fd, int ret, char *str)
{
	close(fd);
	if (str)
		free(str);
	get_next_line(-1);
	return (ret);
}

static void	set_size_y(t_map *map, const char *path)
{
	int		y;
	char	*str;
	int		fd;

	y = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		if (!is_all_ws(str))
			y++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	map->size_y = y;
}

int	set_map(t_map *map, const char *file)
{
	int		fd;
	char	*str;
	int		i;

	set_size_y(map, file);
	if (map->size_y < 3)
		return (-1);
	map->map_matrix = (char **)ft_calloc(sizeof(char *), map->size_y);
	if (map->map_matrix == NULL)
		return (free_matrix(map->map_matrix, 0));
	fd = open(file, O_RDONLY);
	i = -1;
	str = skip_ws(fd);
	while (++i < map->size_y)
	{
		if (is_all_ws(str))
			return (ft_return(fd, -1, str));
		map->map_matrix[i] = ft_strdup(str);
		if (map->map_matrix[i] == NULL)
			return (ft_return(fd, 0, "0"));
		free(str);
		str = get_next_line(fd);
	}
	return (ft_return(fd, 1, str));
}
