/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 08:17:36 by fses              #+#    #+#             */
/*   Updated: 2024/12/08 08:17:39 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned long int args, int a)
{
	char	*e;
	int		d;

	d = 0;
	e = "0123456789abcdef";
	if (a == 1)
		e = "0123456789ABCDEF";
	if (args >= 16)
		d += ft_hexadecimal(args / 16, a);
	d += ft_putchar(e[args % 16]);
	return (d);
}
