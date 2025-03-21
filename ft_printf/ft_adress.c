/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 08:17:28 by fses              #+#    #+#             */
/*   Updated: 2024/12/08 14:26:13 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_adress(void *a)
{
	int				d;
	unsigned long	f;

	d = 0;
	f = (unsigned long)a;
	if (!f)
		return (ft_putstr("(nil)"));
	d += ft_putchar('0');
	d += ft_putchar('x');
	d += ft_hexadecimal(f, 'x');
	return (d);
}
