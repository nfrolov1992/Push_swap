/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:53:10 by tvanessa          #+#    #+#             */
/*   Updated: 2020/03/04 15:18:13 by gmentat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct			s_str
{
	char				*str;
}						t_str;

typedef struct			s_bonus
{
	int					w;
	int					v;
	char				*name_file;
}						t_bonus;

typedef struct			s_true
{
	long long int		val;
	struct s_true		*next;
}						t_true;

typedef struct			s_intlist
{
	long int			val;
	int					index;
	int					status;
	int					true;
	struct s_step		*step;
	struct s_intlist	*next;
	struct s_intlist	*previous;
}						t_intlist;

typedef struct			s_step
{
	int					b_val;
	int					b_step;
	int					a_val;
	int					a_step;
}						t_step;

t_intlist				*new_intlist(void);
t_step					*new_step(void);
t_str					*new_str(void);
t_bonus					*new_bonus(void);
int						is_sorted(t_intlist *a);
void					swap_arr(t_intlist *tmp);
void					push_arr(t_intlist **arr1, t_intlist **arr2);
void					rev_rotate_arr(t_intlist **a);
void					rotate_arr(t_intlist *a);
void					rrr(t_intlist *arr1, t_intlist *arr2);
void					rr(t_intlist *arr1, t_intlist *arr2);
void					ss(t_intlist *arr1, t_intlist *arr2);
void					ft_free_free(char **str, int i);
void					ft_free_stack(t_intlist *stack);
void					err(void);
t_intlist				*give_str(char *str, t_intlist *stack_a,
char **argv, t_bonus *bonus);
void					pars_arg(t_intlist *stack_a, int argc,
char **argv, t_bonus *bonus);
void					check_size(t_intlist *stack_a);
void					check_dub(t_intlist *stack_a);
char					*sorted_index(t_intlist *stack_a, t_str *str_r);
int						length_stack(t_intlist *stack);
int						max_num(t_intlist *stack);
int						min_num(t_intlist *stack);
void					index_num(t_intlist *stack);
int						abs(int c);
void					index_no(t_intlist *stack_a);
t_intlist				*step_on_top_b(t_intlist *stack);
t_intlist				*step_on_top_a(t_intlist *stack);
void					go_sort(t_step *result, t_intlist **a,
t_intlist **b, t_str *str_r);
void					free_step(t_intlist *a, t_intlist *b);
void					round_round(t_intlist **stack_a, t_str *str_r);
void					print_step(t_str *str_r, char *step);
void					mini_sort_b(t_intlist *a, int len, t_str *str_r);
void					mini_sort(t_intlist *a, t_str *str_r);
t_intlist				*sort_max(t_intlist *a, t_intlist *b);
t_step					*min_step_go(t_intlist *b);
void					ft_free_bonus(t_bonus *bonus);
void					ft_free_str(t_str *str);
t_intlist				*read_checker(t_intlist **a, t_intlist **b,
t_bonus *bonus);
void					display_stack(t_intlist *a, t_intlist *b);
void					run_op(char *line, t_intlist **a, t_intlist **b);

#endif
