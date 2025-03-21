/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:19:24 by fses              #+#    #+#             */
/*   Updated: 2025/02/24 11:10:19 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_element *stack_a, int sizea)
{
	int	tmp;
	int	i;

	i = sizea - 1;
	tmp = stack_a[sizea - 1].data;
	while (i)
	{
		stack_a[i].data = stack_a[i - 1].data;
		i--;
	}
	stack_a[0].data = tmp;
}

void	rra(t_list *t, int i)
{
	rrotate(t->stack_a, (t->size_a));
	if (i)
		write(1, "rra\n", 4);
}

void	rrb(t_list *t, int i)
{
	rrotate(t->stack_b, (t->size_b));
	if (i)
		write(1, "rrb\n", 4);
}

void	rrr(t_list *t, int i)
{
	rrotate(t->stack_a, (t->size_a));
	rrotate(t->stack_b, (t->size_b));
	if (i)
		write(1, "rrr\n", 4);
}

int	ft_return(t_list *list, int gnl, int error, int free)
{
	if (free)
		free_list(list);
	if (gnl == -1)
		get_next_line(-1);
	if (error)
		ft_error();
	return (0);
}
