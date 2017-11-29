/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:52:21 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/28 15:52:27 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_power(int nb, int pow)
{
	int result;
	int i;

	i = 1;
	result = nb;
	while (i < pow)
	{
		result = result * nb;
		i++;
	}
	return (result);
}
