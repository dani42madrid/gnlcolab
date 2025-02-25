/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:57:02 by danielm3          #+#    #+#             */
/*   Updated: 2025/02/25 19:58:38 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("hitchhiker.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while (line)
	{
		line = get_next_line(fd);
		printf("%i: %s", i++, line);
		free(line);
	}
	printf("\n");
	close(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*dirtyline = NULL;
	char		*cleanline;
	char		*remainder;
	char		*buffer;
	char		*temp;
	ssize_t		readbytes;

	if (!dirtyline) // esta condición solo se debería dar en la 1ª ejecución
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); // malloc
		if (!buffer)
			return (NULL);
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes > 0)
			buffer[readbytes] = '\0';
		else
			return (NULL);
		dirtyline = ft_strdup(buffer); // malloc
		free(buffer);
		if (!dirtyline) // puede que sobre
			return (NULL);
	}
	if (dirtyline)
	{
		while (!ft_strchr(dirtyline, '\n') && readbytes > 0)
		{
			buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); // malloc
			if (!buffer)
				return (NULL);
			readbytes = read(fd, buffer, BUFFER_SIZE);
			if (readbytes > 0)
			{
				buffer[readbytes] = '\0';
				temp = ft_strdup(dirtyline);
				free(dirtyline);
				dirtyline = ft_strjoin(temp, buffer);
				if (!dirtyline)
					return (NULL);
				free(buffer);
				free(temp);
			}
			else
				return (NULL);
		}
		if (ft_strchr(dirtyline, '\n'))
		{
			remainder = ft_strchr(dirtyline, '\n') + 1;
			cleanline = ft_substr(dirtyline, 0, remainder - dirtyline); // malloc
			if (!cleanline)
				return(NULL);
			temp = ft_strdup(remainder);
			if (!temp)
				return(NULL);
			free(dirtyline);
			dirtyline = ft_strdup(temp);
			free(temp);
			return (cleanline);
		}
	}
	return (dirtyline);
}
