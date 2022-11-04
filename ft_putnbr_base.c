/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:47:44 by mechane           #+#    #+#             */
/*   Updated: 2022/11/02 11:43:12 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	long	n;
	int		count;
	char	*base;

	base = "0123456789";
	count = 0;
	n = nbr;
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
		count += ft_putchar(base[n]);
	else
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(base[n % 10]);
	}
	return (count);
}

int	ft_putnbr_hex(unsigned int nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr < 16)
		count += ft_putchar(base[nbr]);
	else
	{
		count += ft_putnbr_hex(nbr / 16, base);
		count += ft_putchar(base[nbr % 16]);
	}
	return (count);
}
