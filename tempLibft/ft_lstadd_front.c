/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:53:34 by hstein            #+#    #+#             */
/*   Updated: 2022/12/29 17:53:34 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Description
Function name			ft_lstadd_front
Prototype				void ft_lstadd_front(t_list **lst, t_list *new);
Turn in files			-
Parameters				lst: The address of a pointer to the first link of a list.
						new: The address of a pointer to the node to be added to the list.
Return value			None
External functs.		None
Description				Adds the node ’new’ at the beginning of the list.
----------------------------------------------------------------------
	typedef struct s_list
	{
		void			*content;
		struct s_list	*next;
	}	t_list;

	t_list	*ft_lstnew(void *content)
	{
		t_list	*node;

		node = malloc(sizeof(t_list));
		if (!node)
			return (NULL);
		node->content = content;
		node->next = NULL;
		return (node);
	}
*/
// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*node;

// 	node = malloc(sizeof(t_list));
// 	if (!node)
// 		return (NULL);
// 	node->content = content;
// 	node->next = NULL;
// 	return (node);
// }

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
int    main()
{
	t_list	*head;
	t_list	*list;
	t_list	*list2;
	// t_list	**first;

	// first = list;
	char	str[] = "One";
	char	str2[] = "Two";

	head = NULL;
	list = ft_lstnew(str);
	// printf("%s\n", (char *)list->content);
	list2 = ft_lstnew(str2);
	ft_lstadd_front(&head, list);
	ft_lstadd_front(&head, list2);
	printf("%s\n", (char *)list->content);
	printf("%s\n\n", (char *)list2->content);
	// printf("%s\n", (char *)head->content);

	// printf("%s\n", (char *)head->content);
	// printf("%s\n", );

	if (!head)
		printf("BULLSHIT\n");
    printf("%sb\n", (char *)head->content);

    while (head)
    {
        printf("%s\n", (char *)head->content);
        head = head->next;
    }

	free(list);
	free(list2);
}
*/