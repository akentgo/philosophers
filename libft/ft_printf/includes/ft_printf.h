/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:53:33 by akent-go          #+#    #+#             */
/*   Updated: 2023/07/09 10:25:21 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

/* ft_print_chars.c */

int		printchars(int c);
int		printstr(char *str);
int		printpercent(void);

/* ft_print_hex.c */
int		hexa_length(unsigned int length);
void	puthexa(unsigned int hexa, const char format);
int		w_hex(unsigned int hexa, const char format);

/* ft_print_nums.c */
int		print_numbers(int n);
int		print_unsigned(unsigned int n);

/* ft_print_ptr.c */
int		ptr_size(uintptr_t ptr);
int		ptr_print(uintptr_t ptr);

int		ft_printf(const char *str, ...);

#endif
