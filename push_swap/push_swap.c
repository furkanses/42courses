/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:19:44 by fses              #+#    #+#             */
/*   Updated: 2025/02/21 13:35:30 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_final_move(t_list *list)
{
	int	min;
	int	i;
	int	rmin;

	i = 0;
	min = 0;
	while (i < list->size_a)
	{
		if (list->stack_a[i].data < list->stack_a[min].data)
			min = i;
		i++;
	}
	rmin = list->size_a - min;
	i = 0;
	if (rmin < min)
		while (i++ < rmin)
			rra(list, 1);
	else
		while (i++ < min)
			ra(list, 1);
}

static void	push_swap(t_list *list)
{
	if (list->size_a > 3)
		pb(list, 1);
	while (list->size_a > 3)
		do_cheapest_push_a(list);
	sort_3(list);
	while (list->size_b)
		do_cheapest_push_b(list);
	do_final_move(list);
}

int	main(int ac, char **av)
{
	int		size;
	t_list	*list;

	if (ac == 1 || is_all_whitespace(ac, av) || check_args(ac, av, -1) == 0)
	{
		if (ac != 1)
			ft_error();
		return (0);
	}
	size = size_stack(ac, av);
	list = ft_calloc(sizeof(t_list), 1);
	list->stack_a = ft_calloc(sizeof(t_element), size);
	list->stack_b = ft_calloc(sizeof(t_element), size);
	if (list == NULL || list->stack_a == NULL || list->stack_b == NULL)
		return (ft_return(list, 0, 0, 1));
	set_a(list, ac, av);
	if (is_sorted(list))
		return (ft_return(list, 0, 0, 1));
	push_swap(list);
	free_list(list);
}
