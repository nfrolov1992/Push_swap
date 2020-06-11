/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:15:26 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/04 13:13:24 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_intlist	*end_stack(t_intlist *a)
{
	while (a->next)
	{
		a = a->next;
	}
	return (a);
}

void				pars_arg(t_intlist *stack_a, int argc, char **argv,
								t_bonus *bonus)
{
	t_intlist	*tmp;

	tmp = stack_a;
	while (*argv)
	{
		tmp = give_str(*argv, tmp, argv, bonus);
		if (++(argv) && !(*argv))
			break ;
		if (tmp->true != 1)
		{
			if (tmp->next)
				tmp = end_stack(stack_a);
			tmp->next = new_intlist();
			tmp = tmp->next;
		}
		else if (bonus->name_file != NULL && (bonus->w == 1))
		{
			argv++;
			bonus->w = -1;
		}
		if (bonus->v == 1)
			bonus->v = 2;
		tmp->true = 0;
	}
	argc = 0;
}

void				check_size(t_intlist *stack_a)
{
	while (stack_a)
	{
		if (stack_a->val > INT_MAX || stack_a->val < INT_MIN)
			err();
		stack_a = stack_a->next;
	}
}

void				check_dub(t_intlist *stack_a)
{
	int			val;
	t_intlist	*tmp;

	tmp = NULL;
	val = stack_a->val;
	stack_a = stack_a->next;
	while (stack_a)
	{
		tmp = stack_a;
		while (tmp)
		{
			if (val == tmp->val)
				err();
			tmp = tmp->next;
		}
		val = stack_a->val;
		stack_a = stack_a->next;
	}
}
