/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:19:30 by fses              #+#    #+#             */
/*   Updated: 2025/02/20 12:41:13 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static void	push(t_element *stack_a, int *sizea, t_element *stack_b, int *sizeb)
{
	int	i;

	i = *sizeb;
	while (i)
	{
		stack_b[i].data = stack_b[i - 1].data;
		i--;
	}
	stack_b[0].data = stack_a[0].data;
	i = 0;
	while (i < *sizea - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	++(*sizeb);
	--(*sizea);
}

void	pa(t_list *t, int i)
{
	push(t->stack_b, &(t->size_b), t->stack_a, &(t->size_a));
	if (i)
		write(1, "pa\n", 3);
}

void	pb(t_list *t, int i)
{
	push(t->stack_a, &(t->size_a), t->stack_b, &(t->size_b));
	if (i)
		write(1, "pb\n", 3);
}

int	size_stack(int ac, char **av)
{
	char	**tab;
	char	*arg;
	int		i;

	arg = join_arg(ac, av);
	if (arg == NULL)
		return (0);
	tab = ft_split(arg, ' ');
	if (!tab)
		return (0);
	free(arg);
	i = 0;
	while (tab[i])
		i++;
	ft_free_str(tab);
	return (i);
}

void	set_a(t_list *list, int ac, char **av)
{
	char	**tab;
	char	*arg;
	int		i;

	arg = join_arg(ac, av);
	if (arg == NULL)
		return ;
	tab = ft_split(arg, ' ');
	if (!tab)
		return ;
	free(arg);
	i = 0;
	while (tab[i])
	{
		list->stack_a[i].data = ft_atoi(tab[i]);
		list->size_a++;
		i++;
	}
	ft_free_str(tab);
}
