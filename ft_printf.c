/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tditse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 10:33:13 by tditse            #+#    #+#             */
/*   Updated: 2018/08/25 11:13:01 by tditse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(char *fmt, ...)
{
	int		plen[4];
	char	opt[5];
	va_list	va;
	t_char	string;

	va_start(va, fmt);
	plen[3] = 0;
	while (*fmt)
	{
		ft_printf_init(&fmt, opt, plen, &string);
		if (*fmt)
		{
			get_tags(&fmt, opt, plen);
			if (ft_strindexof("sSpdDioOuUxXcC%", opt[4]) != -1)
			{
				fmt++;
				convert(va, opt, plen, string);
			}
			else
				set_undefined(&fmt, opt, plen, -7);
		}
	}
	va_end(va);
	return (plen[3]);
}

void	ft_printf_init(char **fmt, char *opt, int *plen, t_char *string)
{
	plen[3] += ft_strprintcount(*fmt, '%');
	(*fmt) += ft_strchrlen(*fmt, '%');
	set_params(plen, opt, string);
}
