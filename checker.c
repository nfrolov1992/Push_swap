/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 23:05:27 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/04 15:37:48 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		helper_checker(t_intlist *a, t_bonus *bonus)
{
	t_intlist *b;

	b = NULL;
	a = read_checker(&a, &b, bonus);
	if (a)
	{
		if (a->true == 0)
			;
		if (is_sorted(a) && !b)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		ft_printf("KO\n");
	ft_free_stack(a);
	ft_free_stack(b);
}

int				main(int argc, char **argv)
{
	t_intlist	*stack_a;
	t_bonus		*bonus;

	stack_a = new_intlist();
	bonus = new_bonus();
	if (argc == 1)
	{
		ft_free_stack(stack_a);
		ft_free_bonus(bonus);
		ft_printf("Enter arguments\n");
		return (0);
	}
	else
	{
		pars_arg(stack_a, argc, (argv + 1), bonus);
		check_size(stack_a);
		check_dub(stack_a);
		helper_checker(stack_a, bonus);
	}
	ft_free_bonus(bonus);
	return (0);
}
