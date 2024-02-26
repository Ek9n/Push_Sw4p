/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_sorttriple.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:51:03 by hstein            #+#    #+#             */
/*   Updated: 2023/04/16 17:51:03 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorttriple(struct s_stack *stk_a)
{
	int	top;
	int	mid;
	int	bot;

	top = 2;
	mid = 1;
	bot = 0;
	if ((stk_a->arr[top] > stk_a->arr[mid] && \
			stk_a->arr[top] < stk_a->arr[bot]) || \
		(stk_a->arr[top] < stk_a->arr[mid] && \
			stk_a->arr[top] < stk_a->arr[bot]) || \
		((stk_a->arr[top] > stk_a->arr[mid] && \
			stk_a->arr[top] > stk_a->arr[bot]) && \
		(stk_a->arr[mid] > stk_a->arr[bot])))
		swap_a(stk_a, 0);
	if (stk_a->arr[top] > stk_a->arr[mid] && stk_a->arr[top] > stk_a->arr[bot])
		rotate_a(stk_a, 0);
	if (stk_a->arr[top] < stk_a->arr[mid] && stk_a->arr[top] > stk_a->arr[bot])
		rrotate_a(stk_a, 0);
	if (checksort(stk_a) != 0)
		return (0);
	return (1);
}
