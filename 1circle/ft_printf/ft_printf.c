/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:34:17 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/24 17:32:07 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_format(const char *str, va_list *ap)
{
	char	temp;
	int		print_len;

	print_len = 0;
	if (str[1] == 'c')
		print_len = ft_print_c(va_arg(*ap, int));
	else if (str[1] == 's')
		print_len = ft_print_s(va_arg(*ap, char *));
	else if (str[1] == 'd' || str[1] == 'i' || str[1] == 'u')
		print_len += ft_print_diu(va_arg(*ap, int));
	// else if (str[1] == 'p' || str[1] == 'x')
	// 	print_len += ft_print_px(str[1], &ap);
	// else if (str[1] == 'X')
	// 	print_len += ft_print_X(str[1], &ap);
	else
		print_len += write(1, "%", 1);
	return (print_len);
}

int	ft_input_check(const char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '%')
		{
			if (!ft_strchr("cspdiuxX%", str[++idx]))
				return (-1);
		}
		idx++;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		idx;
	int		len;

	va_start(ap, str);
	if (!ft_input_check(str))
		return (0);
	while (str[idx])
	{
		if (*str == '%')
			len += ft_format(&str[idx++], &ap);
		else
			len += write(1, &str[idx], 1);
		idx++;
	}
	va_end(ap);
	return (len);
}
