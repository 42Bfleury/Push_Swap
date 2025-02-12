/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:40:48 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/12 04:50:46 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_move(int nb, t_list **src, t_list **dest, char print)
{
	int	i;
	int	moves_src;
	int	moves_dest;

	i = 0;
	moves_src = ps_get_moves(*src, ps_find_pos(*src, nb), 0);
	moves_dest = ps_get_moves(*dest, ps_find_new_pos(*dest, nb, (print == 'a')), 0);
	if (moves_src >= 0 && moves_dest >= 0)
	{
		while (i < moves_src && i < moves_dest)
		{
			ps_rr(src, dest);
			i++;
		}
		while (i < moves_src || i < moves_dest)
		{
			if (i < moves_src && print == 'a')
				ps_rotate(src, 'b');
			else if (i < moves_src)
				ps_rotate(src, 'a');
			else
				ps_rotate(dest, print);
			i++;
		}
	}
	else if (moves_src <= 0 && moves_dest <= 0)
	{
		while (i > moves_src && i > moves_dest)
		{
			ps_rrr(src, dest);
			i--;
		}
		while (i > moves_src || i > moves_dest)
		{
			if (i > moves_src && print == 'a')
				ps_reverse_rotate(src, 'b');
			else if (i > moves_src)
				ps_reverse_rotate(src, 'a');
			else
				ps_reverse_rotate(dest, print);
			i--;
		}
	}
	else if (moves_src <= 0 && moves_dest >= 0)
	{
		while (i-- > moves_src)
		{
			if (print == 'a')
				ps_reverse_rotate(src, 'b');
			else
				ps_reverse_rotate(src, 'a');
		}
		i = 0;
		while (i++ < moves_dest)
			ps_rotate(dest, print);
	}
	else if (moves_src >= 0 && moves_dest <= 0)
	{
		while (i++ < moves_src)
		{
			if (print == 'a')
				ps_rotate(src, 'b');
			else
				ps_rotate(src, 'a');
		}
		i = 0;
		while (i-- > moves_dest)
			ps_reverse_rotate(dest, print);
	}
}
