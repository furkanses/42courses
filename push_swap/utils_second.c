/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:23:18 by fses              #+#    #+#             */
/*   Updated: 2025/02/24 11:09:04 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list *list)
{
	t_element	*a;
	int			min;
	int			c;

	c = 0;
	a = list->stack_a;
	if (list->size_a == 3)
	{
		if (a[0].data <= a[1].data && a[0].data <= a[2].data)
			min = 0;
		else if (a[1].data <= a[0].data && a[1].data <= a[2].data)
			min = 1;
		else
			min = 2;
		if (min == 1)
			rra(list, 1);
		else if (min == 0)
			ra(list, 1);
		c = 1;
	}
	if (list->stack_a[0].data > list->stack_a[1].data)
		sa(list, 1);
	if (c)
		rra(list, 1);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

size_t	ft_strlen_ps(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_ps(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen_ps(s1) + ft_strlen_ps(s2);
	result = (char *)malloc(len + 2);
	if (!result)
		return (NULL);
	i = -1;
	while (++i < ft_strlen_ps(s1))
		result[i] = s1[i];
	result[i] = ' ';
	i++;
	j = -1;
	while (++j < ft_strlen_ps(s2))
		result[i + j] = s2[j];
	result[i + j] = '\0';
	return (result);
}
