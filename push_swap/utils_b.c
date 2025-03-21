/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:14:25 by fses              #+#    #+#             */
/*   Updated: 2025/02/24 11:09:16 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_target_b(int data_b, t_element *a, int size_a)
{
	int	min;
	int	i;
	int	target;

	min = 0;
	target = -1;
	i = 0;
	while (i < size_a)
	{
		if (a[i].data < a[min].data)
			min = i;
		if (a[i].data >= data_b && (target == -1 || a[i].data < a[target].data))
			target = i;
		i++;
	}
	if (target == -1)
		target = min;
	return (target);
}

static void	set_cost_b(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->size_b)
	{
		list->stack_b[i].cost = cheapest_way_cost(
				find_target_b(list->stack_b[i].data,
					list->stack_a, list->size_a), i, list->size_a,
				list->size_b);
		i++;
	}
}

static int	cheapest_push_b(t_list *list)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i < list->size_b)
	{
		if (list->stack_b[i].cost < list->stack_b[min].cost)
			min = i;
		i++;
	}
	return (min);
}

void	do_cheapest_push_b(t_list *list)
{
	int	min;
	int	way;
	int	mina;

	set_cost_b(list);
	min = cheapest_push_b(list);
	mina = find_target_b(list->stack_b[min].data, list->stack_a, list->size_a);
	way = cheapest_way(mina, min, list->size_a, list->size_b);
	if (way == 1)
		do_push_way1(list, mina, min);
	else if (way == 2)
		do_push_way2(list, mina, min);
	else if (way == 3)
		do_push_way3(list, mina, min);
	else if (way == 4)
		do_push_way4(list, mina, min);
	pa(list, 1);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
