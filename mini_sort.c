/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:32:27 by gmentat           #+#    #+#             */
/*   Updated: 2020/02/28 22:51:11 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		two_sort(t_intlist *a, t_str *str_r)
{
	swap_arr(a);
	print_step(str_r, "sa\n");
}

static void		rot_sort(t_intlist *a, t_str *str_r)
{
	rotate_arr(a);
	print_step(str_r, "ra\n");
}

static void		rev_rot_sort(t_intlist *a, t_str *str_r)
{
	rev_rotate_arr(&a);
	print_step(str_r, "rra\n");
}

static void		ez_rot_sort(t_intlist *a, t_str *str_r)
{
	two_sort(a, str_r);
	rot_sort(a, str_r);
}

void			mini_sort(t_intlist *a, t_str *str_r)
{
	if (length_stack(a) == 2 && a->val > a->next->val)
		two_sort(a, str_r);
	else if (length_stack(a) == 3)
	{
		if (a->val > a->next->val && a->next->val > a->next->next->val &&
			a->next->next->val < a->val)
		{
			two_sort(a, str_r);
			rev_rot_sort(a, str_r);
		}
		else if (a->val > a->next->val && a->next->val < a->next->next->val &&
			a->next->next->val < a->val)
			rot_sort(a, str_r);
		else if (a->val > a->next->val && a->next->val < a->next->next->val &&
			a->next->next->val > a->val)
			two_sort(a, str_r);
		else if (a->val < a->next->val && a->next->val > a->next->next->val &&
			a->next->next->val > a->val)
			ez_rot_sort(a, str_r);
		else if (a->val < a->next->val && a->next->val > a->next->next->val &&
			a->next->next->val < a->val)
			rev_rot_sort(a, str_r);
	}
}
