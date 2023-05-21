/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:01:53 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/03/27 20:28:03 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*		INCLUDES				*/

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

/*		FUNCTIONS				*/

char	*get_next_line(int fd);
size_t	ft_strlen(const char *word);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s_1, unsigned int start, size_t len);
int		result_checker(char **line,
			char **returnable, char *buffer, int result);
void	free_memory_1(char ***line);
void	free_memory_2(char ***line, int i);
int		check_buffer(char *buffer);
int		check_line(char **line, char **returnable);

#endif