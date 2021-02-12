#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_bzero(char *s, size_t n);
void	*calloc(size_t n, size_t size);
int		ft_isalnum(int a);
int		ft_isalpha(int c);
int		ft_isascii(int t);
int		ft_isdigit(int n);
int		ft_isprint(int p);
void	*ft_memccpy(void *to, const void *from, int c, size_t n);
void	*ft_memchr(const void *ptr, int c, size_t n);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
void	*ft_memcpy(void *to, const void *from, size_t numBytes);
void	*ft_memmove(void *to, const void *from, size_t n);
void	*ft_memset(void *ptr, int x, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *src);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *str, int c);
int		ft_tolower(int l);
int		ft_toupper(int u);

#endif