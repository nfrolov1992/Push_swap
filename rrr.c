/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:25:29 by gmentat           #+#    #+#             */
/*   Updated: 2020/02/12 15:36:46 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_intlist *arr1, t_intlist *arr2)
{
	rev_rotate_arr(&arr1);
	rev_rotate_arr(&arr2);
}