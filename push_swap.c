/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:27:53 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/04 22:14:48 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print_lists(t_list *a, t_list *b)
{
	ft_printf("Pile A:\n");
	while (a)
	{
		ft_printf("%i\n", (int)(long)a->content);
		a = a->next;
	}
	ft_printf("Pile B:\n");
	while (b)
	{
		ft_printf("%i\n", (int)(long)b->content);
		b = b->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = ps_parse(argc, argv);
	b = NULL;
	if (ps_check_dup(a))
		ps_error(&a, &b);
	// ps_print_lists(a, b);
	// ft_printf("___________________________________________\n");
	if (!ps_check_sorted(a))
		ps_sort(&a, &b);
	// ps_print_lists(a, b);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	return (0);
}

/*int	main(int argc, char **argv)
{
	int		debug = 0;
	int		flag = 0;

	t_list	*a;
	t_list	*b;
	int		min_a;
	int		max_a;

	a = NULL;
	b = NULL;
	
	ps_error();

	ps_add_node(&a, 1);
	ps_add_node(&a, 2);
	ps_add_node(&a, 9);
	ps_add_node(&a, 4);
	ps_add_node(&a, 5);
	ps_add_node(&a, 7);
	ps_add_node(&a, 3);
	ps_add_node(&a, 8);
	
	if (debug)
	{
		ps_print_lists(a, b);
		min_a = ps_find_pos_min(a);
		max_a = ps_find_pos_max(a);
		ft_printf("\nPos Min A = %i\n", min_a);
		ft_printf("Pos Max A = %i\n", max_a);
	}
	else
		ps_print_lists(a, b);

	if (!ps_lst_is_sorted(a))
	{
		if (debug)
			ft_printf("\nA is not sorted...\n\n");
		ft_printf("\n");
		flag = ps_sort_lst_5(&a, &b);
		if (debug)
			ps_print_lists(a, b);
	}
	
	if (ps_find_pos_min(a) != 1)
	{
		if (debug)
			ft_printf("\nA is sorted but Min not first...\n");
		if (flag < 1)
			ft_printf("\n");
		ps_reorder_lst(&a);
		if (debug)
			ps_print_lists(a, b);
	}

	if (debug)
		ft_printf("\nA is sorted!\n");
	else
	{
		ft_printf("\nResult:\n");
		ps_print_lists(a, b);
	}
	return (0);
}*/