/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:27:53 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/12 15:23:22 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_error(t_list **a, t_list **b)
{
	ft_lstclear(a, NULL);
	ft_lstclear(b, NULL);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = ps_parse(ac, av);
	b = NULL;
	if (ps_check_dup(a))
		ps_error(&a, &b);
	if (!ps_check_sorted(a))
		ps_sort(&a, &b);
	ps_reorder(&a, 1);
	ft_lstclear(&a, NULL);
	return (0);
}
