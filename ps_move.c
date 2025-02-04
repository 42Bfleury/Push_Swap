/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:40:48 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/04 22:13:40 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ps_move(int nb, t_list **src, t_list **dest, char print)
{
	int i;
	int moves_src;
	int moves_dest;

	i = 0;
	// ft_printf("Nb: %i\n", nb);
	// ft_printf("Pos: %i\n", ps_find_pos(*src, nb));
	moves_src = ps_get_moves(*src, ps_find_pos(*src, nb), 0);
	// ft_printf("Moves src: %i\n", moves_src);
	if (print == 'a')
	{
		// ft_printf("New pos1: %i\n", ps_find_new_pos(*dest, nb, 1));
		moves_dest = ps_get_moves(*dest, ps_find_new_pos(*dest, nb, 1), 0);
	}
	else
	{
		// ft_printf("New pos0: %i\n", ps_find_new_pos(*dest, nb, 0));
		moves_dest = ps_get_moves(*dest, ps_find_new_pos(*dest, nb, 0), 0);
	}
	// ft_printf("Moves dest: %i\n", moves_dest);
	// ft_printf("Nb op: %i\n", ps_get_nb_op(*src, *dest, ps_find_pos(*src, nb), ps_find_new_pos(*dest, nb, 0), 0));
	if (moves_src >= 0 && moves_dest >= 0)
	{
		if (moves_src < moves_dest)
		{
			while (i < moves_dest)
			{
				if (i < moves_src)
					ps_rr(src, dest, 1);
				else if (print == 'a')
					ps_rotate(dest, 'a');
				else
					ps_rotate(dest, 'b');
				i++;
			}
		}
		else
		{
			while (i < moves_src)
			{
				if (i < moves_dest)
					ps_rr(src, dest, 1);
				else if (print == 'a')
					ps_rotate(src, 'b');
				else
					ps_rotate(src, 'a');
				i++;
			}
		}
	}
	else if (moves_src <= 0 && moves_dest <= 0)
	{
		if (moves_src < moves_dest)
		{
			while (i > moves_src)
			{
				if (i > moves_dest)
					ps_rrr(src, dest, 1);
				else if (print == 'a')
					ps_reverse_rotate(src, 'b');
				else
					ps_reverse_rotate(src, 'a');
				i--;
			}
		}
		else
		{
			while (i > moves_dest)
			{
				if (i > moves_src)
					ps_rrr(src, dest, 1);
				else if (print == 'a')
					ps_reverse_rotate(dest, 'a');
				else
					ps_reverse_rotate(dest, 'b');
				i--;
			}
		}
	}
	else if (moves_src <= 0 && moves_dest >= 0)
	{
		while (i > moves_src)
		{
			if (print == 'a')
				ps_reverse_rotate(src, 'b');
			else
				ps_reverse_rotate(src, 'a');
			i--;
		}
		i = 0;
		while (i < moves_dest)
		{
			if (print == 'a')
				ps_rotate(dest, 'a');
			else
				ps_rotate(dest, 'b');
			i++;
		}
	}
	else if (moves_src >= 0 && moves_dest <= 0)
	{
		while (i < moves_src)
		{
			if (print == 'a')
				ps_rotate(src, 'b');
			else
				ps_rotate(src, 'a');
			i++;
		}
		i = 0;
		while (i > moves_dest)
		{
			if (print == 'a')
				ps_reverse_rotate(dest, 'a');
			else
				ps_reverse_rotate(dest, 'b');
			i--;
		}
	}
	ps_push(src, dest, print);
	// ps_print_lists(*src, *dest);
	// ft_printf("___________________________________________\n");
}
