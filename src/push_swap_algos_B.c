/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algos_B.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:15:13 by hstein            #+#    #+#             */
/*   Updated: 2023/04/16 01:18:59 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lowerlimit3_2(struct s_lowerlimit3_vars *var, \
				const int size, const int devisor)
{
	while (var->cnt_digits < size / devisor)
	{
		var->lownum = var->arr[0];
		var->idx_lownum = var->j;
		while (var->j <= var->idx_max)
		{
			if (var->lownum > var->arr[var->j])
			{
				var->lownum = var->arr[var->j];
				var->idx_lownum = var->j;
			}
			var->j++;
		}
		var->swapper = var->arr[var->idx_max];
		var->arr[var->idx_max] = var->lownum;
		var->arr[var->idx_lownum] = var->swapper;
		var->j = 0;
		var->idx_max--;
		var->cnt_digits++;
	}
}

int	lowerlimit3(const int *int_arr, const int size, const int devisor)
{
	struct s_lowerlimit3_vars	var;

	var.arr = make_int_arr(int_arr, size);
	if (!var.arr)
		return (-1);
	var.idx_max = size - 1;
	var.j = 0;
	var.cnt_digits = 0;
	if (devisor < 1)
	{
		ft_printf("(lowerlimit3) Devisor < 1!!!\n");
		return (-1);
	}
	lowerlimit3_2(&var, size, devisor);
	free(var.arr);
	return (var.lownum);
}

static void	lowers_to_b3(struct s_stack *stk_a, \
				struct s_stack *stk_b, const int devisor)
{
	int	init_n;
	int	limit;
	int	cnt_pushed;
	int	i;

	init_n = stk_a->n;
	limit = lowerlimit3(stk_a->arr, stk_a->n, devisor);
	cnt_pushed = 0;
	i = 0;
	while (i < init_n)
	{
		if (stk_a->arr[stk_a->n - 1] <= limit)
		{
			push_b(stk_a, stk_b);
			cnt_pushed++;
			if (cnt_pushed == init_n / devisor)
				break ;
		}
		else if (stk_a->n > 1)
			rotate_a(stk_a, 0);
		i++;
	}
}

int	supersort(struct s_stack *stk_a, struct s_stack *stk_b, int divisor)
{
	int	i;

	i = 0;
	while (i++ < 1)
	{
		while (stk_a->n / divisor > 1)
			lowers_to_b3(stk_a, stk_b, divisor);
		while (stk_a->n)
			push_b(stk_a, stk_b);
	}
	return (0);
}
