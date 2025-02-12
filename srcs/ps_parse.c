/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 03:53:20 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/12 18:20:50 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long	_atol(const char *str)
{
	int		i;
	long	result;
	int		negative;

	i = 0;
	result = 0;
	negative = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			negative = 1;
	while (ft_isdigit(str[i]))
		result = (result * 10) + (str[i++] - '0');
	if (negative)
		return (-result);
	return (result);
}

static void	_parse_arg(t_list **l, char *s)
{
	int		i;
	long	n;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		ps_error(l, NULL);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			ps_error(l, NULL);
		i++;
	}
	n = _atol(s);
	if (n < INT_MIN || n > INT_MAX)
		ps_error(l, NULL);
	ft_lstadd_back(l, ft_lstnew((void *)n));
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
