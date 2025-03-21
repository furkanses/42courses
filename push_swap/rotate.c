/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:19:26 by fses              #+#    #+#             */
/*   Updated: 2025/02/18 08:42:53 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	rotate(t_element *stack_a, int sizea)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack_a[0].data;
	while (i < sizea - 1)
	{
		stack_a[i].data = stack_a[i + 1].data;
		i++;
	}
	stack_a[sizea - 1].data = tmp;
}

void	ra(t_list *t, int i)
{
	rotate(t->stack_a, (t->size_a));
	if (i)
		write(1, "ra\n", 3);
}

void	rb(t_list *t, int i)
{
	rotate(t->stack_b, (t->size_b));
	if (i)
		write(1, "rb\n", 3);
}

void	rr(t_list *t, int i)
{
	rotate(t->stack_a, (t->size_a));
	rotate(t->stack_b, (t->size_b));
	if (i)
		write(1, "rr\n", 3);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
}
