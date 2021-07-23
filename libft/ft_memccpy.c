/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:14:30 by naaghasy          #+#    #+#             */
/*   Updated: 2021/01/18 22:14:33 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t						i;
	unsigned	char			*str_src;
	unsigned	char			*str_dest;

	str_dest = dest;
	str_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (str_src[i] == c)
		{
			str_dest[i] = str_src[i];
			return (str_dest + i + 1);
		}
		str_dest[i] = str_src[i];
		i++;
	}
	return (0);
}
