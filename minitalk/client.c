/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:34:58 by fses              #+#    #+#             */
/*   Updated: 2025/02/03 20:36:14 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	total;
	int	sign;

	sign = 1;
	total = 0;
	i = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		total = total * 10 + (str[i++] - 48);
	return (total * sign);
}

void	ft_sendbit(int pid, char *av)
{
	int	i;

	while (*av)
	{
		i = 8;
		while (i--)
		{
			if ((*av >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(1000);
		}
		av++;
	}
}

int	main(int argc, char **av)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 0)
			write(1, "PID negatif olmamalı\n", 21);
		ft_sendbit(pid, av[2]);
	}
	else
		write(1, "./client PID <string> formatinda olmali!\n", 41);
	return (0);
}
