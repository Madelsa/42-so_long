/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:50:46 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/07/04 13:50:46 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*strcpy;
	int		i;

	if (!src)
		return (NULL);
	strcpy = malloc(ft_strlen(src) + 1);
	if (strcpy != NULL)
	{
		i = -1;
		while (src[++i])
			strcpy[i] = src[i];
		strcpy[i] = '\0';
	}
	return (strcpy);
}
