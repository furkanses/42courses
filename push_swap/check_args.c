/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:51:51 by fses              #+#    #+#             */
/*   Updated: 2025/02/24 11:11:02 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isrepeat(int num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	is_all_whitespace(int ac, char **av)
{
	int	j;
	int	i;
	int	l;

	j = 0;
	while (++j < ac)
	{
		l = 0;
		i = -1;
		if (!av[j] || av[j][0] == '\0')
			return (1);
		while (av[j][++i])
			if (av[j][i] == ' ' || (av[j][i] == '\t' && av[j][i] <= '\r'))
				l++;
		if (l == i)
			return (1);
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if ((num[0] == '+' || num[0] == '-') && num[1] == 0)
		return (0);
	else if (num[0] == '+' || num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*join_arg(int ac, char **av)
{
	char	*ret;
	char	*tmp;
	int		i;

	if (ac == 2)
	{
		ret = ft_strdup(av[1]);
		if ((ret) == NULL)
			return (NULL);
		else
			return (ret);
	}
	i = 2;
	ret = ft_strjoin_ps(av[1], av[2]);
	if (ret == NULL)
		return (NULL);
	while (++i < ac)
	{
		tmp = ret;
		ret = ft_strjoin_ps(tmp, av[i]);
		free(tmp);
		if (ret == NULL)
			return (NULL);
	}
	return (ret);
}

int	check_args(int ac, char **av, int i)
{
	long	num;
	char	**tab;
	char	*arg;

	arg = join_arg(ac, av);
	if (arg == NULL)
		return (0);
	tab = ft_split(arg, ' ');
	if (!tab)
		return (0);
	free(arg);
	while (tab[++i])
	{
		num = ft_atoi(tab[i]);
		if (!ft_isnum(tab[i]) || ft_isrepeat(num, tab, i) || num < -2147483648
			|| num > 2147483647)
		{
			ft_free_str(tab);
			return (0);
		}
	}
	ft_free_str(tab);
	return (1);
}
