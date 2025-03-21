/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:43:50 by fses              #+#    #+#             */
/*   Updated: 2025/02/24 11:09:11 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheapest_way(int index_a, int index_b, int size_a, int size_b)
{
	int	way1;
	int	way2;
	int	way3;
	int	way4;

	if (index_a >= index_b)
		way1 = (index_a);
	else
		way1 = (index_b);
	if (size_a - index_a >= size_b - index_b)
		way2 = (size_a - index_a);
	else
		way2 = (size_b - index_b);
	way3 = index_a + size_b - index_b;
	way4 = index_b + size_a - index_a;
	if (way1 <= way2 && way1 <= way3 && way1 <= way4)
		return (1);
	if (way2 <= way1 && way2 <= way3 && way2 <= way4)
		return (2);
	if (way3 <= way2 && way3 <= way1 && way3 <= way4)
		return (3);
	if (way4 <= way2 && way4 <= way3 && way4 <= way1)
		return (4);
	return (0);
}

int	cheapest_way_cost(int index_a, int index_b, int size_a, int size_b)
{
	int	way1;
	int	way2;
	int	way3;
	int	way4;

	if (index_a >= index_b)
		way1 = (index_a);
	else
		way1 = (index_b);
	if (size_a - index_a >= size_b - index_b)
		way2 = (size_a - index_a);
	else
		way2 = (size_b - index_b);
	way3 = index_a + size_b - index_b;
	way4 = index_b + size_a - index_a;
	if (way1 <= way2 && way1 <= way3 && way1 <= way4)
		return (way1);
	if (way2 <= way1 && way2 <= way3 && way2 <= way4)
		return (way2);
	if (way3 <= way2 && way3 <= way1 && way3 <= way4)
		return (way3);
	if (way4 <= way2 && way4 <= way3 && way4 <= way1)
		return (way4);
	return (0);
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}

int	is_sorted(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->size_a - 1)
	{
		if (list->stack_a[i].data > list->stack_a[i + 1].data)
			break ;
		i++;
	}
	if (i == list->size_a - 1)
		return (1);
	else
		return (0);
}
