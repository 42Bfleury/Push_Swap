/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:27:53 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/12 01:34:19 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*void	ps_print_lists(t_list *a, t_list *b)
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
}*/

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = ps_parse(argc, argv);
	b = NULL;
	if (ps_check_dup(a))
		ps_error(&a, &b);
	if (!ps_check_sorted(a))
		ps_sort(&a, &b);
	ps_reorder_lst(&a);
	ft_lstclear(&a, NULL);
	return (0);
}
