/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:24:09 by mmata-al          #+#    #+#             */
/*   Updated: 2023/12/06 20:26:45 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//#ifdef BUFF = 42

void	clean_buff(char *buffer)
{
	int	this;

	this = 0;
	while (this < BUFFER_SIZE)
	{
		buffer[this] = 0;
		this++;
	}
}

void	buffer_neat(char *nlp, char *buf)
{
	if (nlp[1] == '\0')
		clean_buff(buf);
	else
		ft_strcpy(buf, nlp + 1);
}

char	*get_next_line(int fd)
{	
	static char	shira[BUFFER_SIZE + 1];
	char		*result;
	char		*melon; //null pointer
	
	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
	{
		clean_buff(shira);
		return(NULL);
	}
	result = NULL;
	while (shira[0] || read(fd, shira, BUFFER_SIZE))
	{
		melon = ft_strchr(shira, '\n');
		result = ftstrjoiner(result, shira);
		if (melon)
		{
			buffer_neat(melon, shira);
			break ;
		}
		else
			clean_buff(shira);	
	}
	//printf("\nshira: %s\nresult: %s\nmelon: %d\n", shira, result, melon);	
	return (result);
}
//fazer strchr pra limpar buffer depois da nova linha

// hello there
// yeap

// 7
// hello there\nye
// here\nye\0
// ye\0dfghjkl
#include <fcntl.h>

int main (void)
{
	int i;

	i = 0;
	int fd = open("file.txt", O_RDONLY);
	while (i < 5)
	{
		char *s = get_next_line(fd);
		printf("\n\n%s", s);
		if (!s)
			break ;
		i++;
	}
	printf ("%s", get_next_line(fd));
	close(fd);
}
