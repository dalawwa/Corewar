/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lines_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:24:32 by bfruchar          #+#    #+#             */
/*   Updated: 2017/11/29 15:19:53 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

//je verifie si il s agit d un label
int			get_two_points(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ':' && str[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

//je rajoute le nom dans la liste
void		add_name_list(t_champ *list)
{
	int i;
	int j;
	char *str;

	i = 0;
	while (list->line[i] == ' ' || list->line[i] == '\t')
		i++;
	j = i;
	while (list->line[j] != ' ' && list->line[j] != '\t' && list->line[j] != ',')
		j++;
	str = ft_strnew(j - i + 1);
	str = ft_strncpy(str, &list->line[i], (j - i));
	list->name = ft_strdup(str);
	if (get_two_points(list->name))
		list->is_label = 1;
	else
		list->is_label = 0;
	if (str)
		free(str);
}

void		add_infos_list(t_champ **begin)
{
	t_champ	*list;

	list = *begin;
	while (list->next)
		list = list->next;
	add_name_list(list);
}

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
	add_infos_list(begin);
}
