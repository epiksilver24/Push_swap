/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_tini.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:45:18 by scespede          #+#    #+#             */
/*   Updated: 2023/08/03 04:29:27 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	stack_1(t_ilist **stack_a)
{
	t_ilist	*ptr;

	ptr = *stack_a;
	if (ptr->num > ptr->next->num)
	{
		move_ra(&ptr);
	}
	return (1);
}

//int	stack_2(t_ilist **stack_a)
//{
//	t_ilist	*ptr;
//
//	ptr = *stack_a;
//	if (ptr->num > ptr->next->num && ptr->num > ptr->next->next->num)
//	{
//		move_ra(&ptr);
//		if (ptr->num > ptr->next->num)
//			move_sa(&ptr);
//	}
//	else if (ptr->next->num > ptr->num && ptr->next->num > ptr->next->next->num)
//	{
//		move_ra(&ptr);
//		move_ra(&ptr);
//		if (ptr->num > ptr->next->num)
//			move_sa(&ptr);
//	}
//	else
//	{
//		if (ptr->num > ptr->next->num)
//			move_sa(&ptr);
//	}
//	return (1);
//}

int	stack_2(t_ilist **a)
{
	if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num)
	{
		move_ra(a);
		if ((*a)->num > (*a)->next->num)
			move_sa(a);
	}
	else if ((*a)->next->num > (*a)->num && \
			(*a)->next->num > (*a)->next->next->num)
	{
		move_ra(a);
		move_ra(a);
		if ((*a)->num > (*a)->next->num)
			move_sa(a);
	}
	else
	{
		if ((*a)->num > (*a)->next->num)
			move_sa(a);
	}
	return (1);
}

int	stack_3(t_ilist **a)
{
	t_ilist	*ptr2;

	while ((*a)->indi != 1)
		move_ra(a);
	move_pb(a, &ptr2);
	stack_2(a);
	move_pa(a, &ptr2);
	return (1);
}

int	stack_4(t_ilist **a)
{
	t_ilist	*ptr2;

	if ((*a)->next->next->next->next->indi == 1)
		move_rra(a);
	else if ((*a)->next->next->next->indi == 1)
	{
		move_rra(a);
		move_rra(a);
	}
	while ((*a)->indi != 1)
		move_ra(a);
	move_pb(a, &ptr2);
	while ((*a)->indi != 2)
		move_ra(a);
	move_pb(a, &ptr2);
	stack_2(a);
	move_pa(a, &ptr2);
	move_pa(a, &ptr2);
	return (1);
}
