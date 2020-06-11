/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:35:36 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/03 16:41:57 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		h_one(int mid, t_intlist *a)
{
	while (a)
	{
		if (mid == a->index)
		{
			mid = a->val;
			break ;
		}
		a = a->next;
	}
	return (mid);
}

static void		h_two(int len, t_intlist **a, t_intlist **b, t_str *str_r)
{
	while (length_stack(*a) != 3)
	{
		push_arr(b, a);
		print_step(str_r, "pb\n");
		if ((*b)->val <= len)
		{
			rotate_arr(*b);
			print_step(str_r, "rb\n");
		}
	}
	mini_sort(*a, str_r);
}

static void		h_th(t_step *step, t_intlist *a, t_intlist *b, t_str *str_r)
{
	while (b)
	{
		b = sort_max(a, b);
		step = min_step_go(b);
		free_step(a, b);
		go_sort(step, &a, &b, str_r);
		free(step);
		step = NULL;
	}
	a = step_on_top_a(a);
	free_step(a, b);
	round_round(&a, str_r);
	ft_free_stack(a);
	a = NULL;
	free(b);
	b = NULL;
}

char			*sorted_index(t_intlist *a, t_str *str_r)
{
	int			len;
	t_intlist	*b;
	t_step		*step;

	b = NULL;
	step = NULL;
	len = length_stack(a);
	index_num(a);
	len = h_one((len / 2), a);
	if (length_stack(a) > 3)
	{
		h_two(len, &a, &b, str_r);
		mini_sort(a, str_r);
		h_th(step, a, b, str_r);
	}
	else if (length_stack(a) <= 3)
		mini_sort(a, str_r);
	return (str_r->str);
}
