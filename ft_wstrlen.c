/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tditse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:16:01 by tditse            #+#    #+#             */
/*   Updated: 2018/08/25 11:08:28 by tditse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_wstrlen(wchar_t *ws, int max)
{
	int	i;
	int	len;

	if (!ws)
		return (-1);
	i = 0;
	len = 0;
	if (max == -1)
		max = 2147483647;
	while (ws[i])
	{
		if (len + 1 <= max && ws[i] <= 0x7F)
			len += 1;
		else if (len + 2 <= max && ws[i] <= 0x7FF)
			len += 2;
		else if (len + 3 <= max && ws[i] <= 0xFFFF)
			len += 3;
		else if (len + 4 <= max)
			len += 4;
		i++;
	}
	return (len);
}
