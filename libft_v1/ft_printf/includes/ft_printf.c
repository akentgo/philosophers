/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:42:09 by akent-go          #+#    #+#             */
/*   Updated: 2023/03/30 17:44:26 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	sol_length;

	sol_length = 0;
	if (format == 'c')
		sol_length += printchars(va_arg(args, int));
	else if (format == 's')
		sol_length += printstr(va_arg(args, char *));
	else if (format == 'i' || format == 'd')
		sol_length += print_numbers(va_arg(args, int));
	else if (format == 'u')
		sol_length += print_unsigned(va_arg(args, unsigned int));
	else if (format == 'X' || format == 'x')
		sol_length += w_hex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		sol_length += ptr_print(va_arg(args, unsigned long long));
	else if (format == '%')
		sol_length += printpercent();
	return (sol_length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		sol_length;
	int		i;

	va_start(args, str);
	sol_length = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{	
			sol_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			sol_length += printchars(str[i]);
		i++;
	}
	va_end(args);
	return (sol_length);
}
