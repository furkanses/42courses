/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 08:18:13 by fses              #+#    #+#             */
/*   Updated: 2024/12/08 08:18:15 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long int	a;
	int			b;

	b = 0;
	a = n;
	if (a == 0)
	{
		b += ft_putchar('0');
		return (1);
	}
	if (a < 0)
	{
		b += ft_putchar('-');
		a *= -1;
	}
	if (a > 9)
	{
		b += ft_putnbr(a / 10);
		b += ft_putnbr(a % 10);
	}
	else if (a <= 9)
		b += ft_putchar(a + '0');
	return (b);
}
