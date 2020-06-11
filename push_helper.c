/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:39:23 by gmentat           #+#    #+#             */
/*   Updated: 2020/02/21 13:45:29 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		length_stack(t_intlist *stack)
{
	int		l;

	l = 0;
	while (stack)
	{
		l++;
		stack = stack->next;
	}
	return (l);
}

int		max_num(t_intlist *stack)
{
	int			max;

	max = stack->val;
	stack = stack->next;
	while (stack)
	{
		if (max < stack->val)
			max = stack->val;
		stack = stack->next;
	}
	return (max);
}

int		min_num(t_intlist *stack)
{
	int			min;

	min = stack->val;
	stack = stack->next;
	while (stack)
	{
		if (min > stack->val)
			min = stack->val;
		stack = stack->next;
	}
	return (min);
}

int		abs(int c)
{
	if (c < 0)
		c = c * (-1);
	return (c);
}
