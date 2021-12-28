/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 08:39:34 by ioriola           #+#    #+#             */
/*   Updated: 2020/09/15 12:01:09 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct{
	va_list		varg;
	char		*text;
	int			index;
	char		*block;
	char		type;
	int			fminus;
	int			fprec;
	int			precstar;
	int			fwidth;
	int			widthstar;
	int			fzero;
	int			counter;
	int			error;
}	t_struct;

int				ft_printf(const char *text, ...);

void			kernel(t_struct *set);
void			setalltozero(t_struct *set);
void			setsometozero(t_struct *set);
char			*getblock(t_struct *set);
void			processblock(t_struct *set);
int				istype(char c);
int				isflag(char c);
void			ft_putlong(long nb);
void			ft_putuint(unsigned int nb);
char			*ft_itoa_base(int value, int base);
char			*ft_itoa_base_pointer(unsigned long value, int base);
int				digit_count(long nb, int base);
int				digit_u_count(unsigned int nb, int base);

void			getflags(t_struct *set);
void			getwidth(t_struct *set);
void			getprecision(t_struct *set);
void			printzerosspaces(t_struct *set, int size);
void			printwhatever(t_struct *set);
void			printchar(t_struct *set);
void			printstr(t_struct *set);
void			printpointer(t_struct *set);
void			printint(t_struct *set);
void			printuint(t_struct *set);
void			printhex(t_struct *set);

#endif
