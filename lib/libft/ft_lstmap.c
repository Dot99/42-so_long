/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:17:04 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/17 10:52:22 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*first;
	t_list	*new;
	void	*set;

	if (!f || !del || !lst)
		return (NULL);
	first = NULL;
	new = NULL;
	while (lst)
	{
		set = f(lst->content);
		new = ft_lstnew(set);
		if (!new)
		{
			del(set);
			ft_lstclear(&first, (*del));
			return (first);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
