/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algos_A.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:45:13 by hstein            #+#    #+#             */
/*   Updated: 2023/04/16 01:19:27 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheatsort(struct s_stack *stk_a, struct s_stack *stk_b)
{
	int	i;
	int	k;

	while (stk_a->n > 2)
	{
		i = idx_lowest(stk_a);
		k = (stk_a->n - i);
		if (k < i)
			while (k-- > 0)
				rrotate_a(stk_a, 0);
		else
			while (i-- > 0)
				rotate_a(stk_a, 0);
		push_b(stk_a, stk_b);
	}
	if (stk_a->arr[stk_a->n - 1] > stk_a->arr[0])
		swap_a(stk_a, 0);
	while (stk_b->n)
		push_a(stk_a, stk_b);
	return (0);
}

int	cheatsort_btoa(struct s_stack *stk_a, struct s_stack *stk_b)
{
	int	i;
	int	k;

	while (stk_b->n > 2)
	{
		i = idx_highest(stk_b);
		k = (stk_b->n - i);
		if (k < i)
			while (k-- > 0)
				rrotate_b(stk_b, 0);
		else
			while (i-- > 0)
				rotate_b(stk_b, 0);
		push_a(stk_a, stk_b);
	}
	if (stk_b->arr[stk_b->n - 1] < stk_b->arr[0])
		swap_b(stk_b, 0);
	while (stk_b->n)
		push_a(stk_a, stk_b);
	return (0);
}
