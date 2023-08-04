/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 22:44:32 by scespede          #+#    #+#             */
/*   Updated: 2023/08/03 04:27:34 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	parseargv(char **tab)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (tab[i] != NULL)
	{
		if (ft_atoi2(tab[i], &num) == NULL)
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		if (check_nums(tab[i]) == -1)
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	check_nums(char *str)
{
	int	i;
	int	num;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		num = str[i];
		if (ft_isdigit(num) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	hasduplicated(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		j = i + 1;
		while (tab[j] != NULL)
		{
			if (ft_atoi(tab[j]) == ft_atoi(tab[i]))
			{
				write(1, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}
