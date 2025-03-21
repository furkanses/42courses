/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:35:05 by fses              #+#    #+#             */
/*   Updated: 2025/02/21 11:54:10 by fses             ###   ########.fr       */
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

void	ft_handle(int sig)
{
	static int	a = 128;
	static char	c = 0;

	if (sig == SIGUSR1)
		c += a;
	a = a / 2;
	if (a == 0)
	{
		write(1, &c, 1);
		a = 128;
		c = 0;
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
