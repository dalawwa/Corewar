#include "corewar.h"

unsigned char	*add_that(unsigned char *body, char c, int where)
{
	int		len;
	unsigned char	*tmp;
	int		i;

	len = where + 1;
	i = 0;
	tmp = NULL;
	if (where == 0)
	{
		tmp = malloc(sizeof(char) * 2);
		if (tmp == NULL)
			return (NULL);
		tmp[0] = c;
		tmp[1] = '\0';
	}
	else
	{
		tmp = malloc(sizeof(char) * (len + 1));
		if (tmp == NULL)
			return (perror_ptr("Error ", NULL));
		while (i < len - 1)
		{
			tmp[i] = body[i];
			i++;
		}
		tmp[i] = c;
		tmp[i + 1] = '\0';
		free(body);
		body = NULL;
	}
	return (tmp);
}

int		has_nb_magic(t_file *file)
{
	unsigned char	*magic;
	unsigned char	*tmp;
	int		ret;
	int		i;
	int		j;

	i = 0;
	ret = 0;
	magic = NULL;
	tmp = NULL;
	while (i < 4)
	{
		j = 0;
		tmp = (unsigned char*)malloc(sizeof(unsigned char) * 4);
		if (tmp == NULL)
			return (perror_int("Error ", 0));
		while (j < 4)
			tmp[j++] = 0;
		if (i != 0)
			lseek(file->fd, i, SEEK_SET);
		read(file->fd, tmp, 1);
		magic = add_that((unsigned char*)magic, tmp[0], i);
		if (magic == NULL)
			return (0);
		i++;
		free(tmp);
		tmp = NULL;
	}
	if (magic[0] == 0 && magic[1] == (unsigned char)4294967274 && magic[2] == (unsigned char)4294967171 && magic[3] == (unsigned char)4294967283)
		ret = 1;
	free(magic);
	magic = NULL;
	if (ret == 0)
		ft_printf("Error: File %s has an invalid header\n", file->name);
	return (ret);
}

unsigned char	*clean_body(unsigned char *body, t_play **player)
{
	unsigned char	*cleaned;
	int		i;
	int		j;

	i = CHAMP_MAX_SIZE - 1;
	cleaned = NULL;
	j = 0;
	while (i && body[i] == 0)
		i--;
	(*player)->body_len = i + 1;
	cleaned = malloc(sizeof(unsigned char) * (i + 1));
	if (cleaned == NULL)
		return (perror_ptr("Error ", NULL));
	while (j <= i)
	{
		cleaned[j] = body[j] % 0x100;
		j++;
	}
	free(body);
	body = NULL;
	return (cleaned);
}