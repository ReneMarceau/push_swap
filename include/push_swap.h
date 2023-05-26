/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:38:12 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/26 18:35:04 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>
# include <stdbool.h>

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
	int				index;
	int				chunk;
	int				data;
	int				size;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//----------------------- Lists utils -----------------------//
t_stack	*fill_stack(int argc, char **argv);
t_stack	*lstnew(int data, int index, int chunk);
void	delete_node(t_stack **node);
void	lstadd_front(t_stack **node_first, t_stack **node_last, t_stack *new);

//----------------------- Parsing -----------------------//
int		*args_to_tab(int argc, char **argv, int *size);
int		*quotes_to_tab(char **argv, int *size);
void	set_index(t_stack *stack);
void    set_chunk(t_stack *stack, int chunk_size);
int		numberPerChunk(int total_numbers, int num_chunks);

//----------------------- Error handling -----------------------//
bool	is_repeat(int *tab, int size);
bool	is_sorted(int *tab, int size);
int		count_arg(char **tab);

//----------------------- Actions -----------------------//
void	swap(t_stack **stack);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//----------------------- Free -----------------------//
void	end_program(t_stack *stack_a, t_stack *stack_b, bool error);
void	free_2d(char **tab, int size);

//----------------------- Sorting -----------------------//
void	sort_three(t_stack **stack);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void    sort_big(t_stack **stack_a, t_stack **stack_b);

//-------------------- Sorting Utils --------------------//
int 	best_path_chunk(t_stack *stack, int chunk);
int 	get_chunk_nbr(t_stack *stack);
int 	get_chunk_size(t_stack *stack, int chunk);

//----------------------- Testing -----------------------//
void	display_lst(t_stack *stack);
void	display_all(t_stack *stack_a, t_stack *stack_b);

#endif