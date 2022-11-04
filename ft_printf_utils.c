/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:47:50 by mechane           #+#    #+#             */
/*   Updated: 2022/11/02 11:44:15 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{	
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr_unsi(unsigned int nbr)
{
	int			count;
	const char	*base;

	count = 0;
	base = "0123456789";
	if (nbr < 10)
		count += ft_putchar(base[nbr]);
	else
	{
		count += ft_putnbr_unsi(nbr / 10);
		count += ft_putchar(base[nbr % 10]);
	}
	return (count);
}

int	ft_putnbr_ptr(uintptr_t nbr)
{
	int			count;
	const char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (nbr < 16)
		count += ft_putchar(base[nbr]);
	else
	{
		count += ft_putnbr_ptr(nbr / 16);
		count += ft_putchar(base[nbr % 16]);
	}
	return (count);
}
