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

unsigned char	*ft_ito_hexa(uintmax_t n)
{
	unsigned char *res;

	res = NULL;
	if (!(res = (unsigned char *)malloc(4)))
		return (perror_ptr("Error ", NULL));
	ft_memset(res, 0, 4);
	if (n <= 0xff)
		res[3] = n;
	else if (n <= 0xffff)
	{
		res[2] = n >> 8;
		res[3] = n & 0xff;
	}
	else if (n <= 0xffffff)
	{
		res[1] = n >> 16;
		res[2] = (n >> 8) & 0xff;
		res[3] = n & 0xff;
	}
	else
	{
		res[0] = n >> 24;
		res[1] = (n >> 16) & 0xff;
		res[2] = (n >> 8) & 0xff;
		res[3] = n & 0xff;
	}
	//	res[4] = '\0';
//	ft_printf("ft_ito_hexa : N = %u\ns[0] = %.2x - s[1] = %.2x - s[2] = %.2x - s[3] = %.2x\n", n, res[0], res[1], res[2], res[3]);
	return (res);
	/*
	   unsigned char		*s;
	   uintmax_t	result;
	   int			i;

	   i = 0;

	   result = nb;
	   ft_printf("START %u\n", nb);
	   while (nb >= 16)
	   {
	   nb = nb / 16;
	   ft_printf("tour %d : %u\n", i, nb);
	   i++;
	   }
	   i++;
	   ft_printf(" ft_ito_hexa ========= i = %d\n", i);
	   s = malloc(sizeof(unsigned char) * i);
	   if (s == NULL)
	   return (perror_ptr("Error ", NULL));
	   if (s == NULL)
	   return (NULL);
	   i--;
	   if (fullfill_str(result, i, &s) == -1)
	   return (NULL);
	   return (s);*/
}
