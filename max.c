/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tditse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 10:58:30 by tditse            #+#    #+#             */
/*   Updated: 2018/08/25 11:09:37 by tditse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		get_maxstrlen(t_char string, char *opt, int *plen)
{
	int	max;

	max = 0;
	if (opt[4] == 's' && !opt[3])
		max = ft_strlen(string.str);
	else if (opt[4] == 'S' || (opt[3] == 'l' && opt[4] == 's'))
		max = ft_wstrlen(string.wstr, plen[1]);
	else if (opt[4] == 'c' && !opt[3])
		max = 1;
	else
	{
		if (string.wchar <= 0x7F)
			max = 1;
		else if (string.wchar <= 0x7FF)
			max = 2;
		else if (string.wchar <= 0xFFFF)
			max = 3;
		else
			max = 4;
	}
	if (plen[1] >= 0 && opt[4] != 'c' && opt[4] != 'C')
		return (max > plen[1] ? plen[1] : max);
	else
		return (max);
}

int		get_maxnbrlen(long long int nbr, char *opt, int *plen)
{
	int		max;
	int		len;

	len = (nbr < 0) ? 1 : 0;
	set_base(opt, plen);
	if (ft_strindexof("dDi", opt[4]) != -1)
		len += nblen(nbr, plen[2]);
	else
		len = unblen((unsigned long long)nbr, plen[2]);
	max = (len > plen[1]) ? len : plen[1];
	if (max == plen[1] && !plen[0] && (opt[4] == 'o' || opt[4] == 'O'))
		max--;
	if ((opt[0] == '#' && (opt[4] == 'o' || opt[4] == 'O')) ||
			(opt[2] && opt[4] != '%'))
		max++;
	if ((opt[0] == '#' && (opt[4] == 'x' || opt[4] == 'X')) || opt[4] == 'p')
		max += 2;
	if (!nbr && !plen[1])
		max--;
	return (max);
}
