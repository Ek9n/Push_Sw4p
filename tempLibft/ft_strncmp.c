/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:04:36 by hstein            #+#    #+#             */
/*   Updated: 2023/04/17 03:10:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && n > 0 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n)
		return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
	return (0);
}
