/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_helper_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:09:25 by gmentat           #+#    #+#             */
/*   Updated: 2020/02/28 19:24:53 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		index_no(t_intlist *stack_a)
{
	while (stack_a)
	{
		stack_a->index = -1;
		stack_a = stack_a->next;
	}
}
