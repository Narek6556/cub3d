/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:14:56 by naaghasy          #+#    #+#             */
/*   Updated: 2021/01/18 14:14:58 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				length;
	unsigned	char	*str;

	str = b;
	length = 0;
	while (length < len)
	{
		str[length] = c;
		length++;
	}
	return (b);
}
