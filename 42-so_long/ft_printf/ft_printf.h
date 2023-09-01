/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:49:35 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/08/05 13:50:26 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

unsigned int	ft_putnbr(int n);
int				ft_printf(const char *str, ...);
unsigned int	ft_put_char(int c);
unsigned int	ft_put_string(char *str);
unsigned int	ft_put_hex_pointer(size_t ptr);
unsigned int	ft_putnbr_unsigned(unsigned int n);
unsigned int	ft_put_hex_uint_lower(unsigned int i);
unsigned int	ft_put_hex_uint_upper(unsigned int i);
#endif