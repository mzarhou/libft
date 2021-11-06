/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:43:52 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/05 21:53:41 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*sub_str;
	unsigned int	i;
	unsigned int	str_len;

	str = (char *)s;
	str_len = ft_strlen(str);
	if (len < ft_strlen(str))
		str_len = len;
	else
		str_len = ft_strlen(str);
	sub_str = (char *)malloc(str_len + 1);
	if (!sub_str)
		return (0);
	if (start > str_len)
		return ((char *)ft_calloc(1, 1));
	str += start;
	i = 0;
	while (str && *str && str_len--)
		sub_str[i++] = *str++;
	sub_str[i] = '\0';
	return (sub_str);
}

// #include <stdio.h>
// int main()
// {
// 	char *s = ft_substr("tripouille", 23423, 1);
// 	printf("%s, %p", s, s);
// 	free(s);
// }
