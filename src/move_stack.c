/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:13:06 by scespede          #+#    #+#             */
/*   Updated: 2023/08/03 04:29:02 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	move_ra(t_ilist **stack_a)
{
	t_ilist	*ptr;
	t_ilist	*save;

	ptr = *stack_a;
	if (ptr && !(ptr->next == NULL))
	{
		save = *stack_a;
		ptr = ptr->next;
		save->next = NULL;
		*stack_a = ptr;
		ft_lsitadd_back(&ptr, save);
		write(1, "ra\n", 3);
	}
	return (1);
}

int	move_rra(t_ilist **stack_a)
{
	t_ilist	*ptr;
	t_ilist	*save;

	ptr = *stack_a;
	while (ptr && ptr->next->next != NULL)
		ptr = ptr->next;
	save = ptr->next;
	ptr->next = NULL;
	save->next = *stack_a;
	*stack_a = save;
	write(1, "rra\n", 4);
	return (1);
}

int	move_pb(t_ilist **stack_a, t_ilist **stack_b)
{
	t_ilist	*a;

	a = *stack_a;
	*stack_a = a->next;
	a->next = *stack_b;
	*stack_b = a;
	write(1, "pb\n", 3);
	return (1);
}

int	move_pa(t_ilist **stack_a, t_ilist **stack_b)
{
	t_ilist	*b;

	b = *stack_b;
	*stack_b = b->next;
	b->next = *stack_a;
	*stack_a = b;
	write(1, "pa\n", 3);
	return (1);
}

int	move_sa(t_ilist **stack_a)
{
	t_ilist	*tmp;
	t_ilist	*ptr;

	ptr = *stack_a;
	tmp = ptr->next;
	ptr->next = ptr->next->next;
	tmp->next = ptr;
	*stack_a = tmp;
	write(1, "sa\n", 3);
	return (1);
}
