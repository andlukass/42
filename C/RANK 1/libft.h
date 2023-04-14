#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int ft_strlen(const char *s);

int ft_isalpha(int c);

int ft_isalnum(int c);

int ft_isdigit(int c);

int ft_isascii(int c);

int ft_isprint(int c);

int ft_toupper(int c);

int ft_tolower(int c);

int ft_atoi(const char *str);

int ft_strncmp(const char *s1, const char *s2, size_t n);

char *ft_strnstr(const char *haystack, const char *needle, size_t len);

size_t ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize);

char *ft_strdup(const char *s1);

char *strchr(const char *s, int c);

char *strrchr(const char *s, int c);

void ft_bzero(void *s, size_t n);

void *ft_memset(void *b, int c, size_t len);

void *ft_memcpy(void *dest, const void *src, size_t n);

int ft_memcmp(const void *s1, const void *s2, size_t n);

void *ft_calloc(size_t nmemb, size_t size);

#endif