/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:25:02 by hstein            #+#    #+#             */
/*   Updated: 2022/12/19 15:25:02 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cntstr(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i + 1] != '\0' && s[i] != c)
				i++;
		}
		i++;
	}
	return (cnt);
}

static char	**ft_makearray(char const *s, char c)
{
	char	**arr;

	arr = malloc((ft_cntstr(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[ft_cntstr(s, c)] = NULL;
	return (arr);
}

static char	**ft_outsourced(char **array, const char *ptr_hold, \
								const char *ptr_move, char **rows)
{
	*rows = malloc(ptr_move - ptr_hold + 1);
	if (!*rows)
		return (NULL);
	ft_strlcpy(*rows, ptr_hold, ptr_move - ptr_hold + 1);
	if (!(*rows))
	{
		free(*rows);
		free(array);
		return (NULL);
	}
	return (++rows);
}

static void	ft_skipc(const char **ptr_hold, char c)
{
	while (**ptr_hold && **ptr_hold == c)
		(*ptr_hold)++;
}

char	**ft_split(char const *s, char c)
{
	char		**array;
	char		**rows;
	const char	*ptr_hold;
	const char	*ptr_move;

	array = ft_makearray(s, c);
	if (!array)
		return (NULL);
	rows = array;
	ptr_hold = (const char *)s;
	ft_skipc(&ptr_hold, c);
	while (*ptr_hold != '\0')
	{
		if (*ptr_hold != c)
		{
			ptr_move = ptr_hold;
			while (*ptr_move != c && *ptr_move)
				ptr_move++;
			rows = ft_outsourced(array, ptr_hold, ptr_move, rows);
			ptr_hold = ptr_move;
			ft_skipc(&ptr_hold, c);
		}
	}
	return (array);
}
