/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:23:34 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/08/29 15:16:29 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new_nodes)
{
	t_list	*node;

	if (lst == NULL || new_nodes == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new_nodes;
		return ;
	}
	node = *lst;
	while (node->next != NULL)
		node = node->next;
	node->next = new_nodes;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*next;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	node = *lst;
	while (node != NULL)
	{
		next = node->next;
		del(node->content);
		free(node);
		node = next;
	}
	*lst = NULL;
}

static char	*create_empty_string(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	begin;
	char	*str;

	i = 0;
	begin = i;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	if (s1[i] == '\0')
		return (create_empty_string());
	while (ft_strchr(set, s1[j]) != NULL)
		j--;
	str = (char *)malloc((j - i + 2) * sizeof(char));
	if (str == NULL)
		return (str);
	while (i <= j)
		str[begin++] = s1[i++];
	str[begin] = '\0';
	return (str);
}
