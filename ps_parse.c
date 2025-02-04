/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 03:53:20 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/03 01:50:18 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(t_list **a, t_list **b)
{
	ft_lstclear(a, NULL);
	ft_lstclear(b, NULL);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ps_parse_arg(t_list **a, char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ps_error(a, NULL);
		i++;
	}
	ft_lstadd_back(a, ft_lstnew((void *)(long)ft_atoi(str)));
}

void	ps_parse_string(t_list **a, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(str, ' ');
	while (tab[i])
	{
		ps_parse_arg(a, tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

t_list	*ps_parse(int argc, char **argv)
{
	t_list	*a;
	int		i;

	a = NULL;
	if (argc < 2)
		ps_error(NULL, NULL);
	i = 1;
	while (i < argc)
	{
		if (!ft_strlen(argv[i]))
			ps_error(&a, NULL);
		else if (ft_strchr(argv[i], ' '))
			ps_parse_string(&a, argv[i]);
		else
			ps_parse_arg(&a, argv[i]);
		i++;
	}
	return (a);
}
