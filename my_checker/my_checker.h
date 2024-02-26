/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:52:14 by hstein            #+#    #+#             */
/*   Updated: 2023/04/16 23:52:14 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_CHECKER_H
# define MY_CHECKER_H

# include "get_next_line.h"
# include "../tempLibft/libft.h"
# include <limits.h>
# include <stdbool.h>

struct s_stack
{
	int	size;
	int	n;
	int	*arr;
};

// --Utils--

// Utils - Miscellaneous
int				fillstack_a(struct s_stack *stk, int n, char **splittedinput);
int				cntnumbers(char **splittedinput);
int				fillstack_a_multiinput(struct s_stack *stk, \
					int argc, char **argv);
int				buildstacks_multiinput(struct s_stack *stk_a, \
					struct s_stack *stk_b, int argc, char **argv);
int				idx_lowest(struct s_stack *stk);
int				idx_highest(struct s_stack *stk);
int				lowestnum(struct s_stack *stk);
void			printstack(struct s_stack *stk, char name);
int				checksort(struct s_stack *stk);
int				inputchecker(char *arr, int size);
int				checkinput(char **input, int nums);
int				check_no_duplicates(struct s_stack *stk);

// Utils - Operations
int				swap_a(struct s_stack *stk, int silent);
int				swap_b(struct s_stack *stk, int silent);
int				swap_swap(struct s_stack *stk_a, struct s_stack *stk_b);
int				push_b(struct s_stack *stk_a, struct s_stack *stk_b);
int				push_a(struct s_stack *stk_a, struct s_stack *stk_b);
int				rotate_a(struct s_stack *stk, int silent);
int				rotate_b(struct s_stack *stk, int silent);
int				rotate_rotate(struct s_stack *stk_a, struct s_stack *stk_b);
int				rrotate_a(struct s_stack *stk, int silent);
int				rrotate_b(struct s_stack *stk, int silent);
int				rrotate_rrotate(struct s_stack *stk_a, struct s_stack *stk_b);

#endif
