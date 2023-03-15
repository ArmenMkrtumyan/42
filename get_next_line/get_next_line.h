/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:26:28 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/03/11 15:28:09 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H	

/*		INCLUDES				*/

#include <unistd.h> //also for reading
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include <stdlib.h>
#include <string.h>

/*		FUNCTIONS				*/

char    *get_next_line(int fd);
size_t	ft_strlen(const char *word);
char	*ft_strjoin(char  *s1, char *s2);
char	*ft_substr(char const *s_1, unsigned int start, size_t len);
int     check_line_buffer(char **line,char **returnable, char *buffer);
char    *result_checker(char **line, char**returnable, char *buffer, int result);
#endif
