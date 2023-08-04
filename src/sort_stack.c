/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:20:56 by scespede          #+#    #+#             */
/*   Updated: 2023/08/03 04:28:00 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"
#include <stdio.h>

t_ilist	*sorting_stack(t_ilist *stack_a, t_ilist *stack_b)
{
	int		bit;
	int		count;
	t_ilist	*ptr;

	ptr = stack_a;
	bit = 1;
	while (is_sorted(&ptr) != 1)
	{
		count = count_stack(stack_a);
		while (count-- && ptr != NULL)
		{
			if (ptr->indi & bit)
				move_ra(&stack_a);
			else
				move_pb(&stack_a, &stack_b);
			ptr = stack_a;
		}
		while (stack_b)
			move_pa(&stack_a, &stack_b);
		ptr = stack_a;
		bit = bit << 1;
	}
	return (stack_a);
}

int	count_stack(t_ilist *stack_a)
{
	int	i;

	i = 0;
	while (stack_a != NULL)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int	is_sorted(t_ilist **stack_a)
{
	t_ilist	*ptr;

	ptr = *stack_a;
	while (ptr && ptr->next != NULL)
	{
		if (ptr->indi < ptr->next->indi)
			ptr = ptr->next;
		else
			return (0);
	}
	return (1);
}
