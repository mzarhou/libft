/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:40:00 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/08 18:12:10 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst_ptr, void (*del)(void*))
{
	t_list	*list;
	t_list	*next_el;

	if (!lst_ptr)
		return ;
	list = *lst_ptr;
	while (list)
	{
		next_el = list->next;
		ft_lstdelone(list, del);
		list = next_el;
	}
	*lst_ptr = 0;
}
