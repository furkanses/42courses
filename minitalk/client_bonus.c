/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:34:58 by fses              #+#    #+#             */
/*   Updated: 2025/02/24 15:23:00 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_signal_massage(int sig)
{
	(void)sig;
	write(1, "Yazdim\n", 7);
	exit(0);
}

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

void	ft_send_pid(int pid_s, int pid_c)
{
	int	i;

	i = 31;
	while (i--)
	{
		if ((pid_c >> i) & 1)
			kill(pid_s, SIGUSR1);
		else
			kill(pid_s, SIGUSR2);
		usleep(1000);
	}
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
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(1000);
	}
}

int	main(int argc, char **av)
{
	int	pid;

	if (argc == 3)
	{
		signal(SIGUSR1, ft_signal_massage);
		pid = ft_atoi(av[1]);
		if (pid < 0)
			return (write(1, "PID negatif olmamalı\n", 21), 0);
		ft_send_pid(pid, getpid());
		ft_sendbit(pid, av[2]);
		pause();
	}
	else
		return (write(1, "./client PID <string> formatinda olmali!\n", 41), 0);
	return (0);
}
