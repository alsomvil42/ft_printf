/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 23:38:09 by alsomvil          #+#    #+#             */
/*   Updated: 2018/02/21 11:46:13 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_apply(va_list test, t_struct *save)
{
	if (save->conversion == 'i' || save->conversion == 'd'
		|| save->conversion == 'D')
		ft_convertdi(test, save);
	else if (save->conversion == 's' || save->conversion == 'S')
		ft_converts(test, save);
	else if (save->conversion == 'p' || save->conversion == 'x'
			|| save->conversion == 'X' || save->conversion == 'o'
			|| save->conversion == 'O' || save->conversion == 'u'
			|| save->conversion == 'U')
		ft_convertpxou(test, save);
	else if (save->conversion == 'C' || save->conversion == 'c')
		ft_convertc(test, save);
	else if (save->conversion == '%')
		ft_convertpourcent();
	return;
}
