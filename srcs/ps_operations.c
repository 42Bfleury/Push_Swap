/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:18:59 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/10 19:24:35 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_push(t_list **src, t_list **dest, char print)
{
	t_list	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	ft_lstadd_front(dest, *src);
	*src = tmp;
	if (print == 'a' || print == 'b')
		ft_printf("p%c\n", print);
}

void	ps_swap(t_list **lst, char print)
{
	t_list	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	if (print == 'a' || print == 'b')
		ft_printf("s%c\n", print);
}

void	ps_rotate(t_list **lst, char print)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *lst;
	*lst = (*lst)->next;
	tmp->next->next = NULL;
	if (print == 'a' || print == 'b')
		ft_printf("r%c\n", print);
}

void	ps_reverse_rotate(t_list **lst, char print)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *lst;
	*lst = tmp->next;
	tmp->next = NULL;
	if (print == 'a' || print == 'b')
		ft_printf("rr%c\n", print);
}
