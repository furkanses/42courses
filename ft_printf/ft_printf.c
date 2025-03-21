/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 08:17:45 by fses              #+#    #+#             */
/*   Updated: 2024/12/10 21:52:40 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

static int	ft_checker(char a, va_list args, int *d)
{
	int	ret;

	ret = 0;
	if (a == '%')
		ret = ft_putchar('%');
	else if (a == 's')
		ret = ft_putstr(va_arg(args, char *));
	else if (a == 'c')
		ret = ft_putchar(va_arg(args, int));
	else if (a == 'p')
		ret = ft_adress(va_arg(args, void *));
	else if (a == 'd' || a == 'i')
		ret = ft_putnbr(va_arg(args, int));
	else if (a == 'u')
		ret = ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (a == 'x')
		ret = ft_hexadecimal(va_arg(args, unsigned int), 0);
	else if (a == 'X')
		ret = ft_hexadecimal(va_arg(args, unsigned int), 1);
	else
		ret = ft_putchar('%') + ft_putchar(a);
	if (ret == -1)
		return (-1);
	*d += ret;
	return (0);
}

static int	handle_format(const char *a, int *i, va_list args, int *d)
{
	int	ret;

	(*i)++;
	ret = ft_checker(a[*i], args, d);
	if (ret == -1)
		return (-1);
	return (ret);
}

static int	handle_char(const char c, int *d)
{
	int	ret;

	ret = ft_putchar(c);
	if (ret == -1)
		return (-1);
	*d += ret;
	return (0);
}

int	ft_printf(const char *a, ...)
{
	int		d;
	int		b;
	int		ret;
	va_list	args;

	d = 0;
	b = 0;
	if (a == NULL)
		return (ft_putstr("(null)"));
	va_start(args, a);
	while (a[b])
	{
		if (a[b] == '%')
			ret = handle_format(a, &b, args, &d);
		else
			ret = handle_char(a[b], &d);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		b++;
	}
	va_end(args);
	return (d);
}
