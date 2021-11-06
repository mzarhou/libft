/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:36:11 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/06 14:33:31 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_get_start(char const *s1, char const *set)
{
	while (s1 && *s1)
	{
		if (!ft_strchr(set, *s1))
			return (s1);
		s1++;
	}
	return (s1);
}

static const char	*ft_get_end(char const *s1, char const *set)
{
	int	len;

	len = ft_strlen(s1);
	s1 += len - 1;
	while (s1 && *s1 && len--)
	{
		if (!ft_strchr(set, *s1))
			return (s1);
		s1--;
	}
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;

	if (!s1)
		return (0);
	start = ft_get_start(s1, set);
	end = ft_get_end(s1, set);
	if (start > end)
		return (((char *)s1) + ft_strlen(s1));
	return (ft_substr(s1, start - s1, end - start + 1));
}

// int main()
// {
// 	char *res = ft_strtrim("   xxxtripouille", " x");
// 	printf("%s\n", res);
// }
