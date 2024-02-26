/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_B.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:32:18 by hstein            #+#    #+#             */
/*   Updated: 2023/04/16 00:32:18 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

int	idx_lowest(struct s_stack *stk)
{
	int	i;
	int	lowest;
	int	idx;

	i = stk->n - 1;
	lowest = stk->arr[stk->n - 1];
	idx = 0;
	while (i >= 0)
	{
		if (lowest > stk->arr[i])
		{
			lowest = stk->arr[i];
			idx = (stk->n - 1) - i;
		}
		i--;
	}
	return (idx);
}

int	idx_highest(struct s_stack *stk)
{
	int	i;
	int	highest;
	int	idx;

	i = stk->n - 1;
	highest = stk->arr[stk->n - 1];
	idx = 0;
	while (i >= 0)
	{
		if (highest < stk->arr[i])
		{
			highest = stk->arr[i];
			idx = (stk->n - 1) - i;
		}
		i--;
	}
	return (idx);
}

int	lowestnum(struct s_stack *stk)
{
	int	i;
	int	lowest;

	i = stk->n - 1;
	lowest = stk->arr[stk->n - 1];
	while (i >= 0)
	{
		if (lowest > stk->arr[i])
			lowest = stk->arr[i];
		i--;
	}
	return (lowest);
}

void	printstack(struct s_stack *stk, char name)
{
	int	i;

	i = stk->n - 1;
	if (name == 'a')
		ft_printf("Stack_A:\n");
	else if (name == 'b')
		ft_printf("Stack_B:\n");
	else
		ft_printf("Invalid Stack!\n");
	while (i >= 0)
	{
		ft_printf("%i ", stk->arr[i]);
		i--;
	}
	ft_printf("\n");
}

int	checksort(struct s_stack *stk)
{
	int	i;

	if (!stk)
		return (-1);
	i = 0;
	while (i < stk->n)
	{
		if (stk->arr[i] < stk->arr[i + 1])
			break ;
		i++;
	}
	if (i < stk->n - 1)
		return (-1);
	return (0);
}
