/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:48:24 by naaghasy          #+#    #+#             */
/*   Updated: 2021/01/22 15:48:27 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*sub_str;
	size_t				i;
	size_t				length;
	size_t				for_comp;

	i = 0;
	if (start > ft_strlen(s))
	{
		if (!(sub_str = malloc(sizeof(char) * 1)))
			return (NULL);
		sub_str[0] = '\0';
		return (sub_str);
	}
	for_comp = ft_strlen((char *)s + start);
	length = (len > for_comp) ? for_comp : len;
	if (!(sub_str = malloc((length + 1) * sizeof(char))))
		return (NULL);
	while (i < length)
	{
		sub_str[i] = s[start];
		i++;
		start++;
	}
	sub_str[i] = 0;
	return (sub_str);
}
