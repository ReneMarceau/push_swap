/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:38:12 by rmarceau          #+#    #+#             */
/*   Updated: 2023/03/15 20:13:07 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

//Actions messages
# define PUSH_A "pa"
# define PUSH_B "pb"
# define SWAP_A "sa"
# define SWAP_B "sb"
# define SWAP_STACK "ss"
# define ROTATE_A "ra"
# define ROTATE_B "rb"
# define ROTATE_STACK "rr"
# define REV_ROTATE_A "rra"
# define REV_ROTATE_B "rrb"
# define REV_ROTATE_STACK "rrr"
# define ERROR "Error"

//----------------------- Structure of the nodes -----------------------//
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*fill_stack(int argc, char **argv, int *size);
t_stack	*lstnew(int data);
void	delete_node(t_stack **node);
void	lstadd_front(t_stack **node_first, t_stack **node_last, t_stack *new);

int		*args_to_tab(int argc, char **argv, int **size);
int		*quotes_to_tab(char **argv, int **size);

int		is_repeat(int *tab, int size);
int		is_sorted(int *tab, int size);
int		count_arg(char **tab);

void	swap(t_stack **stack);

void	pa(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b);
void	pb(t_stack **stack_a, t_stack **stack_b, int *size_a, int *size_b);
void	sa(t_stack **stack_a, int size);
void	sb(t_stack **stack_b, int size);
void	ss(t_stack **stack_a, t_stack **stack_b, int size_a, int size_b);
void	ra(t_stack **stack_a, int size);
void	rb(t_stack **stack_b, int size);
void	rr(t_stack **stack_a, t_stack **stack_b, int size_a, int size_b);
void	rra(t_stack **stack_a, int size);
void	rrb(t_stack **stack_b, int size);
void	rrr(t_stack **stack_a, t_stack **stack_b, int size_a, int size_b);

void	end_program(t_stack *stack_a, t_stack *stack_b, int size_a, int size_b);
void	free_2d(char **tab, int size);

#endif