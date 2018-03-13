/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_hexa_toi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:21:39 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:21:43 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int		a_hexa_to_i(unsigned char *s, int len)
{
	int		result;
	int		i;

	result = 0;
	i = 0;
	while (i < len)
	{
		result += s[i] << (8 * (len - i - 1));
		i++;
	}
	if (s[0] > 127)
		return ((unsigned int)(0xffffffff00000000 + result));
	return (result);
}