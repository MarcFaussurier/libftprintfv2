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

int	main(int ac, char **av)
{
	int	*i;
	ft_printf("args:\n");
//	ft_printf(	
//			"%p | %+c%+n %+i %+i %+d %+s %+p %% %+c %+n %+x %+X %+u \n", ULLONG_MAX, '0', &i, 42, 0, -42, "World", &ac, 'c', &i, 64, 64, 64);

//	printf(	"%p | %+c%+n %+i %+i %+d %+s %+p %% %+c %+n %+x %+X %+u \n", ULLONG_MAX, '0', &i, 42, 0, -42, "World", &ac, 'c', &i, 64, 64, 64);


	printf("-----\n");
	int ll= 0;
	ll = printf(		"	%c  %c \xff \n", '0',  '1', -1, '\xff');
	int ly = ft_printf(	"	%c  %c \xff \n", 	'0',  '1', -1, '\xff');

	printf("%i %i-----\n", ll, ly);

	printf("-----\n");
	ft_printf("%#u\n", ULONG_MAX);
	printf("%#u\n", ULONG_MAX);

	printf("-----\n");
	ft_printf("%#.9s\n", "a");
	printf("%#.9s\n", "a");

	printf("-----\n");
	ft_printf("%#p\n", -1);
	printf("%#p\n", -1);

	printf("-----\n");
	ft_printf("%#x\n", 42);
	printf("%#x\n", 42);
	printf("-----\n");
	ft_printf("%#X\n", 42);
	printf("%#X\n", 42);
	printf("-----\n");
	ft_printf("%#o\n", 42);
	printf("%#o\n", 42);
	printf("-----\n");
	ft_printf("%#O\n", 42);
	printf("%#O\n", 42);
	

	printf("%s \n", "7");
	ft_printf("%s \n", "7");

	printf("-----\n");
	ft_printf("%08.1s\n", "bonjour");
	printf("%08.1s\n", "bonjour");

	printf("-----\n");
	ft_printf("%+08.1s\n", "bonjour");
	printf("%+08.1s\n", "bonjour");

	printf("-----\n");
	ft_printf("%0+8.1s\n", "bonjour");
	printf("%0+8.1s\n", "bonjour");

	printf("-----\n");
	ft_printf("%0-8.1s\n", "bonjour");
	printf("%0-8.1s\n", "bonjour");

	printf("-----\n");
	ft_printf("%0+24.12i\n", "bonjour");
	printf("%0+24.12i\n", "bonjour");

	printf("-----\n");
	ft_printf("%0+-24.12i\n", "bonjour");
 	printf("%0+-24.12i\n", "bonjour");

	printf("-----\n");
	ft_printf("%0-+24.12i\n", "bonjour");
	printf("%0-+24.12i\n", "bonjour");

	printf("-----\n");
	ft_printf("%010i\n", "bonjour");
	printf("%010i\n", "bonjour");


	printf("-----\n");
	int x = 0, y =0;
	x = printf(		"pf: %-3d| \n", 1);
	y = ft_printf(	"me: %-3d| \n", 1);
	printf("[%i %i] -----\n", x, y);


	y = ft_printf("me: %0+4d \n", 14);
	x = printf("pf: %0+4d \n", 14);

	printf("[%i %i] -----\n", x, y);
	
	x = printf("%1s", "");
	y = ft_printf("%1s", "");
	printf("[%i %i] -----\n", x, y);


	x = printf("%s", "");
	y = ft_printf("%s", "");
	printf("[%i %i] -----\n", x, y);


	x = printf("%0s", "");
	y = ft_printf("%0s", "");
	printf("[%i %i] -----\n", x, y);
	

	x = printf(" %#x ", 0);
	y = ft_printf(" %#x ", 0);
	printf("[%i %i] -----\n", x, y);


	x = printf(" %#o ", 1);
	y = ft_printf(" %#o ", 1);
	printf("[%i %i] -----\n", x, y);


	x = printf(" %#o ", 0);
	y = ft_printf(" %#o ", 0);
	printf("[%i %i] -----\n", x, y);

	while (ac)
	{
		ft_printf(av[--ac]);
		ft_printf("\n");
	}
	return (0);
}
