/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:03:03 by naaghasy          #+#    #+#             */
/*   Updated: 2021/01/18 16:03:05 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t				length;
	unsigned	char	*str;

	str = s;
	length = 0;
	while (length < n)
	{
		str[0] = 0;
		length++;
		str++;
	}
}
