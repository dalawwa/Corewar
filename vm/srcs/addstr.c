#include "corewar.h"

char	*addstr(char *s)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = ft_strlen(s);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
	{
		perror("Error ");
		return (NULL);
	}
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
