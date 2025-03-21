/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fses <fses@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:20:31 by fses              #+#    #+#             */
/*   Updated: 2025/02/24 11:10:24 by fses             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"

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
void			do_push_way1(t_list *list, int index_a, int index_b);
void			do_push_way2(t_list *list, int index_a, int index_b);
void			do_push_way3(t_list *list, int index_a, int index_b);
void			do_push_way4(t_list *list, int index_a, int index_b);
int				cheapest_way(int index_a, int index_b, int size_a, int size_b);
int				cheapest_way_cost(int index_a, int index_b, int size_a,
					int size_b);
void			do_cheapest_push_a(t_list *list);
void			do_cheapest_push_b(t_list *list);
void			sort_3(t_list *list);
long			ft_atoi(const char *str);
int				ft_isdigit(int c);
char			**ft_split(const char *s, char c);
void			ft_error(void);
void			ft_free_str(char **str);
int				check_args(int ac, char **av, int i);
int				is_sorted(t_list *list);
void			free_list(t_list *list);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			set_a(t_list *list, int ac, char **av);
int				size_stack(int ac, char **av);
int				is_all_whitespace(int ac, char **av);
char			*ft_strjoin_ps(char const *s1, char const *s2);
char			*join_arg(int ac, char **av);
size_t			ft_strlen_ps(const char *s);
char			*ft_strdup(char *src);
int				size_stack(int ac, char **av);
void			set_a(t_list *list, int ac, char **av);
int				ft_return(t_list *list, int gnl, int error, int free);

#endif