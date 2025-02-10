/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_min_max_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:59:27 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/10 19:24:50 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_find_min(t_list *lst)
{
	int		min;

	if (!lst)
		return (0);
	min = (int)(long)lst->content;
	while (lst)
	{
		if ((int)(long)lst->content < min)
			min = (int)(long)lst->content;
		lst = lst->next;
	}
	return (min);
}

int	ps_find_max(t_list *lst)
{
	int		max;

	if (!lst)
		return (0);
	max = (int)(long)lst->content;
	while (lst)
	{
		if ((int)(long)lst->content > max)
			max = (int)(long)lst->content;
		lst = lst->next;
	}
	return (max);
}

int	ps_find_pos_min(t_list *lst)
{
	int		pos;
	int		min;
	int		result;

	pos = 0;
	result = 0;
	while (lst)
	{
		pos++;
		if (!result || (int)(long)lst->content < min)
		{
			min = (int)(long)lst->content;
			result = pos;
		}
		lst = lst->next;
	}
	return (result);
}

int	ps_find_pos_max(t_list *lst)
{
	int		pos;
	int		max;
	int		result;

	pos = 0;
	result = 0;
	while (lst)
	{
		pos++;
		if (!result || (int)(long)lst->content > max)
		{
			max = (int)(long)lst->content;
			result = pos;
		}
		lst = lst->next;
	}
	return (result);
}
