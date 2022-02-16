/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:54:42 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 10:57:41 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_vprintf(const char *fmt, va_list ap);
int	ft_printf(const char *fmt, ...);
int	ft_vcprintf(void(*c)(char c, void *data), void *data, const char *fmt, va_list ap);
int	ft_cprintf(void(*c)(char c, void *data), void *data, const char *fmt, ...);
#endif
