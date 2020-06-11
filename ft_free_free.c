/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:11:05 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/03 20:00:00 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_free_free(char **str, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		str[j] = NULL;
		j++;
	}
	free(str);
	str = NULL;
}

void		ft_free_stack(t_intlist *stack)
{
	t_intlist *tmp;

	if (stack)
	{
		while (stack && stack->next)
		{
			tmp = stack;
			if (stack->next)
				stack = stack->next;
			else
				stack = NULL;
			free(tmp);
			tmp = NULL;
		}
		free(stack);
		stack = NULL;
	}
}

void		ft_free_bonus(t_bonus *bonus)
{
	free(bonus->name_file);
	bonus->name_file = NULL;
	free(bonus);
	bonus = NULL;
}

void		ft_free_str(t_str *str)
{
	free(str->str);
	str->str = NULL;
	free(str);
	str = NULL;
}
