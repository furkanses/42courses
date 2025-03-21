/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:10:39 by fses              #+#    #+#             */
/*   Updated: 2025/02/24 11:08:40 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push_way1(t_list *list, int index_a, int index_b)
{
	int	i;

	i = 0;
	while (i < index_a || i < index_b)
	{
		if (i < index_a && i < index_b)
			rr(list, 1);
		else if (i < index_a)
			ra(list, 1);
		else if (i < index_b)
			rb(list, 1);
		i++;
	}
}

void	do_push_way2(t_list *list, int index_a, int index_b)
{
	int	i;
	int	rindex_a;
	int	rindex_b;

	rindex_a = list->size_a - index_a;
	rindex_b = list->size_b - index_b;
	i = 0;
	while (i < rindex_a || i < rindex_b)
	{
		if (i < rindex_a && i < rindex_b)
			rrr(list, 1);
		else if (i < rindex_a)
			rra(list, 1);
		else if (i < rindex_b)
			rrb(list, 1);
		i++;
	}
}

void	do_push_way3(t_list *list, int index_a, int index_b)
{
	int	i;
	int	rindex_b;

	rindex_b = list->size_b - index_b;
	i = 0;
	while (i < index_a || i < rindex_b)
	{
		if (i < index_a)
			ra(list, 1);
		if (i < rindex_b)
			rrb(list, 1);
		i++;
	}
}

void	do_push_way4(t_list *list, int index_a, int index_b)
{
	int	i;
	int	rindex_a;

	rindex_a = list->size_a - index_a;
	i = 0;
	while (i < rindex_a || i < index_b)
	{
		if (i < rindex_a)
			rra(list, 1);
		if (i < index_b)
			rb(list, 1);
		i++;
	}
}

void	free_list(t_list *list)
{
	if (list->stack_a != NULL)
		free(list->stack_a);
	if (list->stack_b != NULL)
		free(list->stack_b);
	if (list != NULL)
		free(list);
}
