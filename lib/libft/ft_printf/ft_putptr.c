/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:35:41 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/18 16:52:12 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	putptrhex(unsigned long nbr, const char c)
{
	char	*base;
	int		result;

	result = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		result += putptrhex((nbr / 16), c);
		result += putptrhex((nbr % 16), c);
	}
	else
	{
		result += write(1, &base[nbr], 1);
	}
	return (result);
}

int	ft_putptr(void *nbr)
{
	int				result;
	unsigned long	n;

	n = (unsigned long)nbr;
	result = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	result += ft_printstr("0x");
	if (n == 0)
		result += ft_putchar(0);
	else
		result += putptrhex(n, 'x');
	return (result);
}
