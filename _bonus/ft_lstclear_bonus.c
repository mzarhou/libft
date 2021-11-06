/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:40:00 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/06 14:20:10 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst_ptr, void (*del)(void*))
{
	t_list	*list;

	if (!lst_ptr)
		return ;
	list = *lst_ptr;
	while (list)
	{
		ft_lstdelone(list, del);
		list = list->next;
	}
	*lst_ptr = 0;
}
