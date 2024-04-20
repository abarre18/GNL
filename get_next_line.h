#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

char			*get_next_line(int fd);
char			*fill_line_buffer(int fd, char *left_c, char *buf);
char			*set_line(char *line_buf);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
unsigned int	ft_strlen(const char *str);
char			*ft_strchr(const char *str, int chr);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(const char *str, unsigned int start, size_t len);

#endif
