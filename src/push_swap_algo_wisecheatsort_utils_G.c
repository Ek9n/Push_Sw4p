/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_wisecheatsort_utils_F.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:41:57 by hstein            #+#    #+#             */
/*   Updated: 2023/04/15 20:41:57 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_same_direction_nsmaller_b_2(struct s_stack *stk_a, \
				struct s_stack *stk_b, struct s_ncalc *calcmoves)
{
	if (calcmoves->best_move->array_number == 2)
	{
		while ((stk_a->arr[stk_a->n - 1] != calcmoves->nstats_a->numbers[\
				calcmoves->best_move->index]) && \
				(stk_b->arr[0] != calcmoves->nstats_b->\
				numbers[calcmoves->best_move->idx_tomove_nsmaller[calcmoves->\
				best_move->index]]))
			rrotate_rrotate(stk_a, stk_b);
		while (stk_a->arr[stk_a->n - 1] != calcmoves->nstats_a->numbers[\
				calcmoves->best_move->index])
			rrotate_b(stk_a, 0);
		while (stk_b->arr[0] != calcmoves->nstats_b->numbers[calcmoves->\
				best_move->idx_tomove_nsmaller[calcmoves->best_move->index]])
			rrotate_a(stk_b, 0);
	}
}

void	rotate_same_direction_nsmaller_b(struct s_stack *stk_a, \
			struct s_stack *stk_b, struct s_ncalc *calcmoves)
{
	if (!stk_a || !stk_b || !calcmoves)
		return ;
	if (calcmoves->best_move->array_number == 1)
	{
		while ((stk_a->arr[stk_a->n - 1] != calcmoves->nstats_a->\
				numbers[calcmoves->best_move->index]) && \
				(stk_b->arr[0] != calcmoves->nstats_b->\
				numbers[calcmoves->best_move->idx_tomove_nsmaller[calcmoves->\
				best_move->index]]))
			rotate_rotate(stk_a, stk_b);
		while (stk_a->arr[stk_a->n - 1] != calcmoves->nstats_a->\
				numbers[calcmoves->best_move->index])
			rotate_b(stk_a, 0);
		while (stk_b->arr[0] != calcmoves->nstats_b->numbers[calcmoves->\
				best_move->idx_tomove_nsmaller[calcmoves->best_move->index]])
			rotate_a(stk_b, 0);
	}
	rotate_same_direction_nsmaller_b_2(stk_a, stk_b, calcmoves);
}

static void	rotate_same_direction_nhigher_b_2(struct s_stack *stk_a, \
				struct s_stack *stk_b, struct s_ncalc *calcmoves)
{
	if (calcmoves->best_move->array_number == 6)
	{
		while ((stk_a->arr[stk_a->n - 1] != calcmoves->nstats_a->numbers[\
				calcmoves->best_move->index]) && (stk_b->arr[stk_b->n - 1] != \
				calcmoves->nstats_b->numbers[calcmoves->best_move->\
				idx_tomove_nhigher[calcmoves->best_move->index]]))
			rrotate_rrotate(stk_a, stk_b);
		while (stk_a->arr[stk_a->n - 1] != calcmoves->nstats_a->\
				numbers[calcmoves->best_move->index])
			rrotate_b(stk_a, 0);
		while (stk_b->arr[stk_b->n - 1] != calcmoves->nstats_b->numbers[\
				calcmoves->best_move->\
				idx_tomove_nhigher[calcmoves->best_move->index]])
			rrotate_a(stk_b, 0);
	}
}

void	rotate_same_direction_nhigher_b(struct s_stack *stk_a, \
			struct s_stack *stk_b, struct s_ncalc *calcmoves)
{
	if (!stk_a || !stk_b || !calcmoves)
		return ;
	if (calcmoves->best_move->array_number == 5)
	{
		while ((stk_a->arr[stk_a->n - 1] != calcmoves->nstats_a->\
				numbers[calcmoves->best_move->index]) && (stk_b->arr[\
				stk_b->n - 1] != calcmoves->nstats_b->numbers[calcmoves->\
				best_move->idx_tomove_nhigher[calcmoves->best_move->index]]))
			rotate_rotate(stk_a, stk_b);
		while (stk_a->arr[stk_a->n - 1] != calcmoves->nstats_a->\
				numbers[calcmoves->best_move->index])
			rotate_b(stk_a, 0);
		while (stk_b->arr[stk_b->n - 1] != calcmoves->nstats_b->numbers[\
				calcmoves->best_move->\
				idx_tomove_nhigher[calcmoves->best_move->index]])
			rotate_a(stk_b, 0);
	}
	rotate_same_direction_nhigher_b_2(stk_a, stk_b, calcmoves);
}
