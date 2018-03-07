#include "corewar.h"

char	*find_comment(t_file *file)
{
	char *line;

	line = ft_strnew(COMMENT_LENGTH);
	if (line == NULL)
		return (perror_ptr("Error ", NULL));
	lseek(file->fd, 140, SEEK_SET);
	read(file->fd, line, COMMENT_LENGTH);
	return (line);
}

char	*find_name(t_file *file)
{
	char	*line;

	line = ft_strnew(PROG_NAME_LENGTH);
	if (line == NULL)
		return (perror_ptr("Error ", NULL));
	lseek(file->fd, 4, SEEK_SET);
	read(file->fd, line, PROG_NAME_LENGTH);
	return (line);
}