/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removestruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 10:56:21 by alsomvil          #+#    #+#             */
/*   Updated: 2018/03/14 11:00:16 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_removestruct(t_struct *save, int i)
{
	save->precision = NULL;
	save->largueur = NULL;
	save->conversion = 0;
	save->space = 0;
	save->pos = 0;
	save->dieze = 0;
	save->zero = 0;
	save->neg = 0;
	save->flagh = 0;
	save->flaghh = 0;
	save->flagl = 0;
	save->flagll = 0;
	save->flagj = 0;
	save->flagz = 0;
	if (i == 1)
		save->retour = 0;
}
