/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:17:52 by naaghasy          #+#    #+#             */
/*   Updated: 2021/01/22 19:17:54 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *set, char s)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	unsigned	int	front;
	unsigned	int	back;
	unsigned	int	i;
	char			*s;

	front = 0;
	i = 0;
	while (s1[front] && ft_check(set, s1[front]))
		front++;
	back = ft_strlen(s1);
	while (back > front && ft_check(set, s1[back - 1]))
		back--;
	s = (char *)malloc(back - front + 1);
	if (!s)
		return (NULL);
	while (front < back)
		s[i++] = s1[front++];
	s[i] = 0;
	return (s);
}
