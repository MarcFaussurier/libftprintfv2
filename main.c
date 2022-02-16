/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:38:33 by mafaussu          #+#    #+#             */
/*   Updated: 2022/02/16 15:58:54 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

int	main(int ac, char **av)
{
	ft_printf("args:\n");
	ft_printf("%i %s %p %% %c %n\n", 42, "World", &ac, 'c');
	while (ac)
	{
		ft_printf(av[--ac]);
		ft_printf("\n");
	}
	return (0);
}
