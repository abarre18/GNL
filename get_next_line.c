#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;
	char		*buf;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(s);
		free(buf);
		s = NULL;
		buf = NULL;
		return (NULL);
	}
	if (!buf)
		return (NULL);
	line = fill_line_buffer(fd, s, buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	s = set_line(line);
	return (line);
}

char	*fill_line_buffer(int fd, char *s, char *buf)
{
	ssize_t	bytes_readed;
	char	*tmp;

	bytes_readed = 1;
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, buf, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(s);
			return (NULL);
		}
		else if (bytes_readed == 0)
			break ;
		buf[bytes_readed] = '\0';
		if (!s)
			s = ft_strdup("");
		tmp = s;
		s = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (s);
}

char	*set_line(char *s_buf)
{
	char	*s;
	ssize_t	x;

	x = 0;
	while (s_buf[x] != '\n' && s_buf[x] != '\0')
		x++;
	if (s_buf[x] == '\0' || s_buf[x + 1] == '\0')
		return (NULL);
	s = ft_substr(s_buf, x + 1, ft_strlen(s_buf) - x);
	if (*s == 0)
	{
		free(s);
		s = NULL;
	}
	s_buf[x + 1] = '\0';
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*element;

	if (size != 0 && count > (size_t) - 1 / size)
		return (NULL);
	element = malloc(count * size);
	if (!element)
		return (NULL);
	ft_bzero(element, (count * size));
	return (element);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			x;

	dest = s;
	x = 0;
	while (x < n)
	{
		*dest = 0;
		dest++;
		x++;
	}
}
