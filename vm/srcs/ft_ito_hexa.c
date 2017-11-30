/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ito_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:31:09 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 13:20:27 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_hexa_x(uintmax_t rest, unsigned char c)
{
	if (rest < 10)
		return (c);
	else if (rest == 10)
		c = 'a';
	else if (rest == 11)
		c = 'b';
	else if (rest == 12)
		c = 'c';
	else if (rest == 13)
		c = 'd';
	else if (rest == 14)
		c = 'e';
	else if (rest == 15)
		c = 'f';
	else
		c = 'z';
	return (c);
}

int		fullfill_str(uintmax_t result, int i, unsigned char **s)
{
	int rest;

	rest = 0;
	while (result >= 16)
	{
		rest = result % 16;
		result = result / 16;
		(*s)[i] = ft_hexa_x(rest, rest + '0');
		if ((*s)[i] == 'z')
			return (-1);
		i--;
	}
	rest = result % 16;
	(*s)[0] = ft_hexa_x(rest, rest + '0');
	return (1);
}

unsigned char	*ft_ito_hexa(uintmax_t nb)
{
	unsigned char		*s;
	uintmax_t	result;
	int			i;

	i = 0;
	result = nb;
	while (nb >= 16)
	{
		nb = nb / 16;
		i++;
	}
	i++;
	s = malloc(sizeof(unsigned char) * i);
	if (s == NULL)
		return (perror_ptr("Error ", NULL));
	if (s == NULL)
		return (NULL);
	i--;
	if (fullfill_str(result, i, &s) == -1)
		return (NULL);
	return (s);
}
