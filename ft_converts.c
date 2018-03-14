/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 03:36:29 by alsomvil          #+#    #+#             */
/*   Updated: 2018/03/14 14:17:37 by alsomvil         ###   ########.fr       */
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
	long long	argument;
	int		neg;

	i = 0;
	arg = 0;
	neg = 0;
	if ((save->conversion == 'i' || save->conversion == 'd'
			|| save->conversion == 'u')
			&& !save->flagl && !save->flagll)
	{
		arg = va_arg(test, int);
		if (save->conversion == 'u' && arg < 0)
		{
		//	printf("%d\n", arg);
			ft_putnbrunsigned((unsigned int)arg, 0);
			return ;
		}
		if (save->neg == 1)
			ft_putnbr(arg);
		if (arg < 0)
		{
			arg = -arg;
			neg = 1;
		}
		retour = ft_strlen(ft_itoabase(arg, 10));
		if (save->space && save->pos == 0 && neg == 0)
		{
			ft_putchar(' ');
			save->retour = save->retour + 1;
		}
		ft_checkoptionint(save, ft_itoa(arg), &neg);
		if (neg > 0)
			save->retour = save->retour + 1;
		if ((save->precision && ft_atoi(save->precision) == 0)
				&& arg == 0 && save->space == 0)
			return ;
		else if (save->neg != 1)
			ft_putnbr(arg);
		save->retour = save->retour + retour;
	}
	else
	{
		argument = va_arg(test, long long);
		if (argument < 0)
		{
			argument = -argument;
			neg = 1;
		}
		retour = ft_strlen(ft_itoabase(argument, 10));
		ft_checkoptionint(save, ft_itoabase(argument, 10), &neg);
		if (neg > 0)
			save->retour = save->retour + 1;
		save->retour = save->retour + retour;
		if ((save->precision && ft_atoi(save->precision) == 0)
				&& argument == 0 && save->space == 0)
			return ;
		else if ((save->precision && ft_atoi(save->precision) == 0)
				&& argument == 0 && save->space == 1)
		{
			ft_putchar(' ');
			return ;
		}
		ft_putnbr((long long)argument);
	}
}

void	ft_convertpourcent(void)
{
	ft_putchar('%');
}
