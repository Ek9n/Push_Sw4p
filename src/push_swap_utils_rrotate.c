/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_rrotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:45:21 by hstein            #+#    #+#             */
/*   Updated: 2023/02/17 17:45:21 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	rra (reverse rotate a): Shift down all elements of stack a by 1.
								The last element becomes the first one.
	rrb (reverse rotate b): Shift down all elements of stack b by 1.
								The last element becomes the first one.
	rrr : rra and rrb at the same time.
*/

int	rrotate_a(struct s_stack *stk, int silent)
{
	int	swapper;
	int	i;

	if (!stk)
		return (-1);
	if (stk->n < 2)
	{
		ft_printf("(rrotate_a) Not enough elements in Stack_A!");
		return (-1);
	}
	swapper = stk->arr[0];
	i = 0;
	while (i < stk->n - 1)
	{
		stk->arr[i] = stk->arr[i + 1];
		i++;
	}
	stk->arr[stk->n - 1] = swapper;
	if (silent != 1)
		write(1, "rra\n", 4);
	return (0);
}

int	rrotate_b(struct s_stack *stk, int silent)
{
	int	swapper;
	int	i;

	if (!stk)
		return (-1);
	if (stk->n < 2)
	{
		ft_printf("(rrotate_b) Not enough elements in Stack_B!");
		return (-1);
	}
	swapper = stk->arr[0];
	i = 0;
	while (i < stk->n - 1)
	{
		stk->arr[i] = stk->arr[i + 1];
		i++;
	}
	stk->arr[stk->n - 1] = swapper;
	if (silent != 1)
		write(1, "rrb\n", 4);
	return (0);
}

int	rrotate_rrotate(struct s_stack *stk_a, struct s_stack *stk_b)
{
	if (!stk_a || !stk_b)
		return (-1);
	rrotate_a(stk_a, 1);
	rrotate_b(stk_b, 1);
	write(1, "rrr\n", 4);
	return (0);
}
