/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkoption.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:31:44 by alsomvil          #+#    #+#             */
/*   Updated: 2018/03/12 00:29:44 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkoptionchart(t_struct *save, int nb)
{
	int		lengthstr;

	lengthstr = 0;
	if (save->largueur != NULL)
		lengthstr = ft_atoi(save->largueur);
	while ((lengthstr - nb) > 1)
	{
		ft_putchar(' ');
		lengthstr--;
	}
}

int		ft_checkoptionchar(t_struct *save, char *str)
{
	int		lengthstr;
	int		length;
	int		prec;


	lengthstr = 0;
	length = ft_strlen(str);
	if (save->precision != NULL)
		prec = ft_atoi(save->precision);
	else
		prec = 0;
	if (save->largueur != NULL)
		lengthstr = ft_atoi(save->largueur);
	if (prec == 0 || prec > length)
	{
		while (lengthstr > length)
		{
			ft_putchar(' ');
			lengthstr--;
		}
		return (length);
	}
	else
	{
		while (lengthstr > prec)
		{
			ft_putchar(' ');
			lengthstr--;
		}
		return (prec);
	}
}

char	*ft_checkoptionint(t_struct *save, char *str, int neg)
{
	int		lengthstr;
	int		length;
	int		prec;


	lengthstr = 0;
	prec = 0;
	length = ft_strlen(str);
	if (save->precision != NULL)
		prec = ft_atoi(save->precision);
	if (save->largueur != NULL)
		lengthstr = ft_atoi(save->largueur);
	while (lengthstr > length || prec > length)
	{
		while (lengthstr > prec && lengthstr > length)
		{
			ft_putchar(' ');
			lengthstr--;
			if (lengthstr == length + 1 && neg == 1)
			{
				ft_putchar('-');
				neg--;
				lengthstr--;
			}
		}
		while (prec > length)
		{
			if (neg == 1)
			{
				neg--;
				ft_putchar('-');
			}
			save->retour = save->retour + 1;
			ft_putchar('0');
			lengthstr--;
			prec--;
		}
	}
	if (neg == 1)
		ft_putchar('-');
	return (str);
}
