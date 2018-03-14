/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertpxou.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:40:31 by alsomvil          #+#    #+#             */
/*   Updated: 2018/03/14 13:04:13 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convertpxou(va_list test, t_struct *save)
{
	unsigned int	arg;
	unsigned long	argl;
	char			*est;

	est = NULL;
	if (save->conversion == 'u' || save->conversion == 'U')
			ft_convertdi(test, save);
	else if (save->conversion == 'o' && save->flagl == 0)
	{
		arg = va_arg(test, unsigned int);
		est = ft_itoabase(arg, 8);
		ft_putstr(est);
	}
	else if ((save->conversion == 'o' && save->flagl == 1)
			|| save->conversion == 'O')
	{
		argl = va_arg(test, unsigned long);
		est = ft_itoabase(argl, 8);
		ft_putstr(est);
	}
}
