#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>


char	*get_next_line(int fd);

int	ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
int	ft_strlen(const char *s);

#endif
