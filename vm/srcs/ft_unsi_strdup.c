/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 06:25:01 by mapandel          #+#    #+#             */
/*   Updated: 2016/12/26 23:41:45 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char	*ft_unsi_strdup(unsigned char *s, int len)
{
	unsigned char	*dup;
	size_t			i;

	i = 0;
	if (!(dup = (unsigned char*)malloc(sizeof(unsigned char) * len)))
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
