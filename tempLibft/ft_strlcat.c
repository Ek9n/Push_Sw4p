/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:02:55 by hstein            #+#    #+#             */
/*   Updated: 2022/12/18 22:01:33 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*dst && i < dstsize)
	{
		dst++;
		i++;
	}
	return (ft_strlcpy(dst, src, dstsize - i) + i);
}
// size_t    ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
//     char		*ptr_dst;
//     const char	*ptr_src;
//     size_t		dstlen;
//     size_t		buf_dstsize;
// 
//     ptr_dst = dst;
//     ptr_src = src;
//     dstlen = 0;
//     buf_dstsize = dstsize - 1;
//     if (dstsize != 0 && buf_dstsize != 0)
//     {
//         while (*ptr_dst)
//         {
//             ptr_dst++;
//             dstlen++;
// 		}
// 		while (buf_dstsize && *ptr_src != '\0')
//         {
//             *ptr_dst++ = *ptr_src++;
// 			buf_dstsize--;
//         }
//         if (dstsize > dstlen)
//             *ptr_dst = '\0';
//     }
//     return (dstlen + ft_strlen(src));
// }
// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	char		*ptr_dst;
// 	const char	*ptr_src;
// 	size_t		len_dst;
// 
// 	ptr_dst = dst;
// 	ptr_src = src;
// 	len_dst = 0;
// 	if (dstsize > 0)
// 	{
// 		while (*ptr_dst != '\0')
// 		{
// 			len_dst++;
// 			ptr_dst++;
// 			dstsize--;
// 		}
// 		if (len_dst <= dstsize)
// 		{	
// 			while (dstsize-- && *ptr_src != '\0')
// 				*ptr_dst++ = *ptr_src++;
// 			*ptr_dst = '\0';
// 		}
// 	}
// 	return (len_dst + ft_strlen(src));
// }
