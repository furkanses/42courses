/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:43:58 by fses              #+#    #+#             */
/*   Updated: 2025/02/24 11:11:52 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include "get_next_line/get_next_line.h"
# include <unistd.h>

typedef struct s_element
{
	int			data;
	int			cost;
}				t_element;

typedef struct s_list
{
	t_element	*stack_a;
	t_element	*stack_b;
	int			size_a;
	int			size_b;
}				t_list;

void			pa(t_list *t, int i);
void			pb(t_list *t, int i);
void			ra(t_list *t, int i);
void			rb(t_list *t, int i);
void			rr(t_list *t, int i);
void			rra(t_list *t, int i);
void			rrb(t_list *t, int i);
void			rrr(t_list *t, int i);
void			sa(t_list *t, int i);
void			sb(t_list *t, int i);
void			ss(t_list *t, int i);
int				size_stack(int ac, char **av);
void			set_a(t_list *list, int ac, char **av);
void			free_list(t_list *list);
void			*ft_calloc(size_t count, size_t size);
void			ft_error(void);
int				is_sorted(t_list *list);
int				check_args(int ac, char **av, int i);
int				is_all_whitespace(int ac, char **av);
int				ft_return(t_list *list, int gnl, int error, int free);

#endif