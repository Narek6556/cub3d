/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 21:24:09 by naaghasy          #+#    #+#             */
/*   Updated: 2021/02/03 21:24:10 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*n_lst;
	t_list		*n_el;

	if (!lst || !f)
		return (NULL);
	if (!(n_el = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	n_lst = n_el;
	lst = lst->next;
	while (lst)
	{
		if (!(n_el = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&n_lst, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&n_lst, n_el);
	}
	return (n_lst);
}
