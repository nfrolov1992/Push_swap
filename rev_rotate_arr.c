/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:22:00 by gmentat           #+#    #+#             */
/*   Updated: 2020/02/11 19:27:06 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_arr(t_intlist **a)
{
	int			tt_val;
	int			t_val;
	int			i;

	i = 0;
	if (*a)
	{
		t_val = (*a)->val;
		while ((*a)->next)
		{
			(*a)->next->previous = (*a);
			(*a) = (*a)->next;
			i++;
		}
		tt_val = (*a)->val;
		(*a)->val = t_val;
		while (i > 0)
		{
			(*a)->val = (*a)->previous->val;
			(*a) = (*a)->previous;
			i--;
		}
		(*a)->val = tt_val;
	}
}
