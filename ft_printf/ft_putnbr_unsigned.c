/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 08:18:07 by fses              #+#    #+#             */
/*   Updated: 2024/12/08 08:18:09 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int b)
{
	int	a;

	a = 0;
	if (b > 9)
	{
		a += ft_putnbr_unsigned(b / 10);
		a += ft_putnbr_unsigned(b % 10);
	}
	else if (b < 10)
		a += ft_putchar('0' + b);
	return (a);
}
