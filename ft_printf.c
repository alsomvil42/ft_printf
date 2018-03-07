/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 03:18:32 by alsomvil          #+#    #+#             */
/*   Updated: 2018/02/27 12:05:13 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <locale.h>

char	*ft_checkarg(t_struct *save, char *str, int *temp, int i)
{
	char	*stockarg;

	while (str[i] && str[i] != 's' && str[i] != 'S' && str[i] != 'p'
			&& str[i] != 'd' && str[i] != 'D' && str[i] != 'i'
			&& str[i] != 'o' && str[i] != 'O' && str[i] != 'u'
			&& str[i] != 'U' && str[i] != 'x' && str[i] != 'X'
			&& str[i] != 'c' && str[i] != 'C' && str[i] != '%')
	{
		i++;
		(*temp)++;
	}
	stockarg = ft_strndup(str, i);
	save->conversion = str[i];
	return (stockarg);
}

int		ft_nextarg(va_list test, t_struct *save, char *tmpformat, int i)
{
	int		temp;
	int		j;
	char	*nextarg;

	temp = 0;
	j = 0;
	while (tmpformat[i] && tmpformat[i] != '%')
		i++;
	if (tmpformat[i] == '%')
	{
		nextarg = ft_checkarg(save, &tmpformat[i + 1], &temp, 0);
		j = ft_stockmodif(save, &tmpformat[i + 1], 0, temp);
		if (nextarg != NULL)
			ft_apply(test, save);
		nextarg = NULL;
	}
	return (j + 1);
}

int		ft_printstart(t_struct *save, char *tmpformat, int *i)
{
	while (tmpformat[*i] && tmpformat[*i] != '%')
	{
		save->retour = save->retour + 1;
		ft_putchar(tmpformat[*i]);
		(*i)++;
	}
	if (tmpformat[*i] == '%')
		return (1);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		test;
	char		*tmpformat;
	int			i;
	t_struct	save;

	i = 0;
	save.retour = 0;
	tmpformat = ft_strdup(format);
	va_start(test, format);
	ft_bzero(&save, sizeof(t_struct));
	while (ft_printstart(&save, tmpformat, &i) == 1)
	{
		i = i + (ft_nextarg(test, &save, &tmpformat[i], 0));
	}
	va_end(test);
	return (save.retour);
}
