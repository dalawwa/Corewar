/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lines_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:24:32 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/09 12:17:55 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_champ		*ft_lstadd_lines(t_champ *begin, char *line, int i)
{
	t_champ	*next;
	int		j;

	j = 0;
	i = 0;
	if (!(next = malloc(sizeof(t_champ))))
		return (NULL);
	while (line[j] != ':')
		j++;
	next->label = ft_strsub(line, 0, j);
	next->position = position;
	next->next = begin;
	return (next);
}
