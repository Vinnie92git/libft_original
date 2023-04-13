/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:04:18 by vipalaci          #+#    #+#             */
/*   Updated: 2023/04/13 13:06:05 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_clear(void *i, t_list *new, void del(void *))
{
	(del)(i);
	ft_lstclear(&new, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	void	*i;

	i = 0;
	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		i = f(lst->content);
		if (!i)
			return (ft_clear(i, new, del));
		tmp = ft_lstnew(i);
		if (!tmp)
		{
			return (ft_clear(i, new, del));
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
