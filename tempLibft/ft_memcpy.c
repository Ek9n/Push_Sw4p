/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:02:10 by hstein            #+#    #+#             */
/*   Updated: 2022/12/22 19:56:52 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptr_dest;
	const char	*ptr_src;

	if (!dest && !dest)
		return (NULL);
	ptr_dest = (char *) dest;
	ptr_src = (char *) src;
	while (n--)
		*ptr_dest++ = *ptr_src++;
	return (dest);
}
