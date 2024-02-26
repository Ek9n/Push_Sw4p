/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:02:31 by hstein            #+#    #+#             */
/*   Updated: 2023/04/23 17:52:59 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

/*
	sa (swap a): Swap the first 2 elements at the top of stack a.
					Do nothing if there is only one or no elements.
	sb (swap b): Swap the first 2 elements at the top of stack b.
					Do nothing if there is only one or no elements.
	ss : sa and sb at the same time.
*/

int	swap_a(struct s_stack *stk, int silent)
{
	int	swapper;
	int	i;

	if (!stk)
		return (-1);
	if (stk->n < 2)
	{
		return (-1);
	}
	i = stk->n - 1;
	swapper = stk->arr[i - 1];
	stk->arr[i - 1] = stk->arr[i];
	stk->arr[i] = swapper;
	if (silent != 1)
		write(1, "sa\n", 3);
	return (0);
}

int	swap_b(struct s_stack *stk, int silent)
{
	int	swapper;
	int	i;

	if (!stk)
		return (-1);
	if (stk->n < 2)
	{
		return (-1);
	}
	i = stk->n - 1;
	swapper = stk->arr[i - 1];
	stk->arr[i - 1] = stk->arr[i];
	stk->arr[i] = swapper;
	if (silent != 1)
		write(1, "sb\n", 3);
	return (0);
}

int	swap_swap(struct s_stack *stk_a, struct s_stack *stk_b)
{
	if (!stk_a || !stk_b)
		return (-1);
	swap_a(stk_a, 1);
	swap_b(stk_b, 1);
	return (0);
}
