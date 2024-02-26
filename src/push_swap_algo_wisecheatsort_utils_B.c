/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_wisecheatsort_utils_B.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:37:31 by hstein            #+#    #+#             */
/*   Updated: 2023/04/15 20:37:31 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nstats(struct s_nstats *new_nstats)
{
	if (!new_nstats)
	{
		ft_printf("(init_nstats) struct_ptr = NULL!\n");
		return ;
	}
	ft_bsubst(new_nstats->numbers, new_nstats->n, -1);
	ft_bsubst(new_nstats->stps_totop_r, new_nstats->n, -1);
	ft_bsubst(new_nstats->stps_totop_rr, new_nstats->n, -1);
	ft_bsubst(new_nstats->stps_tobottom_r, new_nstats->n, -1);
	ft_bsubst(new_nstats->stps_tobottom_rr, new_nstats->n, -1);
}

int	free_nstats(struct s_nstats *new_nstats)
{
	if (!new_nstats)
		return (-1);
	free(new_nstats->numbers);
	free(new_nstats->stps_totop_r);
	free(new_nstats->stps_totop_rr);
	free(new_nstats->stps_tobottom_r);
	free(new_nstats->stps_tobottom_rr);
	free(new_nstats);
	return (0);
}

struct s_nstats	*nstats_builder(const struct s_stack *stk)
{
	struct s_nstats	*new_nstats;

	if (!stk)
		return (NULL);
	new_nstats = malloc(sizeof(struct s_nstats));
	if (!new_nstats)
		return (NULL);
	new_nstats->numbers = malloc(stk->n * sizeof(int));
	new_nstats->stps_totop_r = malloc(stk->n * sizeof(int));
	new_nstats->stps_totop_rr = malloc(stk->n * sizeof(int));
	new_nstats->stps_tobottom_r = malloc(stk->n * sizeof(int));
	new_nstats->stps_tobottom_rr = malloc(stk->n * sizeof(int));
	if (!(new_nstats->numbers && new_nstats->stps_totop_r && new_nstats->\
			stps_totop_rr && new_nstats->stps_tobottom_r && \
			new_nstats->stps_tobottom_rr))
	{
		free_nstats(new_nstats);
		return (NULL);
	}
	new_nstats->n = stk->n;
	init_nstats(new_nstats);
	intarrcpy(stk->arr, new_nstats->numbers, stk->n);
	return (new_nstats);
}

void	init_ncalc(struct s_ncalc *new_ncalc)
{
	if (!new_ncalc)
	{
		ft_printf("(init_nalc) struct_ptr = NULL!\n");
		return ;
	}
	ft_bsubst(new_ncalc->moves_nsmaller_r_r, new_ncalc->n, -1);
	ft_bsubst(new_ncalc->moves_nsmaller_rr_rr, new_ncalc->n, -1);
	ft_bsubst(new_ncalc->moves_nsmaller_r_rr, new_ncalc->n, -1);
	ft_bsubst(new_ncalc->moves_nsmaller_rr_r, new_ncalc->n, -1);
	ft_bsubst(new_ncalc->moves_nhigher_r_r, new_ncalc->n, -1);
	ft_bsubst(new_ncalc->moves_nhigher_rr_rr, new_ncalc->n, -1);
	ft_bsubst(new_ncalc->moves_nhigher_r_rr, new_ncalc->n, -1);
	ft_bsubst(new_ncalc->moves_nhigher_rr_r, new_ncalc->n, -1);
	ft_bsubst(new_ncalc->best_move->idx_tomove_nsmaller, new_ncalc->n, -1);
	ft_bsubst(new_ncalc->best_move->idx_tomove_nhigher, new_ncalc->n, -1);
}

int	free_ncalc(struct s_ncalc *new_ncalc)
{
	if (!new_ncalc)
		return (-1);
	free(new_ncalc->moves_nsmaller_r_r);
	free(new_ncalc->moves_nsmaller_rr_rr);
	free(new_ncalc->moves_nsmaller_r_rr);
	free(new_ncalc->moves_nsmaller_rr_r);
	free(new_ncalc->moves_nhigher_r_r);
	free(new_ncalc->moves_nhigher_rr_rr);
	free(new_ncalc->moves_nhigher_r_rr);
	free(new_ncalc->moves_nhigher_rr_r);
	free(new_ncalc->best_move->idx_tomove_nsmaller);
	free(new_ncalc->best_move->idx_tomove_nhigher);
	free(new_ncalc->best_move);
	free(new_ncalc);
	return (0);
}
