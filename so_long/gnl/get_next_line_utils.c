/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:55:15 by fses              #+#    #+#             */
/*   Updated: 2025/03/13 21:20:03 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen_gnl(char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

static char	*ft_return(char *str)
{
	free(str);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (ft_return(s1));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	tmp = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!tmp)
		return (NULL);
	while (s1[++i])
		tmp[i] = s1[i];
	while (s2[++j])
		tmp[i + j] = s2[j];
	tmp[i + j] = '\0';
	free(s1);
	return (tmp);
}
