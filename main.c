/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:38:33 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 17:15:32 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct s_text
{
	va_list	ap;
	int		r;
	char	*s;
}	t_test;

static int	test(int line, const char *fmt, ...)
{
	static int	r;
	static int	t;
	int			success;
	t_test		std;
	t_test		ft;

	if (!line)
		return (!printf("%i errors / %i tests\n", r, t));
	t += 1;
	va_start(std.ap, fmt);
	std.r = vasprintf(&std.s, fmt, std.ap);
	va_end(std.ap);
	va_start(ft.ap, fmt);
	ft.r = vasprintf(&ft.s, fmt, ft.ap);
	va_end(ft.ap);
	printf("[%s:%i] ", __FILE__, line);
	success = ((ft.r == std.r) && !strcmp(ft.s, std.s));
	if (success)
		printf("SUCCESS");
	else if (++r)
		printf("FAILURE");
	printf(" [expected=%i got=%i '%s' '%s']\n", std.r, ft.r, std.s, ft.s);
	free(std.s);
	free(ft.s);
	return (!!success);
}

int	main(void)
{
	printf("-- %%c\n");
	test(__LINE__, "%c", 42);
	test(__LINE__, "%+0.54c", 42);
	test(__LINE__, "%+0 .5c", 42);
	test(__LINE__, "%045.58c", 42);
	test(__LINE__, "%---7.1 .8c", 42);
	test(__LINE__, "%80+80+80c", 42);
	test(__LINE__, "% 8 .5c", 42);
	test(__LINE__, "%-0 +72.15c", 42);
	test(__LINE__, "%669c", 42);
	test(__LINE__, "%0.0c", 42);
	printf("-- %%s\n");
	test(__LINE__, "%s", "42");
	test(__LINE__, "%+0.54s", "42");
	test(__LINE__, "%+0 .5s", "42");
	test(__LINE__, "%045.58s", "42");
	test(__LINE__, "%---7.1 .8s", "42");
	test(__LINE__, "%80+80+80s", "42");
	test(__LINE__, "% 8 .5s", "42");
	test(__LINE__, "%-0 +72.15s", "42");
	test(__LINE__, "%669s", "42");
	test(__LINE__, "%0.0s", "42");
	test(__LINE__, "%s", "42");
	printf("-- %%p\n");
	test(__LINE__, "%p", 42);
	test(__LINE__, "%+0.54p", 42);
	test(__LINE__, "%+0 .5p", 42);
	test(__LINE__, "%045.5p", 42);
	test(__LINE__, "%---7.1 .8p", 42);
	test(__LINE__, "%80+80+80p", 42);
	test(__LINE__, "% 8 .5p", 42);
	test(__LINE__, "%-0 +72.15p", 42);
	test(__LINE__, "%669p", 42);
	test(__LINE__, "%0.0p", 42);
	printf("-- %%d\n");
	test(__LINE__, "%669d", 42);
	test(__LINE__, "%0.0d", 42);
	printf("-- %%i\n");
	test(__LINE__, "%i", 42);
	test(__LINE__, "%+0.54i", 42);
	test(__LINE__, "%+0 .5i", 42);
	test(__LINE__, "%045.58i", 42);
	test(__LINE__, "%---7.1 .8i", 42);
	test(__LINE__, "%80+80+80i", 42);
	test(__LINE__, "% 8 .5i", 42);
	test(__LINE__, "%-0 +72.15i", 42);
	printf("-- %%u\n");
	test(__LINE__, "%u", 42);
	test(__LINE__, "%+0.54u", 42);
	test(__LINE__, "%+0 .5u", 42);
	test(__LINE__, "%045.58u", 42);
	test(__LINE__, "%---7.1 .8u", 42);
	test(__LINE__, "%80+80+80u", 42);
	test(__LINE__, "% 8 .5u", 42);
	test(__LINE__, "%-0 +72.15u", 42);
	test(__LINE__, "%669u", 42);
	test(__LINE__, "%0.0u", 42);
	printf("-- %%o\n");
	test(__LINE__, "%o", 42);
	test(__LINE__, "%+0.54o", 42);
	test(__LINE__, "%+0 .5o", 42);
	test(__LINE__, "%045.58o", 42);
	test(__LINE__, "%---7.1 .8o", 42);
	test(__LINE__, "%80+80+80o", 42);
	test(__LINE__, "% 8 .5o", 42);
	test(__LINE__, "%-0 +72.15o", 42);
	test(__LINE__, "%669o", 42);
	test(__LINE__, "%0.0o", 42);
	printf("-- %%%%\n");
	test(__LINE__, "%%", 42);
	test(__LINE__, "%+0.54%", 42);
	test(__LINE__, "%+0 .5%", 42);
	test(__LINE__, "%045.58%", 42);
	test(__LINE__, "%---7.1 .8%", 42);
	test(__LINE__, "%80+80+80%", 42);
	test(__LINE__, "% 8 .5%", 42);
	test(__LINE__, "%-0 +72.15%", 42);
	test(__LINE__, "%669%", 42);
	test(__LINE__, "%0.0%", 42);
	test(0, 0);
	return (0);
}
