/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 04:39:48 by bfleury           #+#    #+#             */
/*   Updated: 2024/01/16 00:43:43 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	len;

	if ((!big || !little) && !n)
		return (NULL);
	if (!*little)
		return ((char *)big);
	len = ft_strlen(little);
	while (*big && n-- >= len)
	{
		if (*big == *little && !ft_memcmp(big, little, len))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
