/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:41:21 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/07/04 12:41:21 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t len)
{
	unsigned char	*ptr_str;

	if (!str)
		return (NULL);
	ptr_str = (unsigned char *)str;
	while (len--)
		*(unsigned char *)str++ = (unsigned char)value;
	return (ptr_str);
}
