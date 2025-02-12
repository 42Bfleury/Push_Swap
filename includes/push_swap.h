/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:28:53 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/12 03:38:48 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/Libft/includes/libft.h"
# include "../lib/Ft_Printf/includes/ft_printf.h"

void	ps_print_lists(t_list *a, t_list *b);

void	ps_swap(t_list **lst, char print);
void	ps_rotate(t_list **lst, char print);
void	ps_reverse_rotate(t_list **lst, char print);
void	ps_push(t_list **src, t_list **dest, char print);

void	ps_ss(t_list **a, t_list **b);
void	ps_rr(t_list **a, t_list **b);
void	ps_rrr(t_list **a, t_list **b);

void	ps_error(t_list **a, t_list **b);
t_list	*ps_parse(int argc, char **argv);

void	ps_reorder_lst(t_list **lst);
void	ps_sort(t_list **a, t_list **b);

void	ps_move(int nb, t_list **src, t_list **dest, char print);
void	ps_move_ab(int nb, t_list **src, t_list **dest);
void	ps_move_ba(int nb, t_list **src, t_list **dest);

int		ps_check_dup(t_list *lst);
int		ps_check_sorted(t_list *lst);

int		ps_find_min(t_list *lst);
int		ps_find_max(t_list *lst);
int		ps_find_pos_min(t_list *lst);
int		ps_find_pos_max(t_list *lst);
int		ps_find_pos(t_list *lst, int nb);
int		ps_find_new_pos(t_list *dest, int nb_src, int asc);
int		ps_find_cheapest(t_list *src, t_list *dest, int asc);

int		ps_get_moves(t_list *lst, int pos, int src);
int		ps_get_nb_op(t_list *src, t_list *dest, int pos_src, int pos_dest);

#endif
