/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_wisecheatsort_utils_H.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:18:31 by hstein            #+#    #+#             */
/*   Updated: 2023/04/16 00:18:31 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_counter_direction_nsmaller_b(struct s_stack *stk_a, \
			struct s_stack *stk_b, struct s_ncalc *calcmoves)
{
	if (calcmoves->best_move->array_number == 3)
	{
		while (stk_a->arr[stk_a->n - 1] != \
				calcmoves->nstats_a->numbers[calcmoves->best_move->index])
			rotate_b(stk_a, 0);
		while (stk_b->arr[0] != calcmoves->nstats_b->numbers[calcmoves->\
				best_move->idx_tomove_nsmaller[calcmoves->best_move->index]])
			rrotate_a(stk_b, 0);
	}
	if (calcmoves->best_move->array_number == 4)
	{
		while (stk_a->arr[stk_a->n - 1] != \
				calcmoves->nstats_a->numbers[calcmoves->best_move->index])
			rrotate_b(stk_a, 0);
		while (stk_b->arr[0] != calcmoves->nstats_b->numbers[calcmoves->\
				best_move->idx_tomove_nsmaller[calcmoves->best_move->index]])
			rotate_a(stk_b, 0);
	}
}

void	rotate_counter_direction_nhigher_b(struct s_stack *stk_a, \
			struct s_stack *stk_b, struct s_ncalc *calcmoves)
{
	if (calcmoves->best_move->array_number == 7)
	{
		while (stk_a->arr[stk_a->n - 1] != \
				calcmoves->nstats_a->numbers[calcmoves->best_move->index])
			rotate_b(stk_a, 0);
		while (stk_b->arr[stk_b->n - 1] != calcmoves->nstats_b->numbers[\
				calcmoves->best_move->idx_tomove_nhigher[\
				calcmoves->best_move->index]])
			rrotate_a(stk_b, 0);
	}
	if (calcmoves->best_move->array_number == 8)
	{
		while (stk_a->arr[stk_a->n - 1] != \
				calcmoves->nstats_a->numbers[calcmoves->best_move->index])
			rrotate_b(stk_a, 0);
		while (stk_b->arr[stk_b->n - 1] != calcmoves->nstats_b->numbers[\
				calcmoves->best_move->idx_tomove_nhigher[\
				calcmoves->best_move->index]])
			rotate_a(stk_b, 0);
	}
}

void	do_best_move_b(struct s_stack *stk_a, struct s_stack *stk_b, \
			struct s_ncalc *calcmoves)
{
	if (calcmoves->best_move->array_number == 0)
		push_a(stk_b, stk_a);
	else if (calcmoves->best_move->array_number >= 1 \
		&& calcmoves->best_move->array_number <= 4)
	{
		rotate_same_direction_nsmaller_b(stk_a, stk_b, calcmoves);
		rotate_counter_direction_nsmaller_b(stk_a, stk_b, calcmoves);
		push_a(stk_b, stk_a);
	}
	else if (calcmoves->best_move->array_number >= 5 \
		&& calcmoves->best_move->array_number <= 8)
	{
		rotate_same_direction_nhigher_b(stk_a, stk_b, calcmoves);
		rotate_counter_direction_nhigher_b(stk_a, stk_b, calcmoves);
		push_a(stk_b, stk_a);
	}
}

int	endrotation_b(struct s_stack *stk)
{
	int	i;
	int	k;

	if (!stk)
		return (-1);
	i = idx_lowest(stk);
	k = (stk->n - i);
	if (k < i)
		while (k-- > 0)
			rrotate_a(stk, 0);
	else
		while (i-- > 0)
			rotate_a(stk, 0);
	return (0);
}
