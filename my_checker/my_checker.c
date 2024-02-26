/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:51:36 by hstein            #+#    #+#             */
/*   Updated: 2023/04/20 03:08:32 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

static int	execute_operation_2(\
				char *op, struct s_stack *stk_a, struct s_stack *stk_b)
{
	int	n;

	n = ft_strlen(op);
	if (!(op && stk_a && stk_b))
		return (-1);
	if (!ft_strncmp(op, "ra\n", n))
		rotate_a(stk_a, 1);
	else if (!ft_strncmp(op, "rb\n", n))
		rotate_b(stk_b, 1);
	else if (!ft_strncmp(op, "rr\n", n))
		rotate_rotate(stk_a, stk_b);
	else if (!ft_strncmp(op, "rra\n", n))
		rrotate_a(stk_a, 1);
	else if (!ft_strncmp(op, "rrb\n", n))
		rrotate_b(stk_b, 1);
	else if (!ft_strncmp(op, "rrr\n", n))
		rrotate_rrotate(stk_a, stk_b);
	else
		return (-1);
	return (1);
}

int	execute_operation(char *op, struct s_stack *stk_a, struct s_stack *stk_b)
{
	int	n;

	if (!(op && stk_a && stk_b))
		return (-1);
	n = ft_strlen(op);
	if (!ft_strncmp(op, "pa\n", n))
		push_a(stk_a, stk_b);
	else if (!ft_strncmp(op, "pb\n", n))
		push_b(stk_a, stk_b);
	else if (!ft_strncmp(op, "sa\n", n))
		swap_a(stk_a, 1);
	else if (!ft_strncmp(op, "sb\n", n))
		swap_b(stk_b, 1);
	else if (!ft_strncmp(op, "ss\n", n))
		swap_swap(stk_a, stk_b);
	else if (execute_operation_2(op, stk_a, stk_b) == -1)
		return (-1);
	return (0);
}

int	tryout_sort(struct s_stack *stk_a, struct s_stack *stk_b)
{
	char	*next_operation;

	next_operation = get_next_line(0);
	while (next_operation)
	{
		if (execute_operation(next_operation, stk_a, stk_b) == -1)
		{
			free(next_operation);
			return (-1);
		}
		free(next_operation);
		next_operation = get_next_line(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_stack	stack_a;
	struct s_stack	stack_b;

	if (argc < 2)
		return (0);
	if (buildstacks_multiinput(&stack_a, &stack_b, argc, argv) == 0 && \
			tryout_sort(&stack_a, &stack_b) == 0)
	{
		if (checksort(&stack_a) == 0 && stack_b.n == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (-1);
	}
	free(stack_a.arr);
	free(stack_b.arr);
	return (0);
}
