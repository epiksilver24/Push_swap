/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:43:24 by scespede          #+#    #+#             */
/*   Updated: 2023/08/03 04:30:53 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# include "libft/libft.h"

typedef struct s_ilist
{
	int				num;
	int				indi;
	struct s_ilist	*next;
}	t_ilist;

t_ilist	*sorting_stack(t_ilist *stack_a, t_ilist *stack_b); 
t_ilist	*ft_lsitnew(int content);
int		parseargv(char **tab);
int		*ft_atoi2(char *str, int *num);
int		ft_lsitsize(t_ilist *lis);
int		hasduplicated(char **tab);
int		move_ra(t_ilist **stack_a);
int		move_rra(t_ilist **stack_a);
int		move_sa(t_ilist **stack_a);
int		move_pb(t_ilist **stack_a, t_ilist **stack_b);
int		move_pa(t_ilist **stack_a, t_ilist **stack_b);
int		is_sorted(t_ilist **stack_a);
int		check_nums(char *str);
int		count_stack(t_ilist *stack_a);
int		stack_1(t_ilist **stack_a);
int		stack_2(t_ilist **stack_a);
int		stack_3(t_ilist **stack_a);
int		stack_4(t_ilist **stack_a);
int		ft_maxint(t_ilist **lst);
int		ft_checklist(t_ilist **lst);
void	ft_lsitadd_back(t_ilist **lst, t_ilist *new);
void	ft_lsitadd_back2(t_ilist **lst, t_ilist *new);
void	free_stack(t_ilist **stack_a);
void	ft_addindi(t_ilist **lst, int size);
void	select_order(t_ilist **ptr, int size);
void	print_stack(t_ilist *stack_a);
#endif
