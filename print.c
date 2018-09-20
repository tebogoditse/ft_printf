/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tditse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:25:22 by tditse            #+#    #+#             */
/*   Updated: 2018/08/25 11:09:45 by tditse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_str(char *opt, int *plen, t_char string)
{
	int	total;

	total = get_maxstrlen(string, opt, plen);
	if (opt[4] == 's' && plen[1] && !opt[3] && string.str == NULL)
		total = 6;
	set_undefined(NULL, opt, plen, total);
	if (opt[4] == 's' && !opt[3])
		total == 0 ? ft_putlenstr(NULL, -1) : ft_putlenstr(string.str, total);
	else if (opt[4] == 'c' && !opt[3])
		ft_putchar(string.c);
	else if (opt[4] == 'S' || (opt[3] == 'l' && opt[4] == 's'))
	{
		if (total == -1)
		{
			ft_putlenstr("(null)", 6);
			total = 6;
		}
		else
			ft_putwstr(string.wstr, total);
	}
	else
		ft_putwchar(string.wchar);
	plen[3] += total > plen[0] ? total : plen[0];
	if (opt[1] == '-')
		ft_putnchar(' ', plen[0] - total);
}

void	print_nbr(char *opt, int *plen, long long int nbr)
{
	int	max;

	if (!nbr && opt[4] != 'o' && opt[4] != 'O')
		opt[0] = 0;
	if (!nbr && plen[1] == -1 && opt[4] == 'o' && opt[0] == '#')
		plen[1] = 0;
	max = get_maxnbrlen(nbr, opt, plen);
	plen[3] += BIGGER(max, BIGGER(plen[0], plen[1]));
	print_opt(opt, plen, max, nbr);
	if (plen[2] == 16 && opt[4] == 'X')
		plen[2] = 1;
	if (opt[4] == '%')
		write(1, "%", 1);
	if ((nbr || plen[1]) && opt[4] != '%')
		print_base(plen[2], nbr, opt);
	if (opt[1] == '-' && plen[0] > plen[1])
		ft_putnchar(' ', plen[0] - max);
}

void	print_opt(char *opt, int *plen, int max, long long int nbr)
{
	if ((!opt[1] || (opt[1] == '0' && plen[1] >= 0)))
		ft_putnchar(' ', plen[0] - max);
	if (opt[2] && opt[4] != '%')
		write(1, &opt[2], 1);
	if ((opt[0] == '#'
				&& (opt[4] == 'X' || opt[4] == 'x')) || opt[4] == 'p')
		opt[4] == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
	if (opt[0] == '#' && (opt[4] == 'o' || opt[4] == 'O'))
	{
		write(1, "0", 1);
		plen[1] -= plen[1] > 0 ? 1 : 0;
	}
	if (opt[1] == '0' && plen[1] == -1)
		ft_putnchar('0', plen[0] - max);
	if (plen[1] > 0)
		ft_putnchar('0', plen[1] - nblen(nbr, plen[2]));
}

void	print_base(int base, long long int nbr, char *opt)
{
	char	*out;

	if (base == 1)
		base = -16;
	if (ft_strindexof("dDi", opt[4]) != -1)
		out = (nbr == -9223372036854775807 - 1) ?
			ft_strdup("-9223372036854775808") : ft_itoa_base(nbr, base);
	else
		out = ft_uitoa_base((unsigned long long int)nbr, base);
	ft_putlenstr(out, ft_strlen(out));
	ft_memdel((void *)&out);
}
