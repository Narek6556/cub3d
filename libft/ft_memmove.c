/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:18:36 by naaghasy          #+#    #+#             */
/*   Updated: 2021/01/18 22:18:38 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t						i;
	unsigned	const	char	*str_src;
	unsigned	char			*str_dest;
	unsigned	char			temp[len];

	i = 0;
	str_src = src;
	str_dest = dest;
	while (i < len)
	{
		temp[i] = str_src[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		str_dest[i] = temp[i];
		i++;
	}
	return (dest);
}
