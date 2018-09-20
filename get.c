/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tditse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:01:55 by tditse            #+#    #+#             */
/*   Updated: 2018/08/25 11:36:55 by tditse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_tags(char **fmt, char *opt, int *plen)
{
	(*fmt)++;
	get_flags(fmt, opt);
	if (ft_isdigit(**fmt))
	{
		plen[0] = ft_atoi(*fmt);
		*fmt += nblen(plen[0], 10);
	}
	get_precision(fmt, plen);
	get_length(fmt, opt);
	error_duplicate(fmt, opt, plen);
	opt[4] = **fmt;
	error_tags(opt);
}

void	get_precision(char **fmt, int *plen)
{
	if (**fmt == '.')
	{
		while (**fmt == '.')
			(*fmt)++;
		if (ft_isdigit(*(*(fmt))))
		{
			plen[1] = ft_atoi(*(fmt));
			*fmt += nblen(plen[1], 10);
		}
	}
	else
		plen[1] = -1;
}

void	get_flags(char **fmt, char *opt)
{
	while (**fmt && ft_strindexof("#+- 0", **fmt) != -1)
	{
		if (**fmt == '#' && !opt[0])
			opt[0] = '#';
		if (**fmt == '0' && opt[1] != '-')
			opt[1] = **fmt;
		if (**fmt == '-')
			opt[1] = **fmt;
		if (**fmt == ' ' && !opt[2])
			opt[2] = **fmt;
		if (**fmt == '+')
			opt[2] = **fmt;
		(*fmt)++;
	}
}

void	get_length(char **fmt, char *opt)
{
	while (**fmt && ft_strindexof("hjzl", **fmt) != -1)
	{
		if (**fmt == *(*fmt + 1) || *(*fmt + 1) == 'h')
		{
			if (**fmt == 'h' || **fmt == 'l')
				opt[3] = **fmt - 32;
			else
				opt[3] = 'L';
			(*fmt)++;
		}
		else
			opt[3] = **fmt;
		(*fmt)++;
	}
}
