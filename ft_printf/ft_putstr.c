/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 08:18:18 by fses              #+#    #+#             */
/*   Updated: 2024/12/08 08:18:20 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *a)
{
	int	d;
	int	ret;

	d = 0;
	if (a == 0)
		return (ft_putstr("(null)"));
	while (*a)
	{
		ret = ft_putchar(*a++);
		if (ret == -1)
			return (-1);
		d += ret;
	}
	return (d);
}
