/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 03:53:20 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/12 15:48:02 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	_parse_arg(t_list **l, char *s)
{
	int		i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			ps_error(l, NULL);
		i++;
	}
	ft_lstadd_back(l, ft_lstnew((void *)(long)ft_atoi(s)));
}

static void	_parse_string(t_list **l, char *s)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(s, ' ');
	while (tab[i])
	{
		_parse_arg(l, tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

t_list	*ps_parse(int ac, char **av)
{
	t_list	*a;
	int		i;

	a = NULL;
	if (ac < 2)
		ps_error(NULL, NULL);
	i = 1;
	while (i < ac)
	{
		if (!ft_strlen(av[i]))
			ps_error(&a, NULL);
		else if (ft_strchr(av[i], ' '))
			_parse_string(&a, av[i]);
		else
			_parse_arg(&a, av[i]);
		i++;
	}
	return (a);
}
