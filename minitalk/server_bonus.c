/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:35:05 by fses              #+#    #+#             */
/*   Updated: 2025/02/21 12:43:13 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putnbr(int n)
{
	long	num;

	num = n;
	if (num < 10)
	{
		num += 48;
		write(1, &num, 1);
	}
	else
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
}

char	handle_message(int sig)
{
	static int	a = 128;
	static char	c = 0;
	char		temp;

	if (sig == SIGUSR1)
		c += a;
	a /= 2;
	if (a == 0)
	{
		temp = c;
		write(1, &c, 1);
		a = 128;
		c = 0;
		return (temp);
	}
	return (-1);
}

void	ft_handle(int sig)
{
	static int	pid_count = 1073741824;
	static int	pid_c = 0;
	char		c;

	if (pid_count)
	{
		if (sig == SIGUSR1)
			pid_c += pid_count;
		pid_count /= 2;
		return ;
	}
	c = handle_message(sig);
	if (c == -1)
		return ;
	if (c == 0)
	{
		kill(pid_c, SIGUSR1);
		pid_count = 1073741824;
		pid_c = 0;
	}
}

int	main(int argc, char **av)
{
	(void)av;
	if (argc != 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	write(1, "PID:", 4);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, ft_handle);
	signal(SIGUSR2, ft_handle);
	while (1)
		;
	return (0);
}
