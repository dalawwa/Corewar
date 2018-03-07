/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ito_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:31:09 by vbaudron          #+#    #+#             */
/*   Updated: 2018/02/02 18:23:13 by dalawwa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			ito_hexa_last(uintmax_t n, unsigned char **res)
{
	(*res)[0] = n >> 24;
	(*res)[1] = (n >> 16) & 0xff;
	(*res)[2] = (n >> 8) & 0xff;
	(*res)[3] = n & 0xff;
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
		ito_hexa_last(n, &res);
	return (res);
}
