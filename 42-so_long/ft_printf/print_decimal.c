/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:08:50 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/08/05 13:50:02 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbr(int n)
{
	long			n_cast;
	unsigned int	count;

	count = 0;
	n_cast = (long)n;
	if (n_cast < 0)
	{
		ft_put_char('-');
		n_cast *= -1;
		count++;
	}
	if (n_cast > 9)
		count += ft_putnbr(n_cast / 10);
	ft_put_char((n_cast % 10) + '0');
	count++;
	return (count);
}

unsigned int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr(n / 10);
	ft_put_char((n % 10) + '0');
	count++;
	return (count);
}
