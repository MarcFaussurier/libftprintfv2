/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:21:58 by mafaussu          #+#    #+#             */
/*   Updated: 2021/09/21 22:54:27 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_isspace(char str);
char		*ft_strrev(char *passed);
void		ft_append(char *str, char c);

int		ft_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i += 1;
	}
	return (-1);
}

unsigned int	ft_checkbase(char *base)
{
	unsigned int	i;
	char			passed[256];

	i = 0;
	while (i < 256)
		passed[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (passed[(unsigned char)base[i]])
			return (0);
		else if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		passed[(unsigned char)base[i]] = 1;
		i += 1;
	}
	return (i);
}

static void	ft_putunbr_base(char *buffer, unsigned int nbr,
							char *base, unsigned int baselen)
{
	if (!nbr)
		return ;
	ft_putunbr_base(buffer + 1, nbr / baselen, base, baselen);
	*buffer = base[nbr % baselen];
}

int	ft_atoi_base(char *str, char *base)
{
	int				o;
	char			isn;
	unsigned int	baselen;

	isn = 1;
	o = 0;
	baselen = ft_checkbase(base);
	if (baselen <= 1)
		return (0);
	while (ft_isspace(*str))
		str += 1;
	while (*str == '+' || *str == '-' || ft_isspace(*str))
		if (*str == '+')
			str += 1;
	else
	{
		isn *= -1;
		str += 1;
	}
	while (ft_index(*str, base) != -1)
	{
		o *= baselen;
		o += ft_index(*str++, base);
	}
	return (o * isn);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	baselen_to;
	int				nb;
	char			*passed;

	baselen_to = ft_checkbase(base_to);
	if ((baselen_to <= 1) || (ft_checkbase(base_from) <= 1))
		return (0);
	passed = malloc(255);
	if (!passed)
		return (0);
	nb = 0;
	while (nb < 255)
		passed[nb++] = 0;
	nb = ft_atoi_base(nbr, base_from);
	if (nb < 0)
	{
		ft_putunbr_base(passed, nb * -1, base_to, baselen_to);
		ft_append(passed, '-');
	}
	else if (nb == 0)
		ft_append(passed, base_to[0]);
	else
		ft_putunbr_base(passed, nb, base_to, baselen_to);
	return (ft_strrev(passed));
}

int	ft_isspace(char str)
{
	return (str == ' ' || str == '\t' || str == '\v' || str == '\f'
		|| str == '\r' || str == '\n');
}

void	ft_swap(char *a, char *b)
{
	char	d;

	d = *a;
	*a = *b;
	*b = d;
}

void	ft_append(char *str, char c)
{
	while (*str)
		str++;
	*str = c;
}

char	*ft_strrev(char *passed)
{
	int	i;
	int	y;

	i = 0;
	while (passed[i])
		i += 1;
	y = 0;
	while (y < i / 2)
	{
		ft_swap(&passed[y], &passed[i - y - 1]);
		y += 1;
	}
	return (passed);
}
