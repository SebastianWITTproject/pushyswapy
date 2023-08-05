/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:04:00 by mcombeau          #+#    #+#             */
/*   Updated: 2023/08/04 01:05:36 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_sorted:
*	Tant que le node precedent est plus petit que le suivant c'est trie
	si c'est pas le cas une seule fois c'est pas trie donc retourne faux
*/
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* push_swap:
*	Chooses a sorting method depending on the number
*	of values to be sorted.
*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

/* main:
*	1) Check si pas d'arg passe
	2) Verifie que input respecte les conditions du sujet pas de repet + nombre etc.
	3) Cree une liste chainee representant la pile a avec tous les nombres en param
	4) Assigne les index 
	5) Fait le tri 
	6) Free
*/
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	int		is_split;

	is_split = 0;
	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		is_split = 1;
	}
	if (!is_correct_input(av, is_split))
		exit_error(NULL, NULL, is_split, av);
	stack_b = NULL;
	stack_a = fill_stack_values(av, is_split);
	stack_size = get_stack_size(stack_a);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (is_split)
		ft_free(av);
	return (0);
}
