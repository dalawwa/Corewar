/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_c_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 16:12:34 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/18 16:12:37 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*ft_stradd_c_end(char *s, char c)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (new == NULL)
		return (NULL);
	while (s && s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (new);
}
