/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:42:21 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/12 01:55:49 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_check_dup(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (-1);
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->content == tmp->content)
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}

int	ps_check_sorted(t_list *lst)
{
	int		pos;
	int		pos_min;
	int		nb;
	int		first;

	if (!lst)
		return (0);
	pos = 0;
	pos_min = ps_find_pos_min(lst);
	first = (int)(long)lst->content;
	while (lst)
	{
		nb = (int)(long)lst->content;
		pos++;
		if ((lst->next && pos != (pos_min - 1)
				&& nb > (int)(long)lst->next->content)
			|| (!lst->next && pos_min > 1 && first < nb))
			return (0);
		lst = lst->next;
	}
	return (1);
}
