/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 07:07:13 by alsomvil          #+#    #+#             */
/*   Updated: 2018/02/01 08:38:40 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkflag(t_struct *save, char *str, int *i)
{
	if (str[0] == 'h')
	{
		if (str[1] && str[1] == 'h')
		{
			save->flaghh = 1;
			(*i)++;
		}
		else
			save->flagh = 1;
	}
	if (str[0] == 'l')
	{
		if (str[1] && str[1] == 'l')
		{
			save->flagll = 1;
			(*i)++;
		}
		else
			save->flagl = 1;
	}
}

void	ft_checkoptionone(t_struct *save, char *str, int *i)
{
	if (str[0] == '#')
		save->dieze = 1;
	if (str[0] == '0')
		save->zero = 1;
	if (str[0] == '-')
		save->neg = 1;
	if (str[0] == ' ')
		save->space = 1;
	if (str[0] == '+')
		save->pos = 1;
	if (str[0] == 'j')
		save->flagj = 1;
	if (str[0] == 'z')
		save->flagz = 1;
	ft_checkflag(save, str, i);
}

void	ft_checksize(t_struct *save, char *str, int *i, int temp)
{
	int		n;
	int		j;

	n = 1;
	j = 0;
	if (str[j] >= '1' && str[j] <= '9' && *i < temp)
	{
		j++;
		while (str[j] && str[j] >= '0' && str[j] <= '9' && *i < temp)
		{
			j++;
			(*i)++;
			n++;
		}
		save->largueur = ft_strndup(str, n);
	}
	if (*i < temp)
		ft_checkoptionone(save, str, i);
}

int		ft_stockmodif(t_struct *save, char *str, int i, int temp)
{
	int		test;
	int		n;

	test = 0;
	n = 0;
	while (str[i] && i < temp)
	{
		if (str[i] == '.')
		{
			if (str[++i] >= '1' && str[i] <= '9')
			{
				test = i;
				while (str[i] >= '0' && str[i] <= '9' && n++ > -1)
					i++;
				save->precision = ft_strndup(&str[test], n);
			}
			else
				i++;
		}
		if (i < temp)
		{
			ft_checksize(save, &str[i], &i, temp);
			i++;
		}
	}
	return (i + 1);
}
