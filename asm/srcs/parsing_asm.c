/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_asm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:37:17 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/25 13:46:01 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			check_valid_name(char *str)
{
	int			i;

	i = ft_strlen(str);
	if (i < 3 || str[i - 1] != 's' || str[i - 2] != '.')
		return (0);
	return (1);
}

int			value_parent_comment(char *str, int i, int j, header_t *op)
{
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"' && str[i] != '\0')
			{
				i++;
				j++;
			}
			if (str[i] == '\0')
			{
				error_msg = 2;
				return (3);
			}
			if (j > 2048)
				return (3);
			i--;
			while (j--)
			{
				op->comment[j] = str[i];
				i--;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int			value_parent_name(char *str, int i, int j, header_t *op)
{
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"' && str[i++] != '\0')
				j++;
			if (str[i] == '\0')
			{
				error_msg = 2;
				return (3);
			}
			if (j > 128)
				return (2);
			i--;
			while (j--)
			{
				op->prog_name[j] = str[i];
				i--;
			}
			return (1);
		}
		i++;
	}
	return (1);
}

int			check_name_comment(int fd, header_t *op, int x, int y)
{
	char		*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strnequ(".name", line, 5) && x == 0)
		{
			if (value_parent_name(line, 0, 0, op) != 1)
			{
				if (line)
					free(line);
				return (3);
			}
			x = 1;
		}
		else if (ft_strnequ(".comment", line, 8) && y == 0)
		{
			if (value_parent_comment(line, 0, 0, op) == 3)
			{
				if (line)
					free(line);
				return (4);
			}
			y = 1;
		}
		else if (check_no_printable_char(line) == 0)
		{
			if (line)
				free(line);
			return (0);
		}
		if (line)
			free(line);
		if (x == 1 && y == 1)
			return (1);
	}
	return (0);
}

int			launch_parsing(char *str, int opt)
{
	int			fd;
	int			i;
	char		*file;
	t_champ		*champ;
	header_t	op;

	file = NULL;
	champ = NULL;
	if (check_valid_name(str) == 0)
		return (ciao_bye(1, str));
	if ((fd = open(str, O_RDONLY)) == -1)
		return (ciao_bye(2, str));
	i = check_name_comment(fd, &op, 0, 0);
	if (i != 1)
		return (ciao_bye_name(i, &op));
	champ = get_champ_data(&file, fd, 0);
	if (label_is_real(file, champ) == 0)
		return (ciao_bye_bye_fr(1, champ));
	if (opt == 1)
		if (launch_creation_cor(file, champ, &op, str) == 0)
			ciao_bye_bye(1);
	if (opt == 0)
		launch_writing_out(file, champ, &op);
	if (file)
		free(file);
	if (champ)
		freedom_for_list(champ);
	return (0);
}
