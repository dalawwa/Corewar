/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsi_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:23:25 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/15 12:32:12 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char	*ft_unsi_strdup(unsigned char *s, int len)
{
	unsigned char	*dup;
	int				i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(dup = (unsigned char*)malloc(sizeof(unsigned char) * len)))
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
