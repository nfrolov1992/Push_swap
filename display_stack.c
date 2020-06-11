/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:25:16 by gmentat           #+#    #+#             */
/*   Updated: 2020/03/04 13:11:41 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		help_display(t_intlist *b)
{
	char	*str;
	char	*res_str;
	char	*tmp;

	res_str = ft_strnew(0);
	while (b)
	{
		tmp = res_str;
		str = ft_itoa(b->val);
		res_str = ft_strjoin(tmp, str);
		free(str);
		str = NULL;
		free(tmp);
		tmp = NULL;
		tmp = res_str;
		res_str = ft_strjoin(tmp, " ");
		free(tmp);
		tmp = NULL;
		b = b->next;
	}
	ft_printf("B: |%s\n\n", res_str);
	free(res_str);
	res_str = NULL;
}

void			display_stack(t_intlist *a, t_intlist *b)
{
	char	*str;
	char	*res_str;
	char	*tmp;

	res_str = ft_strnew(0);
	while (a)
	{
		tmp = res_str;
		str = ft_itoa(a->val);
		res_str = ft_strjoin(tmp, str);
		free(str);
		str = NULL;
		free(tmp);
		tmp = NULL;
		tmp = res_str;
		res_str = ft_strjoin(tmp, " ");
		free(tmp);
		tmp = NULL;
		a = a->next;
	}
	ft_printf("A: |%s\n", res_str);
	free(res_str);
	res_str = NULL;
	help_display(b);
}
