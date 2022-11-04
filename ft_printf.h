/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:48:31 by mechane           #+#    #+#             */
/*   Updated: 2022/11/02 22:26:16 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putnbr(int nbr);
int	ft_putstr(const char *str);
int	ft_putnbr_unsi(unsigned int nbr);
int	ft_putnbr_ptr(uintptr_t nbr);
int	ft_printf(const char *fmt, ...);
int	ft_putnbr_hex(unsigned int nbr, char *base);

#endif