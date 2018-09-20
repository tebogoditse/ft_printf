/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tditse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:26:45 by tditse            #+#    #+#             */
/*   Updated: 2018/08/25 11:10:47 by tditse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_params(int *plen, char *opt, t_char *string)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (i < 3)
			plen[i] = 0;
		opt[i] = 0;
		i++;
	}
	(*string).wchar = 0;
	(*string).wstr = 0;
	(*string).c = 0;
	(*string).str = 0;
}

void	set_undefined(char **fmt, char *opt, int *plen, int total)
{
	int	i;

	if ((opt[4] == 'c' || opt[4] == 's') && !plen[1])
		plen[1] = -1;
	i = plen[0] - ((total < 0) ? 1 : total);
	if (opt[1] == '0')
		ft_putnchar('0', i);
	else if ((opt[2] == ' ' || (!opt[2])) && !opt[1])
		ft_putnchar(' ', i);
	if (plen[0] != 0 && total < 0)
		plen[3] += plen[0] + (total == -7 ? -1 : total);
	if (total == -7)
	{
		if (opt[4])
		{
			write(1, &opt[4], 1);
			plen[3]++;
			(*fmt)++;
		}
		if (opt[1] == '-' && plen[0] > plen[1])
			ft_putnchar(' ', plen[0] - (total > 0 ? total : 1));
	}
}

void	set_base(char *opt, int *plen)
{
	if (opt[4] == 'x' || opt[4] == 'X' || opt[4] == 'p')
		plen[2] = 16;
	else if (opt[4] == 'o' || opt[4] == 'O')
		plen[2] = 8;
	else
		plen[2] = 10;
	if (opt[4] == '%')
		plen[1] = -1;
}
