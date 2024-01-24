/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:24:02 by mmata-al          #+#    #+#             */
/*   Updated: 2023/12/06 20:19:22 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

size_t	ft_strlenn(const char *s);
void	ft_strcpy(char *dest, const char *src);
char	*get_next_line(int fd);
void	clean_buff(char *buffer);
void	buffer_neat(char *nlp, char *buf);
char	*ft_strchr(const char *s, int c);
char	*ftstrjoiner(char *s1, char *s2);

#endif