/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:44:53 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/04 22:10:18 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_find_pos(t_list *lst, int nb)
{
	int	pos;

	pos = 0;
	while (lst)
	{
		pos++;
		if (nb == (int)(long)lst->content)
			return (pos);
		lst = lst->next;
	}
	return (0);
}

int	ps_find_new_pos(t_list *dest, int nb_src, int asc)
{
	int		i;
	int		min;
	int		max;
	int		prev;
	int		next;

	i = 1;
	min = ps_find_min(dest);
	max = ps_find_max(dest);
	while (dest)
	{
		i++;
		if (!dest->next)
			return (1);
		prev = (int)(long)dest->content;
		next = (int)(long)dest->next->content;
		if ((asc && prev < nb_src && nb_src < next)
			|| (asc && (nb_src < min || max < nb_src) && prev == max && next == min)
			|| (!asc && prev > nb_src && nb_src > next)
			|| (!asc && (nb_src < min || max < nb_src) && prev == min && next == max))
			break ;
		dest = dest->next;
	}
	return (i);
}

int	ps_get_moves(t_list *lst, int pos, int calc)
{
	int		size;

	if (calc)
		size = ft_lstsize(lst) + pos - 1;
	else
		size = ft_lstsize(lst);
	// if (calc)
		// ft_printf("SIZE: %i\n", size);
	// else
		// ft_printf("Size: %i\n", size);
	if (pos > (size / 2) + 1)
		return ((size - pos + 1) * -1);
	return (pos - 1);
}

int	ps_get_nb_op(t_list *src, t_list *dest, int pos_src, int pos_dest, int calc)
{
	int		moves_src;
	int		moves_dest;

	moves_src = ps_get_moves(src, pos_src, calc);
	// ft_printf("Moves Src: %i\n", moves_src);
	moves_dest = ps_get_moves(dest, pos_dest, 0);
	// ft_printf("Moves Dest: %i\n", moves_dest);
	if (moves_src >= 0 && moves_dest >= 0)
	{
		if (moves_src < moves_dest)
			return (moves_dest + 1);
		return (moves_src + 1);
	}
	if (moves_src <= 0 && moves_dest <= 0)
	{
		if (moves_src < moves_dest)
			return (-moves_src + 1);
		return (-moves_dest + 1);
	}
	if (moves_src <= 0)
		return (-moves_src + moves_dest + 1);
	return (-moves_dest + moves_src + 1);
}

int	ps_find_cheapest(t_list *src, t_list *dest, int asc)
{
	int	tmp;
	int	pos;
	int	moves;
	int	result;
	int	new_pos;

	pos = 1;
	result = (int)(long)src->content;
	new_pos = ps_find_new_pos(dest, result, asc);
	moves = ps_get_nb_op(src, dest, pos, new_pos, 1);
	while (src)
	{
		new_pos = ps_find_new_pos(dest, (int)(long)src->content, asc);
		tmp = ps_get_nb_op(src, dest, pos, new_pos, 1);
		if (tmp < moves)
		{
			moves = tmp;
			result = (int)(long)src->content;
		}
		src = src->next;
		pos++;
	}
	return (result);
}
