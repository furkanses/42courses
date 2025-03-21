/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:19:20 by fses              #+#    #+#             */
/*   Updated: 2025/02/24 11:09:33 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_element *stack_a)
{
	int	tmp;

	tmp = stack_a[0].data;
	stack_a[0].data = stack_a[1].data;
	stack_a[1].data = tmp;
}

void	sa(t_list *t, int i)
{
	swap(t->stack_a);
	if (i)
		write(1, "sa\n", 3);
}

void	sb(t_list *t, int i)
{
	swap(t->stack_b);
	if (i)
		write(1, "sa\n", 3);
}

void	ss(t_list *t, int i)
{
	swap(t->stack_a);
	swap(t->stack_b);
	if (i)
		write(1, "ss\n", 3);
}

char	*ft_strdup(char *src)
{
	int		s;
	char	*dest;
	int		i;

	i = -1;
	s = ft_strlen_ps(src);
	dest = (char *)malloc(sizeof(char) * (s + 1));
	if (dest == NULL)
		return (NULL);
	while (++i < s)
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}
