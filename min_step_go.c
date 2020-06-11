/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_step_go.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:34:46 by gmentat           #+#    #+#             */
/*   Updated: 2020/02/28 21:27:46 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		helper_min_step_go(t_intlist *b)
{
	while (b)
	{
		if (b->step->b_step > 0 && b->step->a_step > 0)
		{
			if (b->step->b_step == b->step->a_step)
				b->index = abs(b->step->b_step);
			else if (b->step->b_step > b->step->a_step)
				b->index = abs(b->step->b_step);
			else if (b->step->b_step < b->step->a_step)
				b->index = abs(b->step->a_step);
		}
		else if (b->step->b_step < 0 && b->step->a_step < 0)
		{
			if (b->step->b_step == b->step->a_step)
				b->index = abs(b->step->b_step);
			else if (b->step->b_step > b->step->a_step)
				b->index = abs(b->step->a_step);
			else if (b->step->b_step < b->step->a_step)
				b->index = abs(b->step->b_step);
		}
		else
			b->index = abs(b->step->b_step) + abs(b->step->a_step);
		b = b->next;
	}
}

t_step			*min_step_go(t_intlist *b)
{
	t_intlist	*tmp_b;
	t_step		*min_step;
	int			ind;

	tmp_b = b;
	min_step = new_step();
	helper_min_step_go(b);
	b = tmp_b;
	ind = b->index;
	min_step->a_step = b->step->a_step;
	min_step->b_step = b->step->b_step;
	while (b)
	{
		if (ind > b->index)
		{
			ind = b->index;
			min_step->a_step = b->step->a_step;
			min_step->b_step = b->step->b_step;
		}
		b = b->next;
	}
	return (min_step);
}
