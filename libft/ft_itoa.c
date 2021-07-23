/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:33:34 by naaghasy          #+#    #+#             */
/*   Updated: 2021/01/26 17:33:38 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_num_len(int n)
{
	int		num_len;

	num_len = 0;
	while (n != 0)
	{
		n = n / 10;
		num_len++;
	}
	return (num_len);
}

char			*ft_itoa(int n)
{
	char				*number;
	int					i;
	int					k;
	int					num_len;
	long				n_n;

	i = 0;
	n_n = n;
	num_len = ft_count_num_len(n);
	k = (n < 0) ? num_len + 1 : num_len;
	k = (n == 0) ? k + 1 : k;
	if (!(number = malloc(k + 1)))
		return (0);
	number[k] = '\0';
	while (k >= 1)
	{
		if (n_n < 0)
			n_n = -n_n;
		number[k - 1] = (n_n % 10) + '0';
		n_n /= 10;
		k--;
	}
	if (n < 0)
		number[0] = '-';
	return (number);
}
