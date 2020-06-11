/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:19:51 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/04 13:09:19 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		help_push(t_intlist **arr1, t_intlist **arr2)
{
	t_intlist	*tmp1;
	t_intlist	*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	*arr1 = new_intlist();
	(*arr1)->val = (*arr2)->val;
	tmp2 = (*arr2)->next;
	free(*arr2);
	*arr2 = NULL;
	*arr2 = tmp2;
	tmp1 = NULL;
	tmp2 = NULL;
}

void			push_arr(t_intlist **arr1, t_intlist **arr2)
{
	t_intlist	*tmp1;
	t_intlist	*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	if (!(*arr1) && *arr2)
		help_push(arr1, arr2);
	else if (*arr2)
	{
		tmp1 = new_intlist();
		tmp1->val = (*arr2)->val;
		tmp1->next = *arr1;
		*arr1 = tmp1;
		tmp1 = NULL;
		tmp2 = (*arr2)->next;
		free(*arr2);
		*arr2 = NULL;
		*arr2 = tmp2;
		tmp2 = NULL;
	}
}
