/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:52:29 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/06 13:13:07 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include <stdlib.h>

static void	ft_remove_el(
	t_list **root, t_list *del_element, void (*del)(void *))
{
	if (!root)
		return ;
	if (*root == del_element)
	{
		*root = (*root)->next;
		ft_lstdelone(del_element, del);
		return ;
	}
	while (*root)
	{
		if ((*root)->next == del_element)
		{
			(*root)->next = (*root)->next->next;
			ft_lstdelone(del_element, del);
			break ;
		}
		*root = (*root)->next;
	}
}

static void	ft_add_el(t_list **new_list, void *content)
{
	if (!*new_list)
		*new_list = ft_lstnew(content);
	else
		ft_lstadd_back(new_list, ft_lstnew(content));
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	*new_list;
	void	*content;
	t_list	*del_el;

	new_list = 0;
	while (lst)
	{
		content = (*f)(lst->content);
		if (!content)
		{
			del_el = lst;
			lst = lst->next;
			ft_remove_el(&root, del_el, del);
			continue ;
		}
		ft_add_el(&new_list, content);
		lst = lst->next;
	}
	return (new_list);
}
