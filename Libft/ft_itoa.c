#include "libft.h"

char	*ft_putnbr(long int nb, char *str, int	size)
{
	if (nb < 0)
	{
		str[0] = '-';
		ft_putnbr(-nb, str, size);
	}
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = nb % 10 + '0';
		size--;
		nb = nb / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int			size;
	long int	nb;
	char		*str;

	nb = (long int)n;
	size = 2;
	if (nb < 0)
		size++;
	while ((nb / 10) != 0)
	{
		size++;
		nb = nb / 10;
	}
	str = (char *)malloc(sizeof(char) * size);
	if (!(str))
		return (NULL);
	return (ft_putnbr(nb, str, size));
}
