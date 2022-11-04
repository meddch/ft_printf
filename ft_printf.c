/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:47:33 by mechane           #+#    #+#             */
/*   Updated: 2022/11/03 13:09:48 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char fmt)
{
	char	*s;

	s = "cspdiuxX%";
	while (*s)
	{
		if (fmt == *s)
			return (1);
		s++;
	}
	return (0);
}

int	printf_spe(va_list args, char fmt)
{
	int	count;

	count = 0;
	if (fmt == 'd' || fmt == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (fmt == 'u')
		count += ft_putnbr_unsi(va_arg(args, unsigned int));
	else if (fmt == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (fmt == 's')
		count += ft_putstr(va_arg(args, const char *));
	else if (fmt == 'x')
		count += ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (fmt == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (fmt == '%')
		count += ft_putchar('%');
	else if (fmt == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putnbr_ptr(va_arg(args, uintptr_t));
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	int		count;
	va_list	args;

	count = 0;
	if (!fmt)
		return (0);
	while (*fmt != '\0')
	{
		if (*fmt == '%' && check_format(*(fmt + 1)) != 0)
		{
			fmt++;
			count += printf_spe(args, *fmt);
		}
		else if (*fmt != '%')
			count += ft_putchar(*fmt);
		++fmt;
	}
	va_end(args);
	return (count);
}
