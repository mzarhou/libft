/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcp7 <thcp7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:03:28 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/04 11:12:11 by thcp7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		t_len;
	int		i;

	i = 0;
	t_len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)ft_calloc(t_len + 1, 1);
	if (!res)
		return (0);
	while (s1 && *s1 && i < t_len)
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	while (s2 && *s2 && i < t_len)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = 0;
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*res;
// 	char	s1[] = "Mohamed";
// 	char	s2[] = "Jamal";

// 	res = ft_strjoin(s1, s2);
// 	printf("%s\n", res);
// }
