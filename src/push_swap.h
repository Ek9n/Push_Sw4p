/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:20:43 by hstein            #+#    #+#             */
/*   Updated: 2023/02/15 17:20:43 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Includes:

# include "../tempLibft/libft.h"
# include <limits.h>
# include <stdbool.h>

// Struct prototypes:

struct s_stack
{
	int	size;
	int	n;
	int	*arr;
};

struct s_nstats
{
	int	n;
	int	*numbers;
	int	*stps_totop_r;
	int	*stps_totop_rr;
	int	*stps_tobottom_r;
	int	*stps_tobottom_rr;
};

struct s_solution
{
	int	index;
	int	array_number;
	int	*idx_tomove_nsmaller;
	int	*idx_tomove_nhigher;
};

struct s_ncalc
{
	struct s_nstats		*nstats_a;
	struct s_nstats		*nstats_b;
	struct s_solution	*best_move;
	int					n;
	int					*moves_nsmaller_r_r;
	int					*moves_nsmaller_rr_rr;
	int					*moves_nsmaller_r_rr;
	int					*moves_nsmaller_rr_r;
	int					*moves_nhigher_r_r;
	int					*moves_nhigher_rr_rr;
	int					*moves_nhigher_r_rr;
	int					*moves_nhigher_rr_r;
};

struct s_lowerlimit3_vars
{
	int	*arr;
	int	idx_max;
	int	j;
	int	cnt_digits;
	int	lownum;
	int	idx_lownum;
	int	swapper;
};

struct s_fastestmove_vars
{
	int	min_index;
	int	min_value;
	int	i;
	int	current_min_array;
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

// --Algorythms--

int				sorttriple(struct s_stack *stk_a);
int				cheatsort(struct s_stack *stk_a, struct s_stack *stk_b);
int				cheatsort_atob(struct s_stack *stk_a, struct s_stack *stk_b);
int				cheatsort_btoa(struct s_stack *stk_a, struct s_stack *stk_b);
int				whichissort(struct s_stack *stk_a, struct s_stack *stk_b);

// Algorythms - Supersort()

int				lowerlimit3(\
					const int *int_arr, const int size, const int devisor);
int				*make_int_arr(\
					const int *int_arr, const int size);
int				supersort(\
					struct s_stack *stk_a, struct s_stack *stk_b, int divisor);

// Algorythms - Wisecheatsort()

struct s_nstats	*nstats_builder(const struct s_stack *stk);
struct s_ncalc	*ncalc_builder(\
					const struct s_stack *stk_a, const struct s_stack *stk_b);

int				wisecheatsort(struct s_stack *stk_a, struct s_stack *stk_b);
int				wisecheatsort_b(struct s_stack *stk_a, struct s_stack *stk_b);
void			printintarr(int *arr, int size, char *prefix);
void			intarrcpy(const int *src, int *dest, int size);
void			ft_bsubst(int *s, size_t n, int subst);
void			init_nstats(struct s_nstats *new_nstats);
int				free_nstats(struct s_nstats *new_nstats);
void			init_ncalc(struct s_ncalc *new_ncalc);
int				free_ncalc(struct s_ncalc *new_ncalc);
void			*alloc_member_ncalc(struct s_ncalc *new_ncalc, \
					const struct s_stack *stk_a, const struct s_stack *stk_b);
int				init_nsteps(struct s_nstats *calcnstats);
int				calc_moves_nsmaller(struct s_ncalc *ncalculate, \
					int idx_number, int idx_nsmaller);
int				calc_moves_nhigher(struct s_ncalc *ncalculate, \
					int idx_number, int idx_nhigher);
int				find_next_highest_index(int num, int *arr, int arr_len);
int				find_next_smallest_index(int num, int *arr, int arr_len);
int				calc_stps(struct s_ncalc *ncalculate);
void			check_nsmaller(struct s_ncalc *nc, \
					struct s_fastestmove_vars *var);
void			check_nhigher(struct s_ncalc *nc, \
					struct s_fastestmove_vars *var);
int				set_fastestmove(struct s_ncalc *nc);

// .. specialialized for wisecheatsort_b()
void			rotate_same_direction_nsmaller_b(struct s_stack *stk_a, \
					struct s_stack *stk_b, struct s_ncalc *calcmoves);
void			rotate_same_direction_nhigher_b(struct s_stack *stk_a, \
					struct s_stack *stk_b, struct s_ncalc *calcmoves);
void			rotate_counter_direction_nsmaller_b(struct s_stack *stk_a, \
					struct s_stack *stk_b, struct s_ncalc *calcmoves);
void			rotate_counter_direction_nhigher_b(struct s_stack *stk_a, \
					struct s_stack *stk_b, struct s_ncalc *calcmoves);
void			do_best_move_b(struct s_stack *stk_a, \
					struct s_stack *stk_b, struct s_ncalc *calcmoves);
int				endrotation_b(struct s_stack *stk);

#endif