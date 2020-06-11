/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_intlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:10:45 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/02 13:16:07 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_intlist	*new_intlist(void)
{
	t_intlist *new;

	if ((new = (t_intlist *)malloc(sizeof(t_intlist))))
	{
		new->val = 0;
		new->index = -1;
		new->status = 0;
		new->true = 0;
		new->step = NULL;
		new->next = NULL;
		new->previous = NULL;
	}
	return (new);
}

t_step		*new_step(void)
{
	t_step *new;

	if ((new = (t_step *)malloc(sizeof(t_step))))
	{
		new->b_val = 0;
		new->b_step = 0;
		new->a_val = 0;
		new->a_step = 0;
	}
	return (new);
}

t_str		*new_str(void)
{
	t_str *new;

	if ((new = (t_str *)malloc(sizeof(t_str))))
		new->str = NULL;
	return (new);
}

t_bonus		*new_bonus(void)
{
	t_bonus *new;

	if ((new = (t_bonus *)malloc(sizeof(t_bonus))))
	{
		new->name_file = NULL;
		new->v = 0;
		new->w = 0;
	}
	return (new);
}
