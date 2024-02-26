/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_wisecheatsort_utils_C.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:39:57 by hstein            #+#    #+#             */
/*   Updated: 2023/04/15 20:39:57 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*alloc_member_ncalc(struct s_ncalc *new_ncalc, \
			const struct s_stack *stk_a, const struct s_stack *stk_b)
{
	if (!new_ncalc)
		return (NULL);
	new_ncalc->moves_nsmaller_r_r = malloc(stk_a->n * sizeof(int));
	new_ncalc->moves_nsmaller_rr_rr = malloc(stk_a->n * sizeof(int));
	new_ncalc->moves_nsmaller_r_rr = malloc(stk_a->n * sizeof(int));
	new_ncalc->moves_nsmaller_rr_r = malloc(stk_a->n * sizeof(int));
	new_ncalc->moves_nhigher_r_r = malloc(stk_a->n * sizeof(int));
	new_ncalc->moves_nhigher_rr_rr = malloc(stk_a->n * sizeof(int));
	new_ncalc->moves_nhigher_r_rr = malloc(stk_a->n * sizeof(int));
	new_ncalc->moves_nhigher_rr_r = malloc(stk_a->n * sizeof(int));
	new_ncalc->nstats_a = nstats_builder(stk_a);
	new_ncalc->nstats_b = nstats_builder(stk_b);
	new_ncalc->best_move = malloc(sizeof(struct s_solution));
	new_ncalc->best_move->idx_tomove_nsmaller = malloc(stk_a->n * sizeof(int));
	new_ncalc->best_move->idx_tomove_nhigher = malloc(stk_a->n * sizeof(int));
	return (new_ncalc);
}

struct s_ncalc	*ncalc_builder(const struct s_stack *stk_a, \
		const struct s_stack *stk_b)
{
	struct s_ncalc	*new_ncalc;

	if (!stk_a || !stk_b)
		return (NULL);
	new_ncalc = malloc(sizeof(struct s_ncalc));
	alloc_member_ncalc(new_ncalc, stk_a, stk_b);
	if (!(new_ncalc->moves_nsmaller_r_r && new_ncalc->moves_nsmaller_rr_rr && \
			new_ncalc->moves_nsmaller_r_rr && \
			new_ncalc->moves_nsmaller_rr_r && new_ncalc->nstats_a && \
			new_ncalc->nstats_b && \
			new_ncalc->moves_nhigher_r_r && new_ncalc->moves_nhigher_rr_rr && \
			new_ncalc->moves_nhigher_r_rr && \
			new_ncalc->moves_nhigher_rr_r && new_ncalc->best_move && \
			new_ncalc->best_move->idx_tomove_nsmaller && \
			new_ncalc->best_move->idx_tomove_nhigher))
	{
		free_ncalc(new_ncalc);
		return (NULL);
	}
	new_ncalc->n = stk_a->n;
	init_ncalc(new_ncalc);
	return (new_ncalc);
}

int	init_nsteps(struct s_nstats *calcnstats)
{
	int	i;
	int	j;

	if (!calcnstats)
		return (-1);
	i = 0;
	j = calcnstats->n - 1;
	while (i < calcnstats->n)
	{
		calcnstats->stps_totop_r[i] = j;
		calcnstats->stps_totop_rr[i] = i + 1;
		calcnstats->stps_tobottom_r[i] = j + 1;
		calcnstats->stps_tobottom_rr[i] = i;
		i++;
		j--;
	}
	if (calcnstats->n > 0)
	{
		calcnstats->stps_totop_rr[calcnstats->n - 1] = 0;
		calcnstats->stps_tobottom_r[0] = 0;
	}
	return (0);
}
