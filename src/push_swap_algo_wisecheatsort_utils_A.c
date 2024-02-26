/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_wisecheatsort_utils_A.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:37:38 by hstein            #+#    #+#             */
/*   Updated: 2023/04/15 20:37:38 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printintarr(int *arr, int size, char *prefix)
{
	ft_printf("%s", prefix);
	while (size--)
		ft_printf(" %d", arr[size]);
	ft_printf("\n");
}

void	intarrcpy(const int *src, int *dest, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

void	ft_bsubst(int *s, size_t n, int subst)
{
	size_t	i;

	i = 0;
	while (i < n)
		s[i++] = subst;
}
