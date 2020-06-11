/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:18:11 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/04 15:11:58 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		help_read_ch(t_bonus *bonus, t_intlist **a, t_intlist **b)
{
	char	*line;
	int		fo;

	line = NULL;
	(*a)->true = 0;
	fo = open(bonus->name_file, O_RDONLY);
	if (fo == -1)
		err();
	if (bonus->v == 2)
		display_stack(*a, *b);
	while ((get_next_line(fo, &line)) == 1)
	{
		(*a)->true = 1;
		run_op(line, a, b);
		free(line);
	}
	close(fo);
	if (bonus->v == 2 && (*a)->true == 1)
		display_stack(*a, *b);
	else if ((*a)->true == 0)
		ft_printf("successful recording, retype the command");
}

static void		help_read_ch_two(t_intlist **a, t_intlist **b, char *line)
{
	while ((get_next_line(0, &line)) > 0)
	{
		run_op(line, a, b);
		free(line);
	}
}

t_intlist		*read_checker(t_intlist **a, t_intlist **b, t_bonus *bonus)
{
	char	*line;

	line = NULL;
	if (a)
	{
		if (bonus->name_file != NULL)
			help_read_ch(bonus, a, b);
		else if (bonus->v == 2 && bonus->name_file == NULL)
		{
			while ((get_next_line(0, &line)) > 0)
			{
				if (bonus->v == 2)
				{
					run_op(line, a, b);
					display_stack(*a, *b);
					free(line);
				}
			}
		}
		else
			help_read_ch_two(a, b, line);
	}
	return (*a);
}
