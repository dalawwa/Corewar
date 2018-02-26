#include "corewar.h"

unsigned int		a_hexa_to_i(unsigned char *s, int len)
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
//	ft_printf("len = %d -  result = %d - S = %.2x %.2x %.2x %.2x\n", len, result, s[0], s[1], s[2], s[3]);
	if (s[0] > 127)
		return ((unsigned int)(0xffffffff00000000 + result));
	return (result);
}
