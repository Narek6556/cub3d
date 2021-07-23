/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:01:43 by naaghasy          #+#    #+#             */
/*   Updated: 2021/01/19 13:01:45 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack,
	const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!needle[j])
		return (char *)(haystack);
	while (haystack[i] && needle[j] && len)
	{
		if (haystack[i] == needle[j])
		{
			j++;
		}
		else if (j)
		{
			j = 0;
			continue;
		}
		i++;
		len--;
	}
	if (!needle[j])
		return (char*)(haystack + i - j);
	return (0);
}
