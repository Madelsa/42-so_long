/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:49:18 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/07/05 14:49:18 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num_bytes)
{
	unsigned char	*dest_ptr;

	if (!dest || !src)
		return (NULL);
	dest_ptr = (unsigned char *)dest;
	if (dest == src)
		return (dest);
	if (dest < src)
	{
		while (num_bytes--)
			*dest_ptr++ = *(unsigned char *)src++;
	}
	else
	{
		dest_ptr += num_bytes;
		src += num_bytes;
		while (num_bytes--)
			*(--dest_ptr) = *(unsigned char *)(--src);
	}
	return (dest);
}
