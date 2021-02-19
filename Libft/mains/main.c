#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>


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

char	ft(unsigned int i, char c)
{
//test strmapi
	c = i;
	return (c);
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
	char c;

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
	ft_print("I am testing memmove\n");
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
	ft_print("I am testing memcmp\n");
	printf("%i\n", memcmp("blabla", "blabl1u", 6));
	printf("%i\n", ft_memcmp("blabla", "blabl1u", 6));

// test strchr

	ft_print("I am testing strchr\n");
	printf("%s\n", strchr("I love bacon", 'o'));
	printf("%s\n", ft_strchr("I love bacon", 'o'));

// test strrchr
	ft_print("I am testing strrchr\n");
	printf("%s\n", strrchr("I love bacon", 'o'));
	printf("%s\n", ft_strrchr("I love bacon", 'o'));

// test strnstr
	ft_print("I am testing strnstr\n");
	printf("%s\n", ft_strnstr("I love bacon", "bacon", 12));
	printf("%s\n", ft_strnstr("I love bacon", "bacon", 10));
	printf("%s\n", ft_strnstr("I love bacon", "jelly", 10));

// test strncmp
	ft_print("I am testing strncmp\n");
	printf("%i\n", strncmp("I love bacon", "I love jelly", 8));
	printf("%i\n", ft_strncmp("I love bacon", "I love jelly", 8));

// test atoi
	ft_print("I am testing atoi\n");
	char strn1[] = "     \v12546";
 
    printf("String value = %s\n", strn1);
    printf("Integer value = %d\n", atoi(strn1));
	printf("Custom made value = %d\n", ft_atoi(strn1));
 
    char strn2[] = "GeeksforGeeks";
    printf("String value = %s\n", strn2);
    printf("Integer value = %d\n", atoi(strn2));
	printf("Custom made value = %d\n", ft_atoi(strn2));

	char strn3[100] = "99999999999999999999999999";
    printf("String value = %s\n", strn3);
    printf("Integer value = %d\n", atoi(strn3));
	printf("Custom made value = %d\n", ft_atoi(strn3));
	

// test isft
	ft_print("I am testing is_ft\n");
	c = 'z';
	printf("isalpha\n");
	printf("c = %c, result = %i\n", c, isalpha(c));
	printf("c = %c, result = %i\n", c, ft_isalpha(c));
	printf("isdigit\n");
	printf("c = %c, result = %i\n", c, isdigit(c));
	printf("c = %c, result = %i\n", c, ft_isdigit(c));
	printf("isalnum\n");
	printf("c = %c, result = %i\n", c, isalnum(c));
	printf("c = %c, result = %i\n", c, ft_isalnum(c));
	printf("isascii\n");
	printf("c = %c, result = %i\n", c, isascii(c));
	printf("c = %c, result = %i\n", c, ft_isascii(c));
	printf("isprint\n");
	printf("c = %c, result = %i\n", c, isprint(c));
	printf("c = %c, result = %i\n", c, ft_isprint(c));

	c = 'Y';
	printf("isalpha\n");
	printf("c = %c, result = %i\n", c, isalpha(c));
	printf("c = %c, result = %i\n", c, ft_isalpha(c));
	printf("isdigit\n");
	printf("c = %c, result = %i\n", c, isdigit(c));
	printf("c = %c, result = %i\n", c, ft_isdigit(c));
	printf("isalnum\n");
	printf("c = %c, result = %i\n", c, isalnum(c));
	printf("c = %c, result = %i\n", c, ft_isalnum(c));
	printf("isascii\n");
	printf("c = %c, result = %i\n", c, isascii(c));
	printf("c = %c, result = %i\n", c, ft_isascii(c));
	printf("isprint\n");
	printf("c = %c, result = %i\n", c, isprint(c));
	printf("c = %c, result = %i\n", c, ft_isprint(c));

	c = '9';
	printf("isalpha\n");
	printf("c = %c, result = %i\n", c, isalpha(c));
	printf("c = %c, result = %i\n", c, ft_isalpha(c));
	printf("isdigit\n");
	printf("c = %c, result = %i\n", c, isdigit(c));
	printf("c = %c, result = %i\n", c, ft_isdigit(c));
	printf("isalnum\n");
	printf("c = %c, result = %i\n", c, isalnum(c));
	printf("c = %c, result = %i\n", c, ft_isalnum(c));
	printf("isascii\n");
	printf("c = %c, result = %i\n", c, isascii(c));
	printf("c = %c, result = %i\n", c, ft_isascii(c));
	printf("isprint\n");
	printf("c = %c, result = %i\n", c, isprint(c));
	printf("c = %c, result = %i\n", c, ft_isprint(c));

	c = '\v';
	printf("isalpha\n");
	printf("c = %c, result = %i\n", c, isalpha(c));
	printf("c = %c, result = %i\n", c, ft_isalpha(c));
	printf("isdigit\n");
	printf("c = %c, result = %i\n", c, isdigit(c));
	printf("c = %c, result = %i\n", c, ft_isdigit(c));
	printf("isalnum\n");
	printf("c = %c, result = %i\n", c, isalnum(c));
	printf("c = %c, result = %i\n", c, ft_isalnum(c));
	printf("isascii\n");
	printf("c = %c, result = %i\n", c, isascii(c));
	printf("c = %c, result = %i\n", c, ft_isascii(c));
	printf("isprint\n");
	printf("c = %c, result = %i\n", c, isprint(c));
	printf("c = %c, result = %i\n", c, ft_isprint(c));

// test toft
	ft_print("I am testing to_ft\n");
	c = 'D';
	printf("toupper\n");
	printf("c = %c || c = %i\n", c, toupper(c));
	printf("c = %c || c = %i\n", c, ft_toupper(c));
	printf("tolower\n");
	printf("c = %c || c = %i\n", c, tolower(c));
	printf("c = %c || c = %i\n", c, ft_tolower(c));

	c = 'd';
	printf("toupper\n");
	printf("c = %c || c = %i\n", c, toupper(c));
	printf("c = %c || c = %i\n", c, ft_toupper(c));
	printf("tolower\n");
	printf("c = %c || c = %i\n", c, tolower(c));
	printf("c = %c || c = %i\n", c, ft_tolower(c));

	c = '9';
	printf("toupper\n");
	printf("c = %c || c = %i\n", c, toupper(c));
	printf("c = %c || c = %i\n", c, ft_toupper(c));
	printf("tolower\n");
	printf("c = %c || c = %i\n", c, tolower(c));
	printf("c = %c || c = %i\n", c, ft_tolower(c));

// test itoa

	printf("I am testing itoa\n");
	printf("nb input = %i char output = %s\n", 123456, ft_itoa(123456));
	printf("nb input = %i char output = %s\n", -123456, ft_itoa(-123456));
	printf("nb input = %i char output = %s\n", -2147483648, ft_itoa(-2147483648));
	printf("nb input = %i char output = %s\n", 2147483647, ft_itoa(21474836476));

// test strtrim

	char	*sandale;
	char	*sandale2;
	char 	*sandale3;
	char	*sandale4;
	char	*set;

	set = "\t \n";
	sandale = "je porte des sandales\t \n";
	sandale4 = ft_strtrim(sandale, set);
	printf("before = %safter = %s\n", sandale, sandale4);
	free(sandale4);
	sandale2 ="          ";
	sandale3 = ft_strtrim(sandale2, set);
	printf("before = %s after = %s\n", sandale2, sandale3);
	free(sandale3);
	return (0);

// test split // test one, one after the other.

	char	**lol;
	int		i;

	i = 0;
	lol = ft_split("   lorem   ipsum dolor     sit amet  ", ' ');
	while (lol[i] != 0)
	{
		printf("%s\n", lol[i]);
		free(lol[i]);
		i++;
	}
	free(lol);
	printf("\n");

	/*lol = ft_split2("lalalala", 'i');
	while (lol[i] != 0)
	{
		printf("%s\n", lol[i]);
		free(lol[i]);
		i++;
	}
	free(lol);
	printf("\n");

	lol = ft_split("", 'i');
	while (lol[i] != 0)
	{
		printf("%s // this should be empty\n", lol[i]);
		free(lol[i]);
		i++;
	}
	free(lol);

	lol = ft_split("lorem ipsum .", '\0');
	while (lol[i] != 0)
	{
		printf("%s\n", lol[i]);
		free(lol[i]);
		i++;
	}
	free(lol);*/

// test substr

	char	*flip = "je suis flip flop";
	char	*flop = ft_substr(flip, 3, 4);
	char	*flip1 = "je suis flip flop";
	char	*flop1 = ft_substr(flip1, 8, 4);
	char	*flip2 = "je suis flip flop";
	char	*flop2 = ft_substr(flip2, 13, 4);
	char	*flip3 = "je suis flip flop";
	char	*flop3 = ft_substr(flip3, 6, 0);
	char	*flip4 = "";
	char	*flop4 = ft_substr(flip4, 6, 3);

	printf("flip = %s flop = %s\n", flip, flop);
	free(flop);
	printf("flip1 = %s flop1 = %s\n", flip1, flop1);
	free(flop1);
	printf("flip2 = %s flop2 = %s\n", flip2, flop2);
	free(flop2);
	printf("flip3 = %s flop3 = %s\n", flip3, flop3);
	free(flop3);
	printf("flip4 = %s flop4 = %s\n", flip4, flop4);
	free(flop4);

// test strmapi

	char	*blabla = "blablabla";
	char	*bla;
	char 	(*f)(unsigned int, char);

	f = &ft;
	bla = ft_strmapi(blabla, f);
	printf("blabla = %s\n bla = %s\n", blabla, bla);
	free(bla);

	return (0);
}