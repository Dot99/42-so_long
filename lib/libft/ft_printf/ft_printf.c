/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:23:10 by gude-jes          #+#    #+#             */
/*   Updated: 2024/06/18 16:52:05 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_check(const char *str, int i, va_list ap)
{
	if (str[i] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (str[i] == 's')
		return (ft_printstr(va_arg(ap, char *)));
	else if (str[i] == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_printnbr(va_arg(ap, int)));
	else if (str[i] == 'u')
		return (ft_uitoa(va_arg(ap, unsigned int)));
	else if (str[i] == 'x' || str[i] == 'X')
		return (ft_putnbrhex(va_arg(ap, int), str[i]));
	else if (str[i] == '%')
		return (ft_printpercent());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (!str || *str == '\0')
		return (0);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (!ft_strchr("cspdiuxX%", str[i]))
				i++;
			ret += ft_check(str, i, ap);
		}
		else
			ret += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (ret);
}
