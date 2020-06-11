/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:45:32 by gmentat           #+#    #+#             */
/*   Updated: 2020/02/28 22:08:14 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		helper_index_num(t_intlist *tmp, t_intlist *stack, int index)
{
	int			max;

	tmp = stack;
	while (index >= 0)
	{
		max = -2147483648;
		while (stack)
		{
			if (max < stack->val && stack->index < 0)
				max = stack->val;
			stack = stack->next;
		}
		stack = tmp;
		while (stack)
		{
			if (stack->val == max)
			{
				stack->index = index;
				index--;
				break ;
			}
			stack = stack->next;
		}
		stack = tmp;
	}
}

void			index_num(t_intlist *stack)
{
	int			index;
	t_intlist	*tmp;

	tmp = stack;
	index = length_stack(stack) - 1;
	helper_index_num(tmp, stack, index);
}
