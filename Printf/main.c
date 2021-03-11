#include "./ft_printf.h"

int main()
{
	ft_printf("5 arg = %i %% %i %u %i %i %", 1, 2, 3, 4);
	ft_printf("5 arg = %i %i %% %u %i %i %", 0, 1, 2, 3, 4);
	ft_printf("5 arg = %i %i %u %i %i", 1, 2, 3, 4, 5);
	ft_printf("blabla\n", 1);
	ft_printf("blablablabla\n");
	return 0;
}
