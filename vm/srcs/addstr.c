/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:21:46 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/15 11:38:29 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*addstr(char *s)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = ft_strlen(s);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
	{
		perror("Error ");
		return (NULL);
	}
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
