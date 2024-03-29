/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:38:12 by rmarceau          #+#    #+#             */
/*   Updated: 2023/05/29 17:33:07 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>
# include <stdbool.h>

// Actions messages
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

// Chunk size
typedef enum e_chunk
{
	VALUE,
	SIZE,
	CHUNK_COUNT,
}					t_chunk;

//----------------------- Structure of the nodes -----------------------//
typedef struct s_stack
{
	int				index;
	int				chunk;
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

//----------------------- Container Structure -----------------------//
typedef struct s_container
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				*tab;
	int				size_a;
	int				size_b;
}					t_container;

//----------------------- Lists utils -----------------------//
t_stack				*lstnew(int data, int index, int chunk);
void				lstadd_front(t_stack **node_first, t_stack **node_last,
						t_stack *new);
void				delete_node(t_stack **node);

//----------------------- Parsing -----------------------//
void				fill_stack(t_container *data, int argc, char **argv);
void				set_index(t_stack *stack, int size);
void				set_chunk(t_container *data, int chunk_size);
int					number_per_chunk(int total_numbers, int num_chunks);

//----------------------- Error handling -----------------------//
bool				is_repeat(int *tab, int size);
bool				is_sorted(int *tab, int size);

//----------------------- Actions -----------------------//
void				swap(t_stack **stack, int size);
void				pa(t_container *data);
void				pb(t_container *data);
void				sa(t_container *data);
void				sb(t_container *data);
void				ss(t_container *data);
void				ra(t_container *data);
void				rb(t_container *data);
void				rr(t_container *data);
void				rra(t_container *data);
void				rrb(t_container *data);
void				rrr(t_container *data);

//----------------------- Free -----------------------//
void				free_2d(char **tab, int size);
void				end_program(t_container *data, bool error);

//----------------------- Sorting -----------------------//
void				sort_three(t_container *data);
void				sort_five(t_container *data);
void				sort_big(t_container *data);

//-------------------- Sorting Utils --------------------//
int					best_path(t_stack *stack, int size, int value,
						bool is_chunk);
int					get_chunk_size(t_container *data, int chunk);

//----------------------- Error handling -----------------------//
int					count_arg(char **tab);
int					abs(int n);

#endif