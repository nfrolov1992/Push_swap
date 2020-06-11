/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:17:27 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/03 19:56:42 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		run_op(char *line, t_intlist **a, t_intlist **b)
{
	if (!ft_strcmp(line, "pa"))
		push_arr(a, b);
	else if (!ft_strcmp(line, "pb"))
		push_arr(b, a);
	else if (!ft_strcmp(line, "sa"))
		swap_arr(*a);
	else if (!ft_strcmp(line, "sb"))
		swap_arr(*b);
	else if (!ft_strcmp(line, "ss"))
		ss(*a, *b);
	else if (!ft_strcmp(line, "ra"))
		rotate_arr(*a);
	else if (!ft_strcmp(line, "rb"))
		rotate_arr(*b);
	else if (!ft_strcmp(line, "rr"))
		rr(*a, *b);
	else if (!ft_strcmp(line, "rra"))
		rev_rotate_arr(a);
	else if (!ft_strcmp(line, "rrb"))
		rev_rotate_arr(b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(*a, *b);
	else
		err();
}
