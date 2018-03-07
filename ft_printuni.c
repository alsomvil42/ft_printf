/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 10:49:47 by alsomvil          #+#    #+#             */
/*   Updated: 2018/02/26 16:13:52 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_applymaskthree(wchar_t a)
{
	char	c1;
	char	c2;
	char	c3;
	char	c4;

	c1 = ((a >> 18) & 0x7) | 0xF0;
	c2 = ((a >> 12) & 0x3F) | 0x80;
	c3 = ((a >> 6) & 0x3F) | 0x80;
	c4 = (a & 0x3F) | 0x80;
	ft_putchar(c1);
	ft_putchar(c2);
	ft_putchar(c3);
	ft_putchar(c4);
}

void	ft_applymasktwo(wchar_t a)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = ((a >> 12) & 0x0F) | 0xE0;
	c2 = ((a >> 6) & 0x3F) | 0x80;
	c3 = (a & 0x3F) | 0x80;
	ft_putchar(c1);
	ft_putchar(c2);
	ft_putchar(c3);
}

void	ft_applymaskone(wchar_t a)
{
	char	c1;
	char	c2;

	c1 = ((a >> 6) & 0x1F) | 0xC0;
	c2 = (a & 0x3F) | 0x80;
	ft_putchar(c1);
	ft_putchar(c2);
}

void	ft_printuniw(wchar_t a)
{
	char *test;
	int		length;

	test = ft_itoabase(a, 2);
	length = ft_strlen(test);
	if (length < 8)
		ft_putchar(a);
	if (length >= 8 && length <= 11)
		ft_applymaskone(a);
	if (length >= 12 && length <= 16)
		ft_applymasktwo(a);
	if (length >= 17 && length <= 21)
		ft_applymaskthree(a);
}

void	ft_printuni(t_struct *save, wchar_t a)
{
	char *test;
	int		length;

	test = ft_itoabase(a, 2);
	length = ft_strlen(test);
	if (length < 8)
	{
		ft_checkoptionchart(save, 0);
		ft_putchar(a);
	}
	if (length >= 8 && length <= 11)
	{
		ft_checkoptionchart(save, 1);
		ft_applymaskone(a);
	}
	if (length >= 12 && length <= 16)
	{
		ft_checkoptionchart(save, 2);
		ft_applymasktwo(a);
	}
	if (length >= 17 && length <= 21)
	{
		ft_checkoptionchart(save, 3);
		ft_applymaskthree(a);
	}
}
