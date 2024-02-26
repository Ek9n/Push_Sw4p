/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:39:19 by hstein            #+#    #+#             */
/*   Updated: 2023/04/15 21:50:51 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	pa (push a): Take the first element at the top of b and put it at the top of a.
					Do nothing if b is empty.
	pb (push b): Take the first element at the top of a and put it at the top of b.
					Do nothing if a is empty.
*/

int	push_a(struct s_stack *stk_a, struct s_stack *stk_b)
{
	if (!stk_a || !stk_b)
		return (-1);
	if (stk_b->n < 1)
	{
		ft_printf("(push_a) Can't push, not enough elements in Stack_B!\n");
		return (-1);
	}
	if (stk_a->n == stk_a->size)
	{
		ft_printf("(push_a) Can't push, stack_A is full!\n");
		return (-1);
	}
	stk_a->arr[stk_a->n++] = stk_b->arr[stk_b->n-- - 1];
	write(1, "pa\n", 3);
	return (0);
}

int	push_b(struct s_stack *stk_a, struct s_stack *stk_b)
{
	if (!stk_a || !stk_b)
		return (-1);
	if (stk_a->n < 1)
	{
		ft_printf("(push_b) Can't push, not enough elements in Stack_A!\n");
		return (-1);
	}
	if (stk_b->n == stk_b->size)
	{
		ft_printf("(push_b) Can't push, stack_B is full!\n");
		return (-1);
	}
	stk_b->arr[stk_b->n++] = stk_a->arr[stk_a->n-- - 1];
	write(1, "pb\n", 3);
	return (0);
}
