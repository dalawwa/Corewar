/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lines_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:24:32 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/06 10:55:38 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
//je vais recuperer les arguments
void		add_args_champ(t_champ *list)
{
	int	i;
	int	j;

	while (list->prev)
		list = list->prev;
	list = list->next;
	while (list->next)
	{
		i = 0;
		j = 0;
		while (list->is_label == 1 && list->next)
			list = list->next;
		if (list->next == NULL)
			break ;
		while ((list->line[i + 1] != 'r' || list->line[i + 1] != '%') && (list->line[i] != ' ' || list->line[i] != '\t') && list->line[i] != '\0')
			i++;
		i++;
		while (list->line[i] != ' ' && list->line[i] != ',' && list->line[i] != '\t' && list->line[i] != '\0')
		{
			ft_putchar(list->line[i]);
			i++;
			j++;
		}
		ft_putchar(' ');
		list = list->next;
	}
}
*/

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

//pas grand chose a chercher la vue qu on a juste le label
void		is_a_label(t_champ *list)
{
	while (list->next)
		list = list->next;
	list->op_code = 0;
	list->is_label = 1;
	list->params = NULL;
	list->nb_params = 0;
	list->size_param1 = 0;
	list->size_param2 = 0;
	list->size_param3 = 0;
	list->has_ocp = 0;
	list->ocp = '\0';
	list->size_octets = 0;
}

//la il va falloir chercher un max d infos pour remplir la structure, les params et tout
//next step: recuperer les params 
//+ ocp
void		is_a_line_of_life(t_champ *list)
{
	int		i;
//	int		op;

	i = 0;
	while (list->next)
		list = list->next;
	list->op_code = get_the_op_code(list->name);
	if (check_args_valid(list->line, list->op_code) == 0)
		ciao_bye_bye(1);
	list->is_label = 0;
}

//je rajoute le nom dans la liste + label et on lance la recherche des autres infos
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
		is_a_label(list);
	else
		is_a_line_of_life(list);
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
	while (list->prev)
		list = list->prev;
	add_number_args(list);
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
