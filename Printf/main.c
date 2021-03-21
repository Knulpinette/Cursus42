#include "./include/ft_printf.h"

int main()
{
	int		b;
	void	*p;

	b = 5;
	p = &b;
	//ft_printf("5 arg = %i %% %i %i %i %i", 1, 2, 3, 4);
	//ft_printf("5 arg = %i %i %% %i %i %i", 0, 1, 2, 3, 4);
	//ft_printf("5 arg = %i %i %i %i %i", 1, 2, 3, 4, 5);
	//ft_printf("blabla\n", 1);
	//ft_printf("blablablabla\n");
	//ft_printf("TEXTE%05*iTEXTE%**iTEXTE%..*cTEXTE%sBOOP%s", 100, 200, 'z', "STRING");
	//ft_printf("\n%i\n", ft_printf("%% character %12c string %-*.5s number %25.6i", 'c', 55, "won'the'print", -5000));
	//ft_printf("\n");
	//printf("\n%i\n", printf("%% character %12c string %-*.5s number %25.6i", 'c', 55, "won'the'print", -5000));
	//printf("\n");
	ft_printf("my printf\n 5 : %50p\n 10 : %-12.10x\n 12 : %-20.12X\n", p, 79375, 3487);
	printf("real printf\n 5 : %50p\n 10 : %-12.10x\n 12 : %-20.12X\n", p, 79375, 3487);
	//ft_printf("%% character %12c string %-*.5s number %.6i", 'c', 55, "won'the'print", 5000);
	return 0;
}
