/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_A.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:32:32 by hstein            #+#    #+#             */
/*   Updated: 2023/04/16 00:32:32 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fillstack_a(struct s_stack *stk, int n, char **splittedinput)
{
	int	i;

	i = 0;
	stk->n = n;
	while (i < stk->n)
	{
		stk->arr[i] = ft_atoi(splittedinput[n - 1]);
		i++;
		n--;
	}
	return (0);
}

static void	ft_atoi_plus_skipper(const char *nptr, int *i, int *sign)
{
	while (nptr[*i] == ' ' || (nptr[*i] >= 9 && nptr[*i] <= 13))
		*i += 1;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*sign = -1;
		*i += 1;
	}
}

static int	ft_atoi_plus(const char *nptr, bool *integer_flag)
{
	int		i;
	int		sign;
	size_t	result;

	sign = 1;
	result = 0;
	i = 0;
	ft_atoi_plus_skipper(nptr, &i, &sign);
	if (nptr[i] >= '0' && nptr[i] <= '9')
	{
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			result = 10 * result + (nptr[i] - 48);
			i++;
		}
		if ((sign == 1 && result <= 2147483647) || \
				(sign == -1 && result <= 2147483648))
			*integer_flag = 1;
	}
	return ((int)result * sign);
}

int	fillstack_a_multiinput(struct s_stack *stk, int argc, char **argv)
{
	bool	integer_flag;
	int		i;
	int		n;

	integer_flag = 0;
	n = argc - 1;
	i = 0;
	stk->n = n;
	while (i < argc - 1)
	{
		if (argv[n][0] == '\0' || \
				inputchecker(argv[n], ft_strlen(argv[n])) == -1)
			return (-1);
		stk->arr[i] = ft_atoi_plus(argv[n], &integer_flag);
		if (!integer_flag)
			return (-1);
		i++;
		n--;
	}
	return (0);
}

int	buildstacks_multiinput(struct s_stack *stk_a, \
		struct s_stack *stk_b, int argc, char **argv)
{
	if (!stk_a || !stk_b || !argv)
		return (-1);
	stk_a->arr = ft_calloc((argc - 1), sizeof(int));
	if (!stk_a->arr)
		return (-1);
	stk_b->arr = ft_calloc((argc - 1), sizeof(int));
	if (!stk_b->arr)
	{
		free(stk_a->arr);
		stk_a->arr = NULL;
		return (-1);
	}
	stk_a->size = argc - 1;
	stk_b->size = argc - 1;
	stk_a->n = 0;
	stk_b->n = 0;
	if (fillstack_a_multiinput(stk_a, argc, argv) == -1 || \
			!check_no_duplicates(stk_a))
	{
		free(stk_a->arr);
		free(stk_b->arr);
		return (-1);
	}
	return (0);
}
