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

	head = 0;
	while (lst != 0)
	{
		current = ft_lstnew(f(lst->content));
		if (!current)
		{
			if (head != 0)
				ft_lstclear(&head, del);
			return (NULL);
		}
		if (!head)
			head = current;
		else
			previous->next = current;
		previous = current;
		lst = lst->next;
	}
	return (head);
}
