/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:23:36 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/04 13:07:44 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct		s_rotate
{
	int				tt_val;
	int				tt_index;
	int				tt_status;
	int				tt_true;
}					t_rotate;

static void			help_rot(t_intlist *a, t_rotate rot)
{
	while (a)
	{
		if (a->next == NULL)
		{
			a->val = rot.tt_val;
			a->index = rot.tt_index;
			a->status = rot.tt_status;
			a->true = rot.tt_true;
			break ;
		}
		a->val = a->next->val;
		a->index = a->next->index;
		a->status = a->next->status;
		a->true = a->next->true;
		a = a->next;
	}
}

void				rotate_arr(t_intlist *a)
{
	t_intlist	*tmp;
	t_rotate	rot;

	if (a)
	{
		tmp = a;
		rot.tt_val = a->val;
		rot.tt_index = a->index;
		rot.tt_status = a->status;
		rot.tt_true = a->true;
		help_rot(tmp, rot);
	}
}
