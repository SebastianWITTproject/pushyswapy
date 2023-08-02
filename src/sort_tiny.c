/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: switt <switt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:41:01 by mcombeau          #+#    #+#             */
/*   Updated: 2023/08/02 19:57:47 by switt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find_highest_index:
*	Returns the highest index in a stack.
*/
static t_stack	*find_highest(t_stack **stack)
{
	int				highest;
	t_stack	*tmp;
	t_stack	*highest_node;

	if (stack == NULL)
		return (NULL);
	tmp = *stack;
	highest = INT_MIN;
	while (tmp)
	{
		if (tmp->value > highest)
		{
			highest = tmp->value;
			highest_node = tmp;
		}
		tmp = tmp->next;
	}
	return (highest_node);
}


/* tiny_sort:
*	Sorts a stack of 3 numbers in 2 or fewer moves. The sorting is done by index
*	rather than value. Example:
*		values:		 0	 9	 2
*		indexes:	[1]	[3]	[2]
*	Solution, 2 moves:
*	rra:
*		values:		 2	 0	 9
*		indexes:	[2]	[1]	[3]
*	sa:
*		values:		 0	 2	 9
*		indexes:	[1]	[2]	[3]
*/
void	tiny_sort(t_stack **stack)
{
	t_stack	*highest_node;

	if (is_sorted(*stack))
		return ;
	highest_node = find_highest(stack);
	if (*stack == highest_node)
		do_ra(stack);
	else if ((*stack)->next == highest_node)
		do_rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		do_sa(stack);
}
