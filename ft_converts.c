/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 03:36:29 by alsomvil          #+#    #+#             */
/*   Updated: 2018/02/27 11:39:10 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	ft_applyuni(t_struct *save, wchar_t *arg)
{
	int		i;
	int		option;
	int		length;
	char	*temp;

	i = 0;
	option = 0;
	while (arg[i])
	{
		while (arg[i] >= 32 && arg[i] <= 126)
		{
			option++;
			i++;
		}
		if (arg[i] > 126)
		{
			temp = ft_itoabase(arg[i], 2);
			length = ft_strlen(temp);
			if (length >= 8 && length <= 11)
				option = option + 1;
			if (length >= 12 && length <= 16)
				option = option + 2;
			if (length >= 16 && length <= 21)
				option = option + 3;
		}
		i++;
	}
	//printf("%d\n", option);
	ft_checkoptionchart(save, option);
}

void	ft_converts(va_list test, t_struct *save)
{
	int		i;
	int		prec;
	wchar_t	*arg;
	char	*argument;

	i = 0;
	arg = NULL;
	if (save->conversion == 'S')
	{
		arg = va_arg(test, wchar_t*);
		ft_applyuni(save, arg);
		while (arg[i])
		{
			while (arg[i] >= 32 && arg[i] <= 126)
			{
				ft_putchar(arg[i]);
				save->retour = save->retour + 1;
				i++;
			}
			if (arg[i] > 126)
			{
				ft_printuniw(arg[i]);
				i++;
			}
		}
	}
	else
	{
		argument = va_arg(test, char*);
		prec = ft_checkoptionchar(save, argument);
		while (i < prec)
		{
			ft_putchar(argument[i]);
			save->retour = save->retour + 1;
			i++;
		}
	}
}

void	ft_convertc(va_list test, t_struct *save)
{
	int		i;
	wchar_t	arg;
	char	argument;

	i = 0;
	if (save->conversion == 'C')
	{
		arg = va_arg(test, wchar_t);
		ft_printuni(save, arg);
	}
	else
	{
		argument = (char)va_arg(test, int);
		ft_checkoptionchart(save, 0);
		ft_putchar(argument);
	}
}

void	ft_convertdi(va_list test, t_struct *save)
{
	int		i;
	int		arg;
	int		retour;
	long	argument;

	i = 0;
	arg = 0;
	if ((save->conversion == 'i' && save->flagl == 0) || (save->conversion == 'd' && save->flagl == 0))
	{
		arg = va_arg(test, int);
		retour = ft_strlen(ft_itoabase(arg, 10) + 1);
		if (save->largueur && ft_atoi(save->largueur) > retour)
			save->retour = save->retour + ft_atoi(save->largueur);
		else
			save->retour = save->retour + retour + 1;
		ft_checkoptionint(save, ft_itoa(arg));
		ft_putnbr(arg);
	}
	else
	{
		argument = va_arg(test, long);
		retour = ft_strlen(ft_itoabase(arg, 10));
		ft_checkoptionint(save, ft_itoabase(argument, 10));
		save->retour = save->retour + retour;
		if (argument > 0)
			ft_putnbr(argument);
		else
		{
			ft_putnbr((long)argument);
		}
	}
}

void	ft_convertpourcent(void)
{
	ft_putchar('%');
}