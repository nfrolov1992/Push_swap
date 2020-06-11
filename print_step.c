/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:29:48 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/03 19:24:22 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_step(t_str *str_r, char *step)
{
	char	*tmp;

	if (str_r->str == NULL)
		str_r->str = ft_strnew(0);
	tmp = str_r->str;
	str_r->str = ft_strjoin(tmp, step);
	free(tmp);
	tmp = NULL;
}
