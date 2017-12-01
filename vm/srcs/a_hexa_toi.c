#include "corewar.h"

int		a_hexa_to_i(unsigned char *s, int len)
{
	int		result;
	int		i;

	result = 0;
	i = 0;
	while (i < len)
	{
		result += s[i] << (8 * (len - i - 1));
		i++;
	}
	return (result);
}
