/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:23:56 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/03 14:38:37 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_step(t_intlist *a, t_intlist *b)
{
	int		len;

	len = length_stack(a);
	while (a && len > 0)
	{
		if (a->step)
		{
			free(a->step);
			a->step = NULL;
		}
		a = a->next;
		len--;
	}
	len = length_stack(b);
	while (b && len > 0)
	{
		if (b->step)
		{
			free(b->step);
			b->step = NULL;
		}
		b = b->next;
		len--;
	}
}
