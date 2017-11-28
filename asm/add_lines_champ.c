/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lines_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:24:32 by bfruchar          #+#    #+#             */
/*   Updated: 2017/11/28 18:28:54 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_champ		*ft_lstnew_line(char *line)
{
	t_champ *list;

	if (!(list = (t_champ *)ft_memalloc(sizeof(t_champ))))
		ciao_bye_bye(1);
	list->next = NULL;
	list->line = line;
	return (list);
}

void		ft_lstadd_lines(t_champ **begin, char *line, int i)
{
	t_champ	*list;
	t_champ *tmp;

	if (*begin == NULL)
		*begin = ft_lstnew_line(line);
	else
	{
		list = *begin;
		while (list->next)
			list = list->next;
		list->next = ft_lstnew_line(line);
		tmp = list;
		list = list->next;
		list->prev = tmp;
		list->position = i;
	}
}
