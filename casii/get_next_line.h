/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patferna <patferna@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-20 12:49:57 by patferna          #+#    #+#             */
/*   Updated: 2024-11-20 12:49:57 by patferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*extract_line(char **save);
char	*finalize_save(char **save);
char	*join_and_free(char *save, char *buffer);
char	*initialize_save(void);
int		handle_read_error(ssize_t bytes_read, char **save);

#endif



/*
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif



char *get_next_line(int fd);
char *ft_strjoin(const char *s1, const char *s2);
char *ft_strdup(const char *s);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
char *ft_strndup(const char *s, size_t n);
char *extract_line(char **save);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*finalize_save(char **save);
char	*join_and_free(char *save, char *buffer);
char	*initialize_save(void);
int	handle_read_error(ssize_t bytes_read, char **save);

#endif

*/
