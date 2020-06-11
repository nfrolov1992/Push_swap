/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_on_top_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:17:27 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/03 19:12:13 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct		s_prev
{
	int				len;
	int				mid;
	int				i;
}					t_prev;

static void			step_on_top_b_help(t_intlist *tmp, t_prev param)
{
	while (param.i <= param.mid)
	{
		if (tmp && !tmp->step)
			tmp->step = new_step();
		tmp->index = param.i;
		tmp->step->b_val = tmp->val;
		tmp->step->b_step = tmp->index;
		tmp = tmp->next;
		param.i++;
	}
	param.i = (param.len - (param.mid + 1)) * (-1);
	while (param.i < 0 && tmp)
	{
		if (tmp && !tmp->step)
			tmp->step = new_step();
		tmp->index = param.i;
		tmp->step->b_val = tmp->val;
		tmp->step->b_step = tmp->index;
		tmp = tmp->next;
		param.i++;
	}
}

t_intlist			*step_on_top_b(t_intlist *stack)
{
	t_prev		param;
	t_intlist	*tmp;

	param.i = 0;
	tmp = stack;
	param.len = length_stack(tmp);
	param.mid = param.len / 2;
	index_no(tmp);
	if (stack)
		step_on_top_b_help(tmp, param);
	return (stack);
}
