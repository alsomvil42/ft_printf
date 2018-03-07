/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 01:45:59 by alsomvil          #+#    #+#             */
/*   Updated: 2018/02/27 10:46:03 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

typedef struct				s_save
{
	char	*precision;
	char	*largueur;
	int		nbarg;
	char	conversion;
	int		space;
	int		pos;
	int		dieze;
	int		zero;
	int		neg;
	int		flagh;
	int		flaghh;
	int		flagl;
	int		flagll;
	int		flagj;
	int		flagz;
	int		retour;
}							t_struct;

int		ft_printf(const char *format, ...);
void	ft_printuni(t_struct *save, wchar_t c);
void	ft_printuniw(wchar_t c);
int		ft_stockmodif(t_struct *save, char *str, int i, int temp);
void	ft_converts(va_list test, t_struct *save);
void	ft_convertc(va_list test, t_struct *save);
void	ft_apply(va_list test, t_struct *save);
void	ft_convertdi(va_list test, t_struct *save);
void	ft_convertpxou(va_list test, t_struct *save);
void	ft_convertpourcent(void);
char	*ft_checkoptionint(t_struct *save, char *str);
int		ft_checkoptionchar(t_struct *save, char *str);
void	ft_checkoptionchart(t_struct *save, int nb);

#endif
