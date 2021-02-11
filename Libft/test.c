/*#include "libft.h"*/
#include <string.h>
#include <stdio.h>
#include <unistd.h>



void	ft_print(char *str)
{
	int i;

	i = 0;
	if (!str)
		write(1, "NULL", 4);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1,"\n", 1);
}

void	*ft_memset(void *ptr, int x, size_t n)
{ 
	char *c;
	long unsigned int i;
	
	c = (char *)ptr;
	i = 0;
	while (i < n && c[i] != '\0')
	{
		c[i] = x;
		i++;
	}
	return (ptr);
}

void	ft_bzero(char *s, int n)
{
	while (n > 0)
	{
		s[n - 1] = '\0';
		n--;
	}
}

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	char *dest;
	char *src;
	long unsigned int i;

	dest = (char *)to;
	src = (char *)from;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return(to);
}

void	*ft_memccpy(void *to, const void *from, int c, size_t n)
{
	unsigned long int i;
	char *dest;
	char *src;

	i = 0;
	dest = (char *)to;
	src = (char *)from;
	while (i < n) 
	{
		if (src[i] == c)
		{
			dest[i] = src[i];
			i++;
			return (to + i);
		}
		if (src[i] != c)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (NULL);
}

void	*ft_memmove(void *to, const void *from, size_t n)
{
	char *dest;
	const char *src;
	long unsigned int i;

	if (!to && !from)
		return (NULL);
	dest = (char *)to;
	src = (const char *)from;
	if (src + 1 == dest)
	{
		i = n;
		while (i-- > 0)
			dest[i - 1] = src[i - 1];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (to);
}

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	char *str1;
	char *str2;
	unsigned int i;

	str1 = (char*)ptr1;
	str2 = (char*)ptr2;
	i = 0;
	while (i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else 
		{
			if (str1[i] < str2[i])
				return (-1);
			if (str1[i] > str2[i])
				return (1);
		}
	}
	return (0);
}

int	main()
{
	char str[100] = "I am testing memset";
	char str2[100] = "I am testing bzero";
	char str3[100] = "Source";
	char str4[100] = "Destination";
	char str5[100] = "LearningIsMyLife";
	char str6[100] = "blablablablablabla";
	char str7[100] = "jedisbla";
//CHECK MEMCCPY	/*char nothello[] = "Won't b there";*/ 
	char hello[100] = "look outside";
	char world[100] = "if you need, World";

// test memset
	write(1, "\n", 1);
	ft_print(str);
	write(1, "\n", 1);
	ft_print("  testing with zeroes >");
	ft_memset(str + 5, 48, 7);
	ft_print(str);
	ft_print("  zzzzzzzzzz >");
	ft_memset(str, 'z', 12);
	ft_print(str);
	ft_print("  want some $ ? >");
	ft_memset(str, '$', 19);
	ft_print(str);
	ft_print("  more $ ? >");
	ft_memset(str + 19, '0', 1);
	ft_print(str);
	write(1, "\n", 1);

// test bzero
	ft_print(str2);
	write(1, "\n", 1);
	ft_print(" no bzero ? >");
	ft_bzero(str2 + 12, 4);
	ft_print(str2);
	ft_print("  enjoy the empty line >");
	ft_bzero(str2, 7);
	ft_print(str2);
	write(1, "\n", 1);

// test memcpy
	ft_print("I am testing memcpy");
	write(1, "\n", 1);
	ft_print(str3);
	ft_print(str4);
	ft_print("  What's your next...");
	ft_print(ft_memcpy(str3, str4, 11));
	ft_print(str3);
	write(1, "\n", 1);

//test memccpy
	ft_print("I am testing memccpy");
	write(1, "\n", 1);
	ft_print(world);
	ft_print("  Better...");
//CHECK IF NORMAL //
	/*ft_print(ft_memccpy(world, nothello, 'x', 12));*/
	ft_memccpy(world, hello, 'e', 20);
	ft_print(world);

// test memmove
	ft_print("I am testing memmove");
	write(1, "\n", 1);
	ft_print(str5);
	ft_print(str6);
	ft_print("  No overlap ?");
	ft_print(ft_memmove(str5 + 6, str5, 9));
	ft_print(str5);
	ft_memmove(str7, str6, 5);
	ft_print(str6);
	ft_print(str7);
	write(1, "\n", 1);

// test memcmp
	printf("%i\n", memcmp("blabla", "blabl1u", 6));
	printf("%i\n", ft_memcmp("blabla", "blabl1u", 6));

// test strchr

	printf("%s\n", strchr("I love bacon", 'o'));
	printf("%s\n", ft_strchr("I love bacon", 'o'));

// test strrchr

	printf("%s\n", strrchr("I love bacon", 'o'));
	printf("%s\n", ft_strrchr("I love bacon", 'o'));

	return (0);
}