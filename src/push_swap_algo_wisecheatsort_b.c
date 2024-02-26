/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_wisecheatsort_b.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:04:56 by hstein            #+#    #+#             */
/*   Updated: 2023/04/15 19:04:56 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

void	freencalc(struct s_ncalc *ncalc)
{
	free(ncalc->nstats_a->numbers);
	free(ncalc->nstats_a->stps_totop_r);
	free(ncalc->nstats_a->stps_totop_rr);
	free(ncalc->nstats_a->stps_tobottom_r);
	free(ncalc->nstats_a->stps_tobottom_rr);
	free(ncalc->nstats_a);
	free(ncalc->nstats_b->numbers);
	free(ncalc->nstats_b->stps_totop_r);
	free(ncalc->nstats_b->stps_totop_rr);
	free(ncalc->nstats_b->stps_tobottom_r);
	free(ncalc->nstats_b->stps_tobottom_rr);
	free(ncalc->nstats_b);
	free(ncalc->moves_nsmaller_r_r);
	free(ncalc->moves_nsmaller_rr_rr);
	free(ncalc->moves_nsmaller_r_rr);
	free(ncalc->moves_nsmaller_rr_r);
	free(ncalc->moves_nhigher_r_r);
	free(ncalc->moves_nhigher_rr_rr);
	free(ncalc->moves_nhigher_r_rr);
	free(ncalc->moves_nhigher_rr_r);
	free(ncalc->best_move->idx_tomove_nsmaller);
	free(ncalc->best_move->idx_tomove_nhigher);
	free(ncalc->best_move);
	free(ncalc);
}

int	wisecheatsort_b(struct s_stack *stk_a, struct s_stack *stk_b)
{
	struct s_ncalc	*ncalculated;

	while (stk_b->n > 0)
	{
		ncalculated = ncalc_builder(stk_b, stk_a);
		if (!ncalculated)
		{
			ft_printf("(wisecheatsort) ptr: ncalculated is NULL!\n");
			return (-1);
		}
		init_nsteps(ncalculated->nstats_a);
		init_nsteps(ncalculated->nstats_b);
		calc_stps(ncalculated);
		set_fastestmove(ncalculated);
		do_best_move_b(stk_b, stk_a, ncalculated);
		freencalc(ncalculated);
	}
	endrotation_b(stk_a);
	return (0);
}
