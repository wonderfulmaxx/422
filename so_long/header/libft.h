/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:39:28 by tbrissia          #+#    #+#             */
/*   Updated: 2022/04/12 18:08:41 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void	*ft_memset(void	*tab, int value, size_t count);
void	*ft_memmove(void *destination, const void *source, size_t size);
void	*ft_memchr(const void *src, int search, size_t size);
void	ft_bzero(void *tab, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memccpy(void *dst, void *src, int ch, size_t size);
int		ft_memcmp(const void *src1, const void *src2, size_t size);
size_t	ft_strlen(const char	*str);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, const char *src, unsigned int n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, unsigned int nb);
char	*ft_strchr(const char *str, int search);
char	*ft_strrchr(const char *str, int search);
char	*ft_strnstr(const char *str, const char *to_find, size_t size);
char	*ft_strstr(char *str, char *to_find);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
char	*ft_substr(char const *src, unsigned int start, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putstr(char const *str);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char	*s, int fd);
void	ft_putendl_fd(char	*s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/*********************************ft_printf************************************/

void	ft_bin_hex(unsigned long int add, int *count);
void	ft_putnbr_base_fd(int nbr, int fd, int *count);
void	ft_putnbr_base2_fd(int nbr, int fd, int *count);
void	ft_putnbr_pr_fd(int n, int fd, int *count);
void	ft_putnbr_pr2_fd(int n, int fd, int *count);
void	ft_putuns_fd(unsigned int n, int fd, int *count);
void	ft_percent(va_list ptr, const char *str, int i, int *count);
void	ft_ischar(va_list ptr, const char *str, int i, int *count);
int		ft_printf(const char *str, ...);

/*******************************get_next_line*******************************/

char    *ftG_strjoin(char *s1, char *s2);
size_t  ftG_strlen(const char *s);
int     ftG_strchr(char *str, int c);
char    *ft_read( int fd, char *buff, char *str, int res);
char    *get_next_line(int fd);

/*******************************my_fonction*********************************/

int		ft_power(int nb, int power);
void	ft_sort_int_tab(int *tab, int size);
void	ft_swap(int *a, int *b);

#endif
