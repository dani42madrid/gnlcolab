/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:57:02 by danielm3          #+#    #+#             */
/*   Updated: 2025/02/24 17:42:29 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*dirtyline = NULL;
	char		*cleanline;
	char		*remainder;
	char		*buffer;
	ssize_t		readbytes;

	if (!dirtyline) // esta condición solo se debería dar en la 1ª ejecución
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); // malloc
		readbytes = read(fd, buffer, BUFFER_SIZE);
		buffer[readbytes] = '\0';
		dirtyline = ft_strdup(buffer); // malloc
	}
	if (dirtyline)
	{
		while (ft_strchr(dirtyline, '\n'))
		{
			remainder = ft_strchr(dirtyline, '\n');
			cleanline = ft_substr(dirtyline, 0, remainder - dirtyline + 1); // malloc
			free
			dirtyline = ft_strdrup(remainder);
			
			return (cleanline);
			
		}
	}
	
		cleanline = dirtyline;
	return (cleanline);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("hitchhiker.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	printf("%i: %s\n", i++, line);
/* 	while (line != NULL)
	{
		printf("%i: %s\n", i++, line);
		line = get_next_line(fd);
	} */
	close(fd);
	return (0);
}
