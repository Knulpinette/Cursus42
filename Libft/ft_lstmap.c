/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:14:33 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/22 15:14:35 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*current;
	t_list	*previous;

	if (!lst)
		return (NULL);
	current = ft_lstnew(f(lst->content));
	if (!current)
		return (NULL);
	head = current;
	previous = current;
	lst = lst->next;
	while (lst != 0)
	{
		current = ft_lstnew(f(lst->content));
		if (!current)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		previous->next = current;
		previous = current;
		lst = lst->next;
	}
	return (head);
}
