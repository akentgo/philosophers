/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:08:41 by akent-go          #+#    #+#             */
/*   Updated: 2023/04/24 16:01:54 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	hexa_length(unsigned int hex)
{
	int	res;

	res = 0;
	while (hex > 0)
	{
		hex /= 16;
		res++;
	}
	return (res);
}

void	puthexa(unsigned int hexa, const char format)
{
	if (hexa >= 16)
	{
		puthexa(hexa / 16, format);
		puthexa(hexa % 16, format);
	}
	else
	{
		if (hexa <= 9)
			ft_putchar_fd((hexa + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((hexa - 10 + 'a'), 1);
			else if (format == 'X')
				ft_putchar_fd((hexa - 10 + 'A'), 1);
		}
	}
}

int	w_hex(unsigned int hexa, const char format)
{
	if (hexa == 0)
		return (write(1, "0", 1));
	puthexa(hexa, format);
	return (hexa_length(hexa));
}
