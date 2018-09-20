/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tditse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:10:04 by tditse            #+#    #+#             */
/*   Updated: 2018/08/25 11:13:20 by tditse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putwstr(wchar_t *ws, int len)
{
	int	i;

	i = 0;
	while (ws[i] && len >= 0)
	{
		if (ws[i] <= 0x7F)
			len -= 1;
		else if (ws[i] <= 0x7FF)
			len -= 2;
		else if (ws[i] <= 0xFFFF)
			len -= 3;
		else
			len -= 4;
		if (len >= 0)
			ft_putwchar(ws[i]);
		i++;
	}
}
