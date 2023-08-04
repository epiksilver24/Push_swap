/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ilist_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 00:26:25 by scespede          #+#    #+#             */
/*   Updated: 2023/08/03 04:30:21 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_lstadd_back2(t_ilist **lst, t_ilist *new)
{
	t_ilist	*ptr;

	ptr = *lst;
	if (*lst)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	else
		*lst = new;
}

t_ilist	*ft_lsitnew(int content)
{
	t_ilist	*newnode;

	newnode = malloc(sizeof(*newnode));
	if (!newnode)
		return (NULL);
	newnode->num = content;
	newnode->indi = -1;
	newnode->next = NULL;
	return (newnode);
}

void	ft_addindi(t_ilist **lst, int size)
{
	int		min;
	t_ilist	*ptr;

	ptr = *lst;
	min = ft_maxint(lst);
	while (ptr)
	{
		if (ptr->indi == -1)
			if (ptr->num == min)
				ptr->indi = size;
		ptr = ptr->next;
	}
	if (ft_checklist(lst) == -1)
		ft_addindi(lst, (size - 1));
}

void	ft_lsitadd_back(t_ilist **lst, t_ilist *new)
{
	t_ilist	*ptr;

	ptr = *lst;
	if (*lst)
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new;
	}
	else
		*lst = new;
}

int	ft_lsitsize(t_ilist *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
