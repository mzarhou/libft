/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:04:26 by mzarhou           #+#    #+#             */
/*   Updated: 2021/11/05 21:49:44 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += ('a' - 'A');
	return (c);
}

// #include <stdio.h>

// int main()
// {
// 	char c = 'Z';

// 	printf("%c\n", ft_tolower(c));
// }
