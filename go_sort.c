/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:21:56 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/04 13:11:01 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		one_go(t_step *result, t_intlist **a, t_intlist **b,
						t_str *str_r)
{
	if (result->b_step > 0 && result->a_step > 0)
	{
		while (result->b_step > 0 || result->a_step > 0)
		{
			rr(*a, *b);
			print_step(str_r, "rr\n");
			result->b_step--;
			result->a_step--;
		}
	}
	else if (result->b_step < 0 && result->a_step < 0)
	{
		while (result->b_step < 0 || result->a_step < 0)
		{
			rrr(*a, *b);
			print_step(str_r, "rrr\n");
			result->b_step++;
			result->a_step++;
		}
	}
}

static void		two_go(t_step *result, t_intlist **a, t_intlist **b,
							t_str *str_r)
{
	if (result->b_step > 0)
	{
		while (result->b_step > 0)
		{
			rotate_arr(*b);
			print_step(str_r, "rb\n");
			result->b_step--;
		}
	}
	else if (result->a_step > 0)
	{
		while (result->a_step > 0)
		{
			rotate_arr(*a);
			print_step(str_r, "ra\n");
			result->a_step--;
		}
	}
}

static void		three_go(t_step *result, t_intlist **a, t_intlist **b,
							t_str *str_r)
{
	if (result->b_step < 0)
	{
		while (result->b_step < 0)
		{
			rev_rotate_arr(b);
			print_step(str_r, "rrb\n");
			result->b_step++;
		}
	}
	else if (result->a_step < 0)
	{
		while (result->a_step < 0)
		{
			rev_rotate_arr(a);
			print_step(str_r, "rra\n");
			result->a_step++;
		}
	}
}

void			go_sort(t_step *result, t_intlist **a, t_intlist **b,
							t_str *str_r)
{
	if ((result->b_step > 0 && result->a_step > 0) ||
	(result->b_step < 0 && result->a_step < 0))
		one_go(result, a, b, str_r);
	if ((result->b_step > 0) || (result->a_step > 0))
		two_go(result, a, b, str_r);
	if ((result->b_step < 0) || (result->a_step < 0))
		three_go(result, a, b, str_r);
	push_arr(a, b);
	print_step(str_r, "pa\n");
}
