/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lines_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:24:32 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/13 11:47:52 by bfruchar         ###   ########.fr       */
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

//pas grand chose a chercher la vue qu on a juste le label
void		is_a_label(t_champ *list)
{
	while (list->next)
		list = list->next;
	list->op_code = 0;
	list->is_label = 1;
//	list->params = NULL;
//	list->nb_params = 0;
//	list->size_param1 = 0;
//	list->size_param2 = 0;
//	list->size_param3 = 0;
	list->has_ocp = 0;
	list->ocp = '\0';
//	list->size_octets = 0;
}

//la il va falloir chercher un max d infos pour remplir la structure, les params et tout
//next step: recuperer les params 
//+ ocp
void		is_a_line_of_life(t_champ *list)
{
	int		i;
	int		op;

	i = 0;
	list->op_code = get_the_op_code(list->command);
	op = list->op_code;
	if (op == 1 || op == 9 || op == 12 || op == 15)
		list->has_ocp = 0;
	else if (op > 0 && op < 17)
		list->has_ocp = 1;
	add_number_args(list);
	if (check_args_valid(list->line, list->op_code, list) == 0)
		ciao_bye_bye(1);
//	list->is_label = 0;
}

void		is_a_line_of_life_with_label(t_champ *list)
{
	int		i;
	int		op;

	i = 0;
	list->op_code = get_the_op_code(list->command);
	op = list->op_code;
	if (op == 1 || op == 9 || op == 12 || op == 15)
		list->has_ocp = 0;
	else if (op > 0 && op < 17)
		list->has_ocp = 1;
	add_number_args(list);
	if (check_args_valid_with_label(list->line, list->op_code, list) == 0)
		ciao_bye_bye(1);
}

int		ft_tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

//je rajoute le nom dans la liste + label et on lance la recherche des autres infos
void		add_name_list(t_champ *list)
{
	int i;
	int j;
	int g;
	char *str;
	char *str2;

	i = 0;
	while (list->line[i] == ' ' || list->line[i] == '\t')
		i++;
	j = i;
	while (list->line[j] != ' ' && list->line[j] != '\t' && list->line[j] != ',')
		j++;
	str = ft_strnew(j - i + 1);
	str = ft_strncpy(str, &list->line[i], (j - i));
	list->name = ft_strdup(str);
	while (list->line[j] == ' ' || list->line[j] == '\t')
		j++;
	if (get_two_points(list->name))
	{
		list->label = ft_strdup(str);
		is_a_label(list);
		g = ft_tablen(ft_strsplit_three(list->line, ' ', '\t', ','));
		if (list->line[j] != '\0' && list->line[j] != '#' && list->line[j] != ';' && g > 2)
		{
			i = j;
			while (list->line[j] != ' ' && list->line[j] != '\t' && list->line[j] != ',' && list->line[j] != '\0')
				j++;
			str2 = ft_strnew(j - i + 1);
			str2 = ft_strncpy(str2, &list->line[i], (j - i));
			if (get_the_op_code(str2) > 0)
			{
				list->is_label_and = 1;
				list->command = ft_strdup(str2);
				is_a_line_of_life_with_label(list);
			}
		}
	}
	else
	{
		list->command = ft_strdup(str);
		list->is_label_and = 0;
		is_a_line_of_life(list);
	}
	if (str)
		free(str);
}

char	*ft_strdup_asm(const char *s)
{
	char		*dup;
	int			j;
	size_t		i;

	i = 0;
	j = 0;
	while (s[j] != '\0' && s[j] != ';' && s[j] != '#')
		j++;
	if (!(dup = (char*)malloc(j + 1)))
		return (NULL);
	while (s[i] && s[i] != ';' && s[i] != '#')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void		add_infos_list(t_champ **begin)
{
	t_champ	*list;

	list = *begin;
	while (list->next)
		list = list->next;
	list->is_label_and = 0;
	add_name_list(list);
	while (list->prev)
		list = list->prev;
}

t_champ		*ft_lstnew_line(char *line)
{
	t_champ *list;

	if (!(list = (t_champ *)ft_memalloc(sizeof(t_champ))))
		ciao_bye_bye(1);
	list->next = NULL;
	list->line = ft_strdup_asm(line);
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
