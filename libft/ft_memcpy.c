/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:45:05 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/07/04 10:45:05 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num_bytes)
{
	unsigned char	*dest_ptr;

	if (!src)
		return ((char *)dest);
	if (!dest)
		return (NULL);
	dest_ptr = (unsigned char *)dest;
	while (num_bytes--)
		*dest_ptr++ = *(unsigned char *)src++;
	return (dest);
}
