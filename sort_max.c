/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:33:24 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/04 13:07:10 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct		s_sortex
{
	int				max;
	int				m;
	int				end;
	int				tmp_end;
}					t_sortex;

static int			he_one(t_intlist *a)
{
	while (a)
	{
		if (!a->next)
			return (a->val);
		a = a->next;
	}
	return (0);
}

static void			he_two(t_intlist *a, t_intlist *b, t_sortex p, int t)
{
	while (a)
	{
		if (b->val > p.max || b->val < p.m)
		{
			if (((a->val == p.max && p.end == p.m) || (a->val == p.m)) && ++t)
				b->step->a_step = a->step->a_step;
			else if (a->val == p.max && a->next->val == p.m && ++t)
				b->step->a_step = a->next->step->a_step;
		}
		else
		{
			if (((b->val > a->val && a->val != p.m && b->val < p.end) ||
				(b->val < a->val && b->val > p.end)) && ++t)
				b->step->a_step = a->step->a_step;
			else if (((b->val < a->val && b->val > a->next->val &&
				a->next->val != p.m) || (b->val > a->val &&
				b->val < a->next->val)) && ++t)
				b->step->a_step = a->next->step->a_step;
		}
		if (t == 1)
			break ;
		p.end = a->val;
		a = a->next;
	}
}

t_intlist			*sort_max(t_intlist *a, t_intlist *b)
{
	t_intlist		*tmp_a;
	t_intlist		*tmp_b;
	t_sortex		param;

	tmp_a = a;
	tmp_b = b;
	param.max = max_num(a);
	param.m = min_num(a);
	a = step_on_top_a(a);
	b = step_on_top_b(b);
	param.end = he_one(a);
	param.tmp_end = param.end;
	while (b)
	{
		he_two(a, b, param, 0);
		a = tmp_a;
		param.end = param.tmp_end;
		b = b->next;
	}
	return (tmp_b);
}
