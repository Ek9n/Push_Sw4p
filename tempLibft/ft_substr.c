/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 00:43:24 by hstein            #+#    #+#             */
/*   Updated: 2022/12/13 21:29:46 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;

	substring = malloc(sizeof(*s) * len + 1);
	if (substring)
	{
		i = 0;
		while (*(s + start) && i < len)
			*(substring + i++) = *(s + start++);
		*(substring + i) = '\0';
		return (substring);
	}
	return (NULL);
}
