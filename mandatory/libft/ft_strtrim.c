/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a0ec6397 <a0ec6397@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:23:55 by mahmoud           #+#    #+#             */
/*   Updated: 2023/09/05 20:19:44 by a0ec6397         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	end = (char *)s1 + ft_strlen(s1) - 1;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (end > s1 && ft_strrchr(set, *end))
		end--;
	str = (char *)malloc(sizeof(char) * (end - s1) + 2);
	if (!str)
		return (NULL);
	start = str;
	while (s1 <= end)
		*str++ = *s1++;
	*str = '\0';
	return ((char *)start);
}
