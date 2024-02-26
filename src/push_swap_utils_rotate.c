/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:14:58 by hstein            #+#    #+#             */
/*   Updated: 2023/04/16 01:09:36 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	ra (rotate a): Shift up all elements of stack a by 1.
					The first element becomes the last one. 1 2 3 -> 2 3 1
	rb (rotate b): Shift up all elements of stack b by 1.
					The first element becomes the last one.
	rr : ra and rb at the same time.
*/

int	rotate_a(struct s_stack *stk, int silent)
{
	int	swapper;
	int	i;

	if (!stk)
		return (-1);
	if (stk->n < 2)
	{
		ft_printf("(rotate_a) Not enough elements in Stack_A!");
		return (-1);
	}
	i = stk->n - 1;
	swapper = stk->arr[i];
	while (i > 0)
	{
		stk->arr[i] = stk->arr[i - 1];
		i--;
	}
	stk->arr[0] = swapper;
	if (silent != 1)
		write(1, "ra\n", 3);
	return (0);
}
// int	rotate_a(struct s_stack *stk, int silent)
// {
// 	int	swapper;
// 	int	i = stk->n - 1;

// 	if (!stk)
// 		return (-1);
// 	if(stk->n < 2)
// 	{
// 		ft_printf("(rotate_a) Not enough elements in Stack_A!");
// 		return (-1);
// 	}
// 	swapper = stk->arr[i];
// 	while (i >= 0)
// 	{
// 		stk->arr[i] = stk->arr[i - 1];
// 		i--;
// 	}
// 	stk->arr[0] = swapper;
// 	if (silent != 1)
// 		write(1, "ra\n", 3);
// 	return (0);
// }
int	rotate_b(struct s_stack *stk, int silent)
{
	int	swapper;
	int	i;

	if (!stk)
		return (-1);
	if (stk->n < 2)
	{
		ft_printf("(rotate_b) Not enough elements in Stack_B!");
		return (-1);
	}
	i = stk->n - 1;
	swapper = stk->arr[i];
	while (i >= 0)
	{
		stk->arr[i] = stk->arr[i - 1];
		i--;
	}
	stk->arr[0] = swapper;
	if (silent != 1)
		write(1, "rb\n", 3);
	return (0);
}

int	rotate_rotate(struct s_stack *stk_a, struct s_stack *stk_b)
{
	if (!stk_a || !stk_b)
		return (-1);
	rotate_a(stk_a, 1);
	rotate_b(stk_b, 1);
	write(1, "rr\n", 3);
	return (0);
}
