/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:52:09 by fses              #+#    #+#             */
/*   Updated: 2025/03/13 21:42:33 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_put_move(int i)
{
	ft_putstr_fd("Number of moves : ", 1);
	ft_putnbr_fd(i, 1);
	ft_putchar_fd('\n', 1);
}

static int	key_hook(int keycode, t_main *main)
{
	static int	i = 0;

	if (keycode == 119 && move(main->map, 3) && ++i)
		ft_put_move(i);
	else if (keycode == 97 && move(main->map, 4) && ++i)
		ft_put_move(i);
	else if (keycode == 115 && move(main->map, 1) && ++i)
		ft_put_move(i);
	else if (keycode == 100 && move(main->map, 2) && ++i)
		ft_put_move(i);
	if (keycode == 65307 || (main->map->cur_char == 'E'
			&& main->map->collectible == 0))
	{
		if (main->map->cur_char == 'E' && main->map->collectible == 0)
			ft_putstr_fd("You won!\n", 1);
		return (free_main(main));
	}
	mlx_clear_window(main->window->mlx, main->window->win);
	set_win_map(main->map, main->window, -1, -1);
	return (0);
}

static int	key_release_hook(int keycode)
{
	(void)keycode;
	return (0);
}

static int	is_map_empty(char *file)
{
	int		fd;
	int		rd;
	char	*buffer;
	char	*path;

	path = ft_strjoin("maps/", file);
	buffer = malloc(5 * sizeof(char));
	if (!buffer)
		return (0);
	fd = open(path, O_RDONLY);
	rd = read(fd, buffer, 5);
	if (rd == 0)
	{
		ft_putstr_fd("Error\nInvalid map file!\n", 2);
		free(path);
		free(buffer);
		return (0);
	}
	free(path);
	free(buffer);
	return (1);
}

int	main(int ac, char **av)
{
	t_main	*main;

	main = (t_main *)ft_calloc(sizeof(t_main), 1);
	main->map = (t_map *)ft_calloc(sizeof(t_map), 1);
	main->window = (t_window *)ft_calloc(sizeof(t_window), 1);
	if (!main || !main->map || !main->window)
		return (free_main(main));
	if (!is_map_empty(av[1]) || !arg_check(ac, av) || !map_check(main->map,
			av[1]))
		return (free_main(main));
	main->window->mlx = mlx_init();
	if (!main->window->mlx)
		return (free_main(main));
	if (!set_image(main->window))
		return (free_main(main));
	main->window->win = mlx_new_window(main->window->mlx, main->map->size_x
			* 64, main->map->size_y * 64, "so_long");
	if (!main->window->win)
		return (free_main(main));
	set_win_map(main->map, main->window, -1, -1);
	mlx_hook(main->window->win, 17, 0, free_main, main);
	mlx_hook(main->window->win, 2, 1, key_hook, main);
	mlx_hook(main->window->win, 3, 2, key_release_hook, NULL);
	mlx_loop(main->window->mlx);
}
