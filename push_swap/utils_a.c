/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:12:43 by fses              #+#    #+#             */
/*   Updated: 2025/02/24 11:09:22 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_target_a(int data_a, t_element *b, int size_b)
{
	int	max;
	int	i;
	int	target;

	max = 0;
	target = -1;
	i = 0;
	while (i < size_b)
	{
		if (b[i].data > b[max].data)
			max = i;
		if (b[i].data <= data_a && (target == -1 || b[i].data > b[target].data))
			target = i;
		i++;
	}
	if (target == -1)
		target = max;
	return (target);
}

static void	set_cost_a(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->size_a)
	{
		list->stack_a[i].cost = cheapest_way_cost(i,
				find_target_a(list->stack_a[i].data, list->stack_b,
					list->size_b), list->size_a, list->size_b);
		i++;
	}
}

static int	cheapest_push_a(t_list *list)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i < list->size_a)
	{
		if (list->stack_a[i].cost < list->stack_a[min].cost)
			min = i;
		i++;
	}
	return (min);
}

void	do_cheapest_push_a(t_list *list)
{
	int	min;
	int	way;
	int	minb;

	set_cost_a(list);
	min = cheapest_push_a(list);
	minb = find_target_a(list->stack_a[min].data, list->stack_b, list->size_b);
	way = cheapest_way(min, minb, list->size_a, list->size_b);
	if (way == 1)
		do_push_way1(list, min, minb);
	else if (way == 2)
		do_push_way2(list, min, minb);
	else if (way == 3)
		do_push_way3(list, min, minb);
	else if (way == 4)
		do_push_way4(list, min, minb);
	pb(list, 1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, (count * size));
	return (ptr);
}
