/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_double_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:18:59 by bfleury           #+#    #+#             */
/*   Updated: 2025/01/28 14:44:33 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ss(t_list **a, t_list **b, int print)
{
	ps_swap(a, 0);
	ps_swap(b, 0);
	if (print)
		ft_printf("ss\n");
}

void	ps_rr(t_list **a, t_list **b, int print)
{
	ps_rotate(a, 0);
	ps_rotate(b, 0);
	if (print)
		ft_printf("rr\n");
}

void	ps_rrr(t_list **a, t_list **b, int print)
{
	ps_reverse_rotate(a, 0);
	ps_reverse_rotate(b, 0);
	if (print)
		ft_printf("rrr\n");
}
