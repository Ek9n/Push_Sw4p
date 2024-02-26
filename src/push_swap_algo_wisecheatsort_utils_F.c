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

static void	check_nhigher_2(struct s_ncalc *nc, struct s_fastestmove_vars *var)
{
	if (nc->moves_nhigher_r_rr[var->i] < var->min_value && \
			nc->moves_nhigher_r_rr[var->i] > -1)
	{
		var->min_value = nc->moves_nhigher_r_rr[var->i];
		var->current_min_array = 7;
		var->min_index = var->i;
	}
	if (nc->moves_nhigher_rr_r[var->i] < var->min_value && \
			nc->moves_nhigher_rr_r[var->i] > -1)
	{
		var->min_value = nc->moves_nhigher_rr_r[var->i];
		var->current_min_array = 8;
		var->min_index = var->i;
	}
}

void	check_nhigher(struct s_ncalc *nc, struct s_fastestmove_vars *var)
{
	if (nc->moves_nhigher_r_r[var->i] < var->min_value && \
			nc->moves_nhigher_r_r[var->i] > -1)
	{
		var->min_value = nc->moves_nhigher_r_r[var->i];
		var->current_min_array = 5;
		var->min_index = var->i;
	}
	if (nc->moves_nhigher_rr_rr[var->i] < var->min_value && \
			nc->moves_nhigher_rr_rr[var->i] > -1)
	{
		var->min_value = nc->moves_nhigher_rr_rr[var->i];
		var->current_min_array = 6;
		var->min_index = var->i;
	}
	check_nhigher_2(nc, var);
}

int	set_fastestmove(struct s_ncalc *nc)
{
	struct s_fastestmove_vars	var;

	if (!nc)
		return (-1);
	var.min_index = -1;
	var.min_value = INT_MAX;
	var.i = nc->n - 1;
	var.current_min_array = 0;
	while (var.i >= 0)
	{
		check_nsmaller(nc, &var);
		check_nhigher(nc, &var);
		var.i--;
	}
	nc->best_move->index = var.min_index;
	nc->best_move->array_number = var.current_min_array;
	return (0);
}
