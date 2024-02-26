/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:39:19 by hstein            #+#    #+#             */
/*   Updated: 2023/04/23 17:52:53 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

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
		return (-1);
	}
	if (stk_a->n == stk_a->size)
	{
		return (-1);
	}
	stk_a->arr[stk_a->n++] = stk_b->arr[stk_b->n-- - 1];
	return (0);
}

int	push_b(struct s_stack *stk_a, struct s_stack *stk_b)
{
	if (!stk_a || !stk_b)
		return (-1);
	if (stk_a->n < 1)
	{
		return (-1);
	}
	if (stk_b->n == stk_b->size)
	{
		return (-1);
	}
	stk_b->arr[stk_b->n++] = stk_a->arr[stk_a->n-- - 1];
	return (0);
}
