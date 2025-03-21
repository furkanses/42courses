/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 08:17:54 by fses              #+#    #+#             */
/*   Updated: 2024/12/08 08:17:57 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_putstr(char *a);
int	ft_printf(const char *a, ...);
int	ft_putchar(int a);
int	ft_hexadecimal(unsigned long int args, int a);
int	ft_putnbr(int n);
int	ft_adress(void *a);
int	ft_putnbr_unsigned(unsigned int b);

#endif