/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:25:07 by naaghasy          #+#    #+#             */
/*   Updated: 2021/01/18 22:25:10 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	char			*str;
	unsigned	char			*last_st;

	str = (unsigned char *)s;
	last_st = (unsigned char *)(s + n);
	while (str != last_st)
	{
		if (*str == (unsigned char)c)
			return ((void*)str);
		str++;
	}
	return (0);
}
