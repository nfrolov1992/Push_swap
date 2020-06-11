/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:30:35 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/04 15:45:57 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct			s_ind
{
	int					i;
}						t_ind;

static void				helpusik_one(t_intlist **stack_a, char **num,
										t_ind *ind, t_bonus *bonus)
{
	bonus->w = -1;
	if (bonus->v != 2)
		bonus->v = -1;
	if ((*num))
	{
		(*stack_a)->next = new_intlist();
		(*stack_a) = (*stack_a)->next;
		ind->i++;
	}
}

static void				helpusik_two(char **num, t_bonus *bonus)
{
	bonus->w = 1;
	if (*num)
		err();
}

static void				helpusik_three(char **num, t_bonus *bonus)
{
	bonus->v = 1;
	if (*num)
		err();
}

static void				helpusik(t_intlist *stack_a, char **num,
									t_ind *ind, t_bonus *bonus)
{
	while (*num)
	{
		if ((stack_a->val = ft_atol(*num)) && ++(num))
			helpusik_one(&stack_a, num, ind, bonus);
		else if (bonus->w != -1 && (ft_strcmp(*num, "-w")) == 0 && ++(num))
			helpusik_two(num, bonus);
		else if (bonus->v == 0 && (ft_strcmp(*num, "-v")) == 0 && ++(num))
			helpusik_three(num, bonus);
		else if ((stack_a->val = ft_strcmp(*num, "0")) == 0 && ++(num))
			helpusik_one(&stack_a, num, ind, bonus);
		else
			err();
		if (!(*num))
			break ;
	}
}

t_intlist				*give_str(char *str, t_intlist *stack_a,
									char **argv, t_bonus *bonus)
{
	char	**num;
	t_ind	ind;
	char	**tmp;

	ind.i = 1;
	num = ft_strsplit(str, ' ');
	tmp = num;
	if (*num)
		helpusik(stack_a, num, &ind, bonus);
	else
		stack_a->true = 1;
	if (bonus->w == 1)
	{
		stack_a->true = 1;
		argv++;
		if ((*argv))
			bonus->name_file = ft_strdup(*argv);
	}
	if (bonus->v == 1)
		stack_a->true = 1;
	ft_free_free(num, ind.i);
	num = NULL;
	return (stack_a);
}
