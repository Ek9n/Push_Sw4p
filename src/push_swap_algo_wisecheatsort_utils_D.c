/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_wisecheatsort_utils_D.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:40:38 by hstein            #+#    #+#             */
/*   Updated: 2023/04/15 20:40:38 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calc_moves_nsmaller_2(struct s_ncalc *ncalculate, \
		int idx_number, int idx_nsmaller)
{
	if (ncalculate->nstats_a->stps_totop_r[idx_number] >= \
			ncalculate->nstats_b->stps_tobottom_r[idx_nsmaller])
		ncalculate->moves_nsmaller_r_r[idx_number] = \
			ncalculate->nstats_a->stps_totop_r[idx_number];
	else
		ncalculate->moves_nsmaller_r_r[idx_number] = \
			ncalculate->nstats_b->stps_tobottom_r[idx_nsmaller];
	if (ncalculate->nstats_a->stps_totop_rr[idx_number] >= \
			ncalculate->nstats_b->stps_tobottom_rr[idx_nsmaller])
		ncalculate->moves_nsmaller_rr_rr[idx_number] = \
			ncalculate->nstats_a->stps_totop_rr[idx_number];
	else
		ncalculate->moves_nsmaller_rr_rr[idx_number] = \
			ncalculate->nstats_b->stps_tobottom_rr[idx_nsmaller];
	ncalculate->moves_nsmaller_r_rr[idx_number] = \
		ncalculate->nstats_a->stps_totop_r[idx_number] + \
		ncalculate->nstats_b->stps_tobottom_rr[idx_nsmaller];
	ncalculate->moves_nsmaller_rr_r[idx_number] = \
		ncalculate->nstats_a->stps_totop_rr[idx_number] + \
		ncalculate->nstats_b->stps_tobottom_r[idx_nsmaller];
}

int	calc_moves_nsmaller(struct s_ncalc *ncalculate, \
		int idx_number, int idx_nsmaller)
{
	if (!ncalculate)
		return (-1);
	if (idx_nsmaller == -1)
	{
		ncalculate->moves_nsmaller_r_r[idx_number] = -1;
		ncalculate->moves_nsmaller_rr_rr[idx_number] = -1;
		ncalculate->moves_nsmaller_r_rr[idx_number] = -1;
		ncalculate->moves_nsmaller_rr_r[idx_number] = -1;
	}
	else
		calc_moves_nsmaller_2(ncalculate, idx_number, idx_nsmaller);
	return (0);
}

static void	calc_moves_nhigher_2(struct s_ncalc *ncalculate, \
		int idx_number, int idx_nhigher)
{
	if (ncalculate->nstats_a->stps_totop_r[idx_number] >= \
			ncalculate->nstats_b->stps_totop_r[idx_nhigher])
		ncalculate->moves_nhigher_r_r[idx_number] = \
			ncalculate->nstats_a->stps_totop_r[idx_number];
	else
		ncalculate->moves_nhigher_r_r[idx_number] = \
			ncalculate->nstats_b->stps_totop_r[idx_nhigher];
	if (ncalculate->nstats_a->stps_totop_rr[idx_number] >= \
			ncalculate->nstats_b->stps_totop_rr[idx_nhigher])
		ncalculate->moves_nhigher_rr_rr[idx_number] = ncalculate->\
			nstats_a->stps_totop_rr[idx_number];
	else
		ncalculate->moves_nhigher_rr_rr[idx_number] = ncalculate->\
			nstats_b->stps_totop_rr[idx_nhigher];
	ncalculate->moves_nhigher_r_rr[idx_number] = ncalculate->nstats_a->\
		stps_totop_r[idx_number] + ncalculate->nstats_b->\
		stps_totop_rr[idx_nhigher];
	ncalculate->moves_nhigher_rr_r[idx_number] = ncalculate->nstats_a->\
		stps_totop_rr[idx_number] + ncalculate->nstats_b->\
		stps_totop_r[idx_nhigher];
}

int	calc_moves_nhigher(struct s_ncalc *ncalculate, \
		int idx_number, int idx_nhigher)
{
	if (!ncalculate)
		return (-1);
	if (idx_nhigher == -1)
	{
		ncalculate->moves_nhigher_r_r[idx_number] = -1;
		ncalculate->moves_nhigher_rr_rr[idx_number] = -1;
		ncalculate->moves_nhigher_r_rr[idx_number] = -1;
		ncalculate->moves_nhigher_rr_r[idx_number] = -1;
	}
	else
		calc_moves_nhigher_2(ncalculate, idx_number, idx_nhigher);
	return (0);
}
