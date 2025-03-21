/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:43:35 by fses              #+#    #+#             */
/*   Updated: 2025/02/24 11:10:53 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

static int	move_check(char *str)
{
	if (ft_strncmp(str, "pb\n", 3) == 0 || ft_strncmp(str, "pa\n", 3) == 0
		|| ft_strncmp(str, "sa\n", 3) == 0 || ft_strncmp(str, "ss\n", 3) == 0
		|| ft_strncmp(str, "sb\n", 3) == 0 || ft_strncmp(str, "ra\n", 3) == 0
		|| ft_strncmp(str, "rb\n", 3) == 0 || ft_strncmp(str, "rr\n", 3) == 0
		|| ft_strncmp(str, "rra\n", 4) == 0 || ft_strncmp(str, "rrb\n", 4) == 0
		|| ft_strncmp(str, "rrr\n", 4) == 0)
		return (1);
	else
		return (0);
}

static void	move(char *str, t_list *list)
{
	if (ft_strncmp(str, "sa\n", 3) == 0 && list->size_a > 1)
		sa(list, 0);
	else if (ft_strncmp(str, "sb\n", 3) == 0 && list->size_b > 1)
		sb(list, 0);
	else if (ft_strncmp(str, "ss\n", 3) == 0 && list->size_b > 1
		&& list->size_a > 1)
		ss(list, 0);
	else if (ft_strncmp(str, "pa\n", 3) == 0 && list->size_b > 0)
		pa(list, 0);
	else if (ft_strncmp(str, "pb\n", 3) == 0 && list->size_a > 0)
		pb(list, 0);
	else if (ft_strncmp(str, "ra\n", 3) == 0 && list->size_a > 0)
		ra(list, 0);
	else if (ft_strncmp(str, "rb\n", 3) == 0 && list->size_b > 0)
		rb(list, 0);
	else if (ft_strncmp(str, "rr\n", 3) == 0 && list->size_a > 0
		&& list->size_b > 0)
		rr(list, 0);
	else if (ft_strncmp(str, "rra\n", 4) == 0 && list->size_a > 0)
		rra(list, 0);
	else if (ft_strncmp(str, "rrb\n", 4) == 0 && list->size_b > 0)
		rrb(list, 0);
	else if (ft_strncmp(str, "rrr\n", 4) == 0 && list->size_b > 0
		&& list->size_a > 0)
		rrr(list, 0);
}

static int	checker(t_list *list)
{
	char	*input;

	while (1)
	{
		input = get_next_line(0);
		if (input == NULL)
		{
			get_next_line(-1);
			return (1);
		}
		if (move_check(input) == 0)
		{
			free(input);
			return (0);
		}
		move(input, list);
		free(input);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		size;
	t_list	*list;

	size = size_stack(ac, av);
	if (ac == 1 || is_all_whitespace(ac, av) || check_args(ac, av, -1) == 0)
	{
		if (ac != 1)
			ft_error();
		return (0);
	}
	list = ft_calloc(sizeof(t_list), 1);
	list->stack_a = ft_calloc(sizeof(t_element), size);
	list->stack_b = ft_calloc(sizeof(t_element), size);
	if (list == NULL || list->stack_a == NULL || list->stack_b == NULL)
		return (ft_return(list, -2, 0, 1));
	set_a(list, ac, av);
	if (checker(list) == 0)
		return (ft_return(list, -1, 1, 1));
	if (is_sorted(list) && list ->size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(list);
}
