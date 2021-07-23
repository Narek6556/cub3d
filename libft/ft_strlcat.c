/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:35:42 by naaghasy          #+#    #+#             */
/*   Updated: 2021/01/19 11:35:44 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned int	k;

	i = ft_strlen(dst);
	j = ft_strlen((char *)src);
	if (size == 0)
		return (j);
	if (i >= size)
		j += size;
	else
		j += i;
	k = 0;
	while (src[k] && i + 1 < size)
	{
		dst[i] = src[k];
		k++;
		i++;
	}
	dst[i] = '\0';
	return (j);
}
