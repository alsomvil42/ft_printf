/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkoption.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:31:44 by alsomvil          #+#    #+#             */
/*   Updated: 2018/03/14 10:30:51 by alsomvil         ###   ########.fr       */
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

char	*ft_checkoptionint(t_struct *save, char *str, int *neg)
{
	int		lengthstr;
	int		length;
	int		prec;
	int		space;


	lengthstr = 0;
	prec = 0;
	space = 0;
	length = ft_strlen(str);
	if ((*neg) == 0)
		space = 1;
	if (save->precision != NULL)
		prec = ft_atoi(save->precision);
	if (save->largueur != NULL)
		lengthstr = ft_atoi(save->largueur);
	if (prec == 0 && lengthstr == 0 && save->pos == 1 && *neg == 0)
	{
		ft_putchar('+');
		save->retour = save->retour + 1;
	}
	while ((lengthstr > length || prec > length) && save->neg == 0)
	{
		while (lengthstr > prec && lengthstr > length)
		{
			if (save->zero == 1 && save->pos == 0)
			{
				if (*neg == 1)
				{
					ft_putchar('-');
					(*neg)--;
					lengthstr--;
					save->retour = save->retour + 1;
				}
				save->retour = save->retour + 1;
				if (space == 1 && save->space)
				{
					space--;
					ft_putchar(' ');
				}
				else
					ft_putchar('0');
			}
			else if ((save->zero == 1 && save->pos == 1) ||
					(lengthstr > (prec + 1)))
			{
				if (lengthstr > (prec + 1))
				{
					ft_putchar(' ');
					save->retour = save->retour + 1;
				}
			}
			else if (save->pos == 0)
			{
				ft_putchar(' ');
				save->retour = save->retour + 1;
			}
			lengthstr--;
			if (lengthstr == length + 1 && *neg == 1)
			{
				ft_putchar('-');
				save->retour = save->retour + 1;
				(*neg)--;
				lengthstr--;
			}
		}
		while (prec > length)
		{
			if (*neg == 1)
			{
				(*neg)--;
				ft_putchar('-');
				save->retour = save->retour + 1;
			}
			if (save->pos == 1)
			{
				save->pos = 0;
				ft_putchar('+');
				save->retour = save->retour + 1;
			}
			save->retour = save->retour + 1;
			ft_putchar('0');
			lengthstr--;
			prec--;
		}
	}
	if (save->neg == 1 && save->largueur != NULL)
	{
		if (*neg == 1)
		{
			length = ft_atoi(save->largueur) - (ft_strlen(str) + 1);
			save->retour = save->retour + 1;
		}
		else
			length = ft_atoi(save->largueur) - (ft_strlen(str));
		(*neg)--;
		while (length > 0)
		{
			ft_putchar(' ');
			save->retour = save->retour + 1;
			length--;
		}
	}
	if (*neg == 1)
	{
		(*neg)--;
		ft_putchar('-');
		save->retour = save->retour + 1;
	}
	return (str);
}
