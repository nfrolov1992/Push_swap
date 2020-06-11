/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:25:16 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/04 13:07:34 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		round_helper(t_intlist *tmp)
{
	int			step;
	int			min;

	step = 0;
	min = min_num(tmp);
	while (tmp)
	{
		if (tmp->val == min)
		{
			step = tmp->index;
			break ;
		}
		tmp = tmp->next;
	}
	return (step);
}

void			round_round(t_intlist **stack_a, t_str *str_r)
{
	t_intlist	*tmp;
	int			step;

	tmp = *stack_a;
	step = round_helper(tmp);
	if (step > 0)
	{
		while (step > 0)
		{
			rotate_arr(*stack_a);
			print_step(str_r, "ra\n");
			step--;
		}
	}
	if (step < 0)
	{
		while (step < 0)
		{
			rev_rotate_arr(stack_a);
			print_step(str_r, "rra\n");
			step++;
		}
	}
}
