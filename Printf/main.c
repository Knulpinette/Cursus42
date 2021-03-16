#include "ft_printf.h"

int main()
{
	//ft_printf("5 arg = %i %% %i %u %i %i %", 1, 2, 3, 4);
	//ft_printf("5 arg = %i %i %% %u %i %i %", 0, 1, 2, 3, 4);
	//ft_printf("5 arg = %i %i %u %i %i", 1, 2, 3, 4, 5);
	//ft_printf("blabla\n", 1);
	//ft_printf("blablablabla\n");
	//ft_printf("TEXTE%05*iTEXTE%**iTEXTE%..*cTEXTE%sBOOP%s", 100, 200, 'z', "STRING");
	ft_printf("\n%i\n", ft_printf("lolalala %c liloooo %s lililili %*i", 'c', "string", 3, 5000));
	ft_printf("\n");
	//printf("TEXTE%iTEXTE%iTEXTE%cTEXTE%s", 100, 200, 'z', "STRING");
	return 0;
}
