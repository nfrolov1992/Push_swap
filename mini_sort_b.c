/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:30:52 by gmentat           #+#    #+#             */
/*   Updated: 2020/02/28 21:14:56 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		two_sort(t_intlist *a, t_str *str_r)
{
	swap_arr(a);
	print_step(str_r, "sb\n");
}

static void		rot_sort(t_intlist *a, t_str *str_r)
{
	rotate_arr(a);
	print_step(str_r, "rb\n");
}

static void		rev_rot_sort(t_intlist *a, t_str *str_r)
{
	rev_rotate_arr(&a);
	print_step(str_r, "rrb\n");
}

static void		ez_rot_sort(t_intlist *a, t_str *str_r)
{
	two_sort(a, str_r);
	rev_rot_sort(a, str_r);
}

void			mini_sort_b(t_intlist *a, int len, t_str *str_r)
{
	if (len == 2 && a->val > a->next->val)
		two_sort(a, str_r);
	else if (len == 3)
	{
		if (a->val < a->next->val && a->next->val < a->next->next->val &&
			a->next->next->val > a->val)
			ez_rot_sort(a, str_r);
		else if (a->val < a->next->val && a->next->val > a->next->next->val &&
			a->next->next->val > a->val)
			rot_sort(a, str_r);
		else if (a->val < a->next->val && a->next->val > a->next->next->val &&
			a->next->next->val < a->val)
			two_sort(a, str_r);
		else if (a->val > a->next->val && a->next->val < a->next->next->val &&
			a->next->next->val > a->val)
			rev_rot_sort(a, str_r);
		else if (a->val > a->next->val && a->next->val < a->next->next->val &&
			a->next->next->val < a->val)
		{
			rev_rot_sort(a, str_r);
			two_sort(a, str_r);
		}
	}
}
