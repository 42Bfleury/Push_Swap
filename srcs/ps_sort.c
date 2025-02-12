/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:50:27 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/12 04:50:07 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ps_sort_lst_a_3(t_list **lst)
{
	if (!lst || !*lst)
		return ;
	if (!ps_check_sorted(*lst))
		ps_swap(lst, 'a');
}

void	ps_sort(t_list **a, t_list **b)
{
	int	nb;

	while (ft_lstsize(*a) > 3)
	{
		nb = ps_find_cheapest(*a, *b, 0);
		ps_move(nb, a, b, 'b');
		ps_push(a, b, 'b');
	}
	ps_sort_lst_a_3(a);
	while (ft_lstsize(*b))
	{
		nb = ps_find_cheapest(*b, *a, 1);
		ps_move(nb, b, a, 'a');
		ps_push(b, a, 'a');
	}
}
