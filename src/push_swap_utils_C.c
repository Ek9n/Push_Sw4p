/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_C.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:40:13 by hstein            #+#    #+#             */
/*   Updated: 2023/04/16 00:40:13 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_no_duplicates(struct s_stack *stk)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < stk->n)
	{
		while (k < stk->n)
		{
			if (stk->arr[i] == stk->arr[k] && i != k)
				return (0);
			k++;
		}
		k = 0;
		i++;
	}
	return (1);
}

int	checkinput(char **input, int nums)
{
	int	i;

	i = 0;
	while (i < nums && inputchecker(input[i], ft_strlen(input[i])) == 0)
		i++;
	if (nums - i != 0)
	{
		ft_printf("(buildstacks) No valid input!\n");
		return (-1);
	}
	return (0);
}

int	inputchecker(char *arr, int size)
{
	int	i;

	if (!arr)
		return (-1);
	i = 0;
	if (arr[0] == '-' || arr[0] == '+')
		i++;
	while (arr[i] >= '0' && arr[i] <= '9')
		i++;
	if (i < size)
		return (-1);
	return (0);
}

int	*make_int_arr(const int *int_arr, const int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = int_arr[i];
		i++;
	}
	return (arr);
}

int	cntnumbers(char **splittedinput)
{
	int	cnt;

	cnt = 0;
	while (splittedinput[cnt])
		cnt++;
	return (cnt);
}
