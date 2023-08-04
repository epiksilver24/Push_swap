/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:28:41 by scespede          #+#    #+#             */
/*   Updated: 2023/08/03 00:18:28 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	free_stack(t_ilist **stack_a)
{
	t_ilist	*aux;
	t_ilist	*list;

	list = *stack_a;
	while (list)
	{
		aux = list->next;
		free(list);
		list = aux;
	}
	list = NULL;
}
