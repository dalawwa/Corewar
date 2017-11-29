#include "corewar.h"

int		a_hexa_to_i(unsigned char *s, int len)
{
	int	result;
	int	i;

	result = 0;
	i = 1;
	len--;
	while (len >= 0)
	{
		result += s[len] * ft_power(2, i);
		len--;
		i++;
	}
	return (result);
}
