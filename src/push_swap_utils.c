/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 00:04:29 by scespede          #+#    #+#             */
/*   Updated: 2023/08/03 00:29:00 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include "../include/ft_push_swap.h" 

int	*ft_atoi2(char *str, int *num)
{
	int				count;
	int				resta;
	long long int	nbr;

	nbr = 0;
	resta = 0 ;
	count = 0;
	if (str[count] == '-')
	{
		count++;
		resta++;
	}
	else if (str[count] == '+')
		count++;
	while (str[count] && str[count] >= '0' && str[count] <= '9')
	{
		nbr = nbr * 10 + str[count] - '0';
		if (nbr > ((long long int)INT_MAX + 1) && resta == 1)
			return (NULL);
		if (nbr > INT_MAX && resta == 0)
			return (NULL);
		count++;
	}
	return (num);
}

int	ft_maxint(t_ilist **lst)
{
	int		i;
	t_ilist	*ptr;

	ptr = *lst;
	i = INT_MIN;
	while (ptr)
	{
		if (ptr->num > i && ptr->indi == -1)
			i = ptr->num;
		ptr = ptr->next;
	}
	return (i);
}

int	ft_checklist(t_ilist **lst)
{
	t_ilist	*ptr;

	ptr = *lst;
	while (ptr)
	{
		if (ptr->indi == -1)
			return (-1);
		ptr = ptr->next;
	}
	return (1);
}
