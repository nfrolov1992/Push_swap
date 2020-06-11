# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmentat <gmentat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 15:27:16 by tvanessa          #+#    #+#              #
#    Updated: 2020/03/04 13:19:40 by gmentat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = 
SS = $(S)push_swap.c $(S)new_intlist.c $(S)is_sorted.c $(S)swap_arr.c $(S)ss.c \
	$(S)rrr.c $(S)rr.c $(S)rotate_arr.c $(S)rev_rotate_arr.c $(S)push_arr.c \
	$(S)ft_free_free.c $(S)err.c $(S)sorted.c $(S)push_helper.c $(S)check_arg.c \
	$(S)push_helper_two.c $(S)step_on_top_b.c $(S)step_on_top_a.c $(S)go_sort.c \
	$(S)free_step.c $(S)round_round.c $(S)index_num.c $(S)print_step.c \
	$(S)mini_sort_b.c $(S)mini_sort.c $(S)sort_max.c $(S)min_step_go.c \
	$(S)give_str.c $(S)read_checker.c $(S)display_stack.c $(S)run_op.c
SSS = $(S)checker.c $(S)new_intlist.c $(S)is_sorted.c $(S)swap_arr.c $(S)ss.c \
	$(S)rrr.c $(S)rr.c $(S)rotate_arr.c $(S)rev_rotate_arr.c $(S)push_arr.c \
	$(S)ft_free_free.c $(S)err.c $(S)sorted.c $(S)push_helper.c $(S)check_arg.c \
	$(S)push_helper_two.c $(S)step_on_top_b.c $(S)step_on_top_a.c $(S)go_sort.c \
	$(S)free_step.c $(S)round_round.c $(S)index_num.c $(S)print_step.c \
	$(S)mini_sort_b.c $(S)mini_sort.c $(S)sort_max.c $(S)min_step_go.c \
	$(S)give_str.c $(S)read_checker.c $(S)display_stack.c $(S)run_op.c
H = -I libft/includes -I libft/ -I .
NAME = push_swap
NAME2 = checker
CC = clang
CF = -g -Wall -Wextra -Werror

all: $(NAME) $(NAME2)

%.o: %.c push_swap.h
	$(CC) $(CF) $(H) -c -o $@ $<

$(NAME): libbuild $(SS:.c=.o)
	$(CC) $(CF) $(H) -o $(NAME) $(SS:.c=.o) -L libft/ -lft
$(NAME2): libbuild $(SSS:.c=.o)
	$(CC) $(CF) $(H) -o $(NAME2) $(SSS:.c=.o) -L libft/ -lft

libbuild:
	make -C libft/ 

clean:
	make -C libft/ clean 
	/bin/rm -f $(SS:.c=.o)
	/bin/rm -f $(SSS:.c=.o)

fclean: clean
	make -C libft/ fclean 
	/bin/rm -f libft.a
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME2)

re: fclean all
