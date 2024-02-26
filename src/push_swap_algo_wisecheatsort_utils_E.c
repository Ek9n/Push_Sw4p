/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_wisecheatsort_utils_E.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:41:30 by hstein            #+#    #+#             */
/*   Updated: 2023/04/15 20:41:30 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_highest_index(int num, int *arr, int arr_len)
{
	int	i;
	int	next_highest_index;

	i = 0;
	next_highest_index = -1;
	while (i < arr_len)
	{
		if (arr[i] > num && (next_highest_index == -1 || \
				arr[i] < arr[next_highest_index]))
			next_highest_index = i;
		i++;
	}
	return (next_highest_index);
}

int	find_next_smallest_index(int num, int *arr, int arr_len)
{
	int	i;
	int	next_smallest_index;

	i = 0;
	next_smallest_index = -1;
	while (i < arr_len)
	{
		if (arr[i] < num && (next_smallest_index == -1 || \
				arr[i] > arr[next_smallest_index]))
			next_smallest_index = i;
		i++;
	}
	return (next_smallest_index);
}

int	calc_stps(struct s_ncalc *ncalculate)
{
	int	idx_nsmaller;
	int	idx_nhigher;
	int	i;

	i = ncalculate->nstats_a->n - 1;
	while (i >= 0)
	{
		idx_nsmaller = find_next_smallest_index(ncalculate->nstats_a->\
			numbers[i], ncalculate->nstats_b->numbers, ncalculate->nstats_b->n);
		ncalculate->best_move->idx_tomove_nsmaller[i] = idx_nsmaller;
		idx_nhigher = find_next_highest_index(ncalculate->nstats_a->numbers[i], \
			ncalculate->nstats_b->numbers, ncalculate->nstats_b->n);
		ncalculate->best_move->idx_tomove_nhigher[i] = idx_nhigher;
		calc_moves_nsmaller(ncalculate, i, idx_nsmaller);
		calc_moves_nhigher(ncalculate, i, idx_nhigher);
		i--;
	}
	return (0);
}

static void	check_nsmaller_2(struct s_ncalc *nc, struct s_fastestmove_vars *var)
{
	if (nc->moves_nsmaller_r_rr[var->i] < var->min_value && \
			nc->moves_nsmaller_r_rr[var->i] > -1)
	{
		var->min_value = nc->moves_nsmaller_r_rr[var->i];
		var->current_min_array = 3;
		var->min_index = var->i;
	}
	if (nc->moves_nsmaller_rr_r[var->i] < var->min_value && \
			nc->moves_nsmaller_rr_r[var->i] > -1)
	{
		var->min_value = nc->moves_nsmaller_rr_r[var->i];
		var->current_min_array = 4;
		var->min_index = var->i;
	}
}

void	check_nsmaller(struct s_ncalc *nc, struct s_fastestmove_vars *var)
{
	if (nc->moves_nsmaller_r_r[var->i] < var->min_value && \
			nc->moves_nsmaller_r_r[var->i] > -1)
	{
		var->min_value = nc->moves_nsmaller_r_r[var->i];
		var->current_min_array = 1;
		var->min_index = var->i;
	}
	if (nc->moves_nsmaller_rr_rr[var->i] < var->min_value && \
			nc->moves_nsmaller_rr_rr[var->i] > -1)
	{
		var->min_value = nc->moves_nsmaller_rr_rr[var->i];
		var->current_min_array = 2;
		var->min_index = var->i;
	}
	check_nsmaller_2(nc, var);
}
