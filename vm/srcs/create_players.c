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
			return (NULL);
		while (i < len)
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

void			swap_second(unsigned char *body)
{
	unsigned char tmp;

	tmp = body[1];
	body[1] = body[0];
	body[0] = tmp;
}

unsigned char	*clean_body(unsigned char *body, int *body_len)
{
	unsigned char	*cleaned;
	int		i;
	int		j;

	i = CHAMP_MAX_SIZE - 1;
	cleaned = NULL;
	j = 0;
	swap_second(body);
	while (body[i] == 0)
		i--;
	*body_len = i;
//	ft_printf("i = %d\n", i);
	cleaned = malloc(sizeof(unsigned char) * i);
	if (cleaned == NULL)
		return (NULL);
	while (j < i)
	{
		cleaned[j] = body[1 + j] % 0x100;
//		ft_printf("body_cleaned[%d] = %.2x\n", j, cleaned[j]);
		j++;
	}
	free(body);
	body = NULL;
//	i = 0;
//	while (i < j)
//	{
//		ft_printf("body_cleaned[%d] = %.2x\n", i, cleaned[i]);
//		i++;
//	}
	return (cleaned);
}


int		has_nb_magic(int fd)
{
	char	*magic;
	char	*tmp;
	int		ret;
	int		i;

	i = 0;
	ret = 1;
	magic = NULL;
	tmp = NULL;
	while (i < 4)
	{
		tmp = ft_strnew(1);
		if (i != 0)
			lseek(fd, i, SEEK_SET);
		read(fd, tmp, 1);
//		ft_printf("tmp = %x\n", tmp[0]);
		magic = (char*)add_that((unsigned char*)magic, tmp[0], i);
		i++;
		free(tmp);
		tmp = NULL;
	}
	if (magic[0] == '0' && magic[1] == (char)4294967274 && magic[2] == (char)4294967171 && magic[3] == (char)4294967283)
		ret = 1;
	free(magic);
	magic = NULL;
//	if (ret == 1)
//		ft_putendl("Magic Number Found !");
	if (ret == 0)
		ft_putendl("Error : Something wrong with Magic Number");
	return (ret);
}

unsigned char	*find_body(int fd)
{
	unsigned char	*line;
	unsigned char	*body;
	int		i;
	int		red;

	i = 0;
	red = 140 + 4 + COMMENT_LENGTH;
	line = NULL;
	body = NULL;
	while (red < CHAMP_MAX_SIZE + 140 + 4 + COMMENT_LENGTH)
	{
		line = (unsigned char*)ft_strnew(1);
		lseek(fd, red, SEEK_SET);
		read(fd, line, 1);
		body = add_that(body, line[0], i);
		red++;
		free(line);
		line = NULL;
		i++;
	}
/*	i = 0;
	while (i < CHAMP_MAX_SIZE)
	{
		ft_printf("body[%d] = %.2x\n", i, body[i]);
		i++;
	}*/
	return (body);
}

char	*find_comment(int fd)
{
	char *line;

	line = ft_strnew(COMMENT_LENGTH);
	lseek(fd, 140, SEEK_SET);
	read(fd, line, COMMENT_LENGTH);
//	ft_printf("COMMENT =_%s_\n", line);
	return (line);
}

char	*find_name(int fd)
{
	char	*line;

	line = ft_strnew(PROG_NAME_LENGTH);
	lseek(fd, 4, SEEK_SET);
	read(fd, line, PROG_NAME_LENGTH);
//	ft_printf("NAME =_%s_\n", line);
	return (line);
}

int		check_size(int fd, t_arena *arena)
{
	int size;

	size = 0;
	arena = arena + 0;
	size = lseek(fd, 0, SEEK_END);
	if (size > CHAMP_MAX_SIZE + PROG_NAME_LENGTH + 4 + COMMENT_LENGTH)
	{
		ft_printf("Error: File %s has too large code (%d bytes > 682 bytes)\n", "FILE_NAME", size - 140 - 4 - COMMENT_LENGTH);
		return (0);
	}
	return (1);
}

int		create_a_player(int fd, t_play *player, t_arena *arena)
{
	if (check_size(fd, arena) == 0)
		return (0);
	if (has_nb_magic(fd) != 1)
		return (0);
	player->name = find_name(fd);
//	ft_printf("player->name = %s\n", player->name);
	if (player->name == NULL)
		return (0);
	player->comment = find_comment(fd);
	if (player->comment == NULL)
		return (0);
	player->body = find_body(fd);
	if (player->body == NULL)
		return (0);
	player->body = clean_body(player->body, &player->body_len);
	if (player->body == NULL)
		return (0);
	return (1);
}

t_play		*init_player(int i)
{
	t_play *player;
	player = (t_play*)malloc(sizeof(t_play));
	if (player == NULL)
		return (NULL);
	player->play_num = i + 1;
	player->name = NULL;
	player->comment = NULL;
	player->body = NULL;
	player->body_len = -1;
	return (player);
}

int		create_players(t_arena *arena)
{
	int		i;

	i = 0;
//	ft_printf("Let's create %d Player(s) !\n", arena->nb_players);
	arena->players = (t_play **)malloc(sizeof(t_play *) * arena->nb_players);
	if (arena->players == NULL)
		return (0);
	while (i < arena->nb_players)
	{
		arena->players[i] = init_player(i);
		if (create_a_player(arena->fds[arena->nb_players - 1 - i], arena->players[i], arena) == 0)
			return (0);
		i++;
	}
	print_players(arena);
	return (1);
}
