/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:53:17 by naaghasy          #+#    #+#             */
/*   Updated: 2021/02/05 23:14:21 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		splited_char_count(char const *str, char c)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i++] != c)
			j++;
		if (j)
			count++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	int		k;
	int		count;
	char	**d;

	i = 0;
	k = 0;
	count = splited_char_count(s, c);
	d = malloc((count + 1) * sizeof(char*));
	while (i < count)
	{
		j = 0;
		while (s[k] && s[k++] != c)
			j++;
		if (j)
		{
			if (s[k] || s[ft_strlen(s) - 1] == c)
				d[i++] = ft_substr(s, (k - j - 1), j);
			else
				d[i++] = ft_substr(s, (k - j), j);
		}
	}
	d[i] = 0;
	return (d);
}
