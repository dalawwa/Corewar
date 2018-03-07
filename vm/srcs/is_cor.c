#include "corewar.h"

int		is_cor(char *s)
{
	int	len;
	
	len = (int)ft_strlen(s);
	if (len < 4)
		return (0);
	if (s[len - 1] == 'r' && s[len - 2] == 'o' && s[len - 3] == 'c' && s[len - 4] == '.')
		return (1);
	return (0);
}
