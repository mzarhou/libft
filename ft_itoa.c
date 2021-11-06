/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:47:36 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/06 13:00:21 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static char	*ft_add_char(char *str, char c)
{
	char	*new_str;
	int		str_len;

	if (!str)
	{
		str = (char *)malloc(2);
		if (!str)
			return (0);
		str[0] = c;
		str[1] = 0;
		return (str);
	}
	str_len = ft_strlen(str);
	new_str = (char *)malloc(str_len + 2);
	if (!new_str)
		return (0);
	ft_memcpy(new_str, str, str_len);
	new_str[str_len] = c;
	new_str[str_len + 1] = 0;
	return (new_str);
}

static char	*ft_reverse(char *str)
{
	int		i;
	int		j;
	char	temp;

	if (!str)
		return (0);
	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

void	ft_check_negatif(int *nb, int *is_negative)
{
	if (*nb < 0)
	{
		*is_negative = 1;
		*nb *= -1;
	}
}

char	*ft_itoa(int nb)
{
	char	*res;
	int		is_negative;

	is_negative = 0;
	res = 0;
	if (nb == INT_MIN)
	{
		res = ft_add_char(res, '8');
		nb /= 10;
	}
	ft_check_negatif(&nb, &is_negative);
	while (1)
	{
		res = ft_add_char(res, nb % 10 + '0');
		if (!res)
			return (0);
		if (nb / 10 == 0)
			break ;
		nb /= 10;
	}
	if (is_negative)
		res = ft_add_char(res, '-');
	return (ft_reverse(res));
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <limits.h>

// int main()
// {
// 	printf("%s\n", ft_itoa(INT_MIN));
// }
