/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:18:11 by gmentat           #+#    #+#             */
/*   Updated: 2020/02/21 14:08:10 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_arr(t_intlist *tmp)
{
	int		t_val;
	int		tt_index;
	int		tt_status;
	int		tt_true;

	if (tmp && tmp->next)
	{
		t_val = tmp->val;
		tt_index = tmp->index;
		tt_status = tmp->status;
		tt_true = tmp->true;
		tmp->val = tmp->next->val;
		tmp->index = tmp->next->index;
		tmp->status = tmp->next->status;
		tmp->true = tmp->next->true;
		tmp->next->val = t_val;
		tmp->next->index = tt_index;
		tmp->next->status = tt_status;
		tmp->next->true = tt_true;
	}
}
