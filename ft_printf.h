/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 01:45:59 by alsomvil          #+#    #+#             */
/*   Updated: 2018/04/26 00:34:33 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_checkoptioncharuni(wchar_t *arg, t_save *save);
void	ft_converts_one(va_list test, t_save *save);
void	ft_printuni(t_save *save, wchar_t c);
void	ft_applymasktwo(wchar_t a, t_save *save);
void	ft_applymaskthree(wchar_t a, t_save *save);
void	ft_printuniw(wchar_t c, t_save *save, int length);
void	ft_printuni_two(t_save *save, wchar_t a, int length);
void	ft_putstr_minu(char *str, t_save *save, int test);
int		ft_stockmodif(t_save *save, char *str, int i, int temp);
void	ft_converts(va_list test, t_save *save);
void	ft_convertc(va_list test, t_save *save);
void	ft_apply(va_list test, t_save *save);
void	ft_applyoptiond(char *str, t_save *save, int neg);
void	ft_pasdeplace(t_save *save, int neg, int *size);
void	ft_applyoptiono(char *str, t_save *save, int neg);
void	ft_applyoptionx(char *str, t_save *save);
void	ft_convertx(va_list test, t_save *save);
void	ft_convertdi(va_list test, t_save *save);
void	ft_convertpxou(va_list test, t_save *save);
void	ft_convertp(va_list test, t_save *save);
void	ft_convertpourcent(t_save *save);
char	*ft_checkoptionint(t_save *save, char *str, int *neg);
void	ft_checkoptionchar(t_save *save, char *str);
void	ft_checkoptionchart(t_save *save, char argument);
void	ft_checkoptionuni(t_save *save, int nb);
void	ft_removestruct(t_save *save, int i);
void	ft_unsigned(int arg, t_save *save);

#endif
