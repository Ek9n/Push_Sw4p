/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:05:08 by hstein            #+#    #+#             */
/*   Updated: 2023/04/15 19:05:08 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	run_algorythm(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (checksort(stack_a) != 0)
	{
		if (stack_a->n == 3)
			sorttriple(stack_a);
		else if (stack_a->n <= 12)
			cheatsort(stack_a, stack_b);
		else if (stack_a->n <= 100)
		{
			while (stack_a->n > 0)
				push_b(stack_a, stack_b);
			wisecheatsort_b(stack_a, stack_b);
		}
		else
		{
			supersort(stack_a, stack_b, 3);
			wisecheatsort_b(stack_a, stack_b);
		}
	}
	if (checksort(stack_a) != 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_stack	stack_a;
	struct s_stack	stack_b;

	if (argc < 2)
		return (0);
	if (buildstacks_multiinput(&stack_a, &stack_b, argc, argv) == -1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (-1);
	}
	run_algorythm(&stack_a, &stack_b);
	free(stack_a.arr);
	free(stack_b.arr);
	return (0);
}
	// printstack(&stack_a, 'a');
	// printstack(&stack_b, 'b');
