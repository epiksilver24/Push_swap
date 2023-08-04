/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:56:36 by scespede          #+#    #+#             */
/*   Updated: 2023/08/03 04:30:04 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h" 

void	slect_order(t_ilist **stack_a, int size)
{
	t_ilist	*ptr;

	ptr = *stack_a;
	if (is_sorted(&ptr) != 1)
	{
		if (ptr->next->next == NULL)
			write(1, "sa\n", 3);
		else if (size == 3)
			stack_2(stack_a);
		else if (size == 4)
			stack_3(stack_a);
		else 
			stack_4(stack_a);
	}
}

int	main(int ac, char **av)
{
	int		in;
	t_ilist	*ptr;
	t_ilist	*ptr2;

	in = 1;
	if (ac > 1)
	{
		if ((parseargv(av + 1) == -1) || (hasduplicated (av + 1) == -1))
			return (0);
		ptr = ft_lsitnew(ft_atoi(av[in++]));
		while (av[in] != NULL)
		{
			ptr2 = ft_lsitnew(ft_atoi(av[in++]));
			ft_lsitadd_back(&ptr, ptr2);
		}
		ptr2 = NULL;
		ft_addindi(&ptr, ft_lsitsize(ptr));
		if (ft_lsitsize(ptr) <= 5)
			slect_order(&ptr, ft_lsitsize(ptr));
		else
			ptr = sorting_stack(ptr, ptr2);
		free_stack(&ptr);
	}
	return (0);
}
