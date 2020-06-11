/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_on_top_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:19:05 by gmentat           #+#    #+#             */
/*   Updated: 2020/02/28 21:51:40 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct		s_prev
{
	int				len;
	int				mid;
	int				i;
}					t_prev;

static void			step_on_top_a_help(t_intlist *tmp, t_prev param)
{
	while (param.i <= param.mid)
	{
		tmp->index = param.i;
		tmp->step->a_val = tmp->val;
		tmp->step->a_step = tmp->index;
		tmp = tmp->next;
		if (tmp && !tmp->step)
			tmp->step = new_step();
		param.i++;
	}
	param.i = (param.len - (param.mid + 1)) * (-1);
	while (param.i < 0 && tmp)
	{
		tmp->index = param.i;
		tmp->step->a_val = tmp->val;
		tmp->step->a_step = tmp->index;
		tmp = tmp->next;
		if (tmp)
			tmp->step = new_step();
		param.i++;
	}
}

t_intlist			*step_on_top_a(t_intlist *stack)
{
	t_prev		param;
	t_intlist	*tmp;

	param.i = 0;
	tmp = stack;
	if (tmp && !tmp->step)
		tmp->step = new_step();
	param.len = length_stack(tmp);
	param.mid = param.len / 2;
	index_no(tmp);
	if (stack)
		step_on_top_a_help(tmp, param);
	return (stack);
}
