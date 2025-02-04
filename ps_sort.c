/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:50:27 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/04 22:15:10 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_reorder_lst(t_list **lst)
{
	int		i;
	int		pos_min;
	int		lst_size;

	pos_min = ps_find_pos_min(*lst);
	lst_size = ft_lstsize(*lst);
	if (pos_min <= (lst_size / 2) + 1)
	{
		i = pos_min - 1;
		while (i--)
			ps_rotate(lst, 'a');
	}
	else
	{
		i = lst_size - pos_min + 1;
		while (i--)
			ps_reverse_rotate(lst, 'a');
	}
}

int	ps_sort_lst_a_3(t_list **lst)
{
	if (!lst || !*lst)
		return (-1);
	if (!ps_check_sorted(*lst))
	{
		ps_swap(lst, 'a');
		return (1);
	}
	return (0);
}

void	ps_sort(t_list **a, t_list **b)
{
	int	nb;

	while (ft_lstsize(*a) > 3)
	{
		nb = ps_find_cheapest(*a, *b, 0);
		ps_move(nb, a, b, 'b');
	}
	ps_sort_lst_a_3(a);
	while (ft_lstsize(*b))
	{
		nb = ps_find_cheapest(*b, *a, 1);
		ps_move(nb, b, a, 'a');
	}
	ps_reorder_lst(a);
	// ft_printf("___________________________________________\n");
}

/*int	ps_sort_lst_5(t_list **a, t_list **b)
{
	int		i;
	int		size_a;
	// int		first_b;
	// int		min_a;
	// int		max_a;
	// int		pos_min_a;
	// int		pos_max_a;

	if (!a || !*a || !b)
		return (0);
	size_a = ft_lstsize(*a);
	if (size_a <= 3)
		return (ps_sort_lst_a_3(a));
	i = 0;
	while (size_a - i > 3)
	{
		ps_push(a, b, 'b');
		i++;
	}
	ps_sort_lst_a_3(a);

	// min_a = ps_find_min(*a);
	// max_a = ps_find_max(*a);

	int num = ps_find_cheapest(*b, *a, 1);
	int pos = ps_find_pos(*b, num);
	int new_pos = ps_find_new_pos(*a, num, 1);
	int nb_ops = ps_get_nb_op(*b, *a, pos, new_pos);

	// first_b = (int)(long)(*b)->content;

	ft_printf("Stack: B\n");
	ft_printf("Cheapest Num: %i\n", num);
	ft_printf("Position: %i\n", pos);
	ft_printf("New Position: %i\n", new_pos);
	ft_printf("Nb operations: %i\n", nb_ops);

	// if (first_b < min_a || max_a < first_b)
	// {
	// 	pos_min_a = ps_find_pos_min(*a);
	// 	pos_max_a = ps_find_pos_max(*a);
	// 	if ((first_b < min_a && pos_min_a == 1) || (max_a < first_b && pos_max_a == size_a - i))
	// 		ps_push(b, a, 'a');
	// }
	return (1);
}*/
