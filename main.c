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
	ft_printf(	
			"%p | %+c%+n %+i %+i %+d %+s %+p %% %+c %+n %+x %+X %+u \n", ULLONG_MAX, '0', &i, 42, 0, -42, "World", &ac, 'c', &i, 64, 64, 64);

	printf(	"%p | %+c%+n %+i %+i %+d %+s %+p %% %+c %+n %+x %+X %+u \n", ULLONG_MAX, '0', &i, 42, 0, -42, "World", &ac, 'c', &i, 64, 64, 64);

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
	

	printf("-----\n");
	ft_printf("%0-8.3s\n", "bonjour");
	printf("%0-8.3s\n", "bonjour");

	while (ac)
	{
		ft_printf(av[--ac]);
		ft_printf("\n");
	}
	return (0);
}
