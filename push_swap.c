/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:32:18 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/04 18:29:39 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_free_all(t_intlist *stack_a, t_bonus *bonus, t_str *str_r)
{
	ft_free_stack(stack_a);
	ft_free_bonus(bonus);
	ft_free_str(str_r);
}

static void		help_main(t_intlist *stack_a, t_bonus *bonus,
							t_str *str_r, int fo)
{
	fo = open(bonus->name_file, O_WRONLY);
	if (fo == -1)
		ft_free_all(stack_a, bonus, str_r);
	if (fo == -1)
		err();
	str_r->str = sorted_index(stack_a, str_r);
	ft_dprintf(fo, "%s", str_r->str);
	close(fo);
}

static void		help_main_two(t_intlist *stack_a, t_bonus *bonus, t_str *str_r)
{
	check_size(stack_a);
	check_dub(stack_a);
	if (is_sorted(stack_a) == 1)
	{
		ft_free_all(stack_a, bonus, str_r);
		exit(1);
	}
}

static void		help_three(t_bonus *bonus, t_str *str_r)
{
	ft_free_bonus(bonus);
	ft_free_str(str_r);
}

int				main(int argc, char **argv)
{
	t_intlist	*stack_a;
	t_str		*str_r;
	t_bonus		*bonus;

	stack_a = new_intlist();
	bonus = new_bonus();
	str_r = new_str();
	if (argc == 1)
	{
		ft_free_all(stack_a, bonus, str_r);
		ft_printf("Enter arguments\n");
		return (0);
	}
	else
	{
		pars_arg(stack_a, argc, (argv + 1), bonus);
		help_main_two(stack_a, bonus, str_r);
		if (bonus->name_file != NULL)
			help_main(stack_a, bonus, str_r, 0);
		else
			ft_printf("%s", (str_r->str = sorted_index(stack_a, str_r)));
	}
	help_three(bonus, str_r);
	stack_a = NULL;
	return (0);
}
