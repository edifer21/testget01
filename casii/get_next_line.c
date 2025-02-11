/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patferna <patferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:38:43 by patferna          #+#    #+#             */
/*   Updated: 2024/12/05 15:22:55 by patferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>  // Para read()
#include <stdlib.h>  // Para malloc() y free()
#include <string.h>  // Para ft_strchr() y ft_substr()
#include <stdio.h>   // Para perror()
#include "get_next_line.h"
#include "get_next_line.h"

#include "get_next_line.h"

char	*ft_free_strjoin(char *save, char *tmp)
{
	char	*new;

	// Usamos calloc para reservar memoria y asegurar que la nueva cadena esté inicializada
	new = ft_strjoin(save, tmp);
	free(save);  // Liberamos la memoria de save después de concatenarlo
	return (new);
}

char	*the_rest(char *save)
{
	int		i;
	int		n;
	char	*new_save;

	i = 0;
	// Buscar el salto de línea
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')  // Si no hay salto de línea, terminamos
	{
		free(save);
		return (NULL);
	}
	// Usamos calloc para reservar memoria para el resto de los caracteres después del salto de línea
	new_save = calloc(ft_strlen(save) - i + 1, sizeof(char));
	i++;
	n = 0;
	// Copiar el resto de la cadena después del salto de línea
	while (save[i] != '\0')
		new_save[n++] = save[i++];
	free(save);
	return (new_save);
}

char	*make_line_from(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (save[i] == '\0')  // Si no hay nada en save, devolvemos NULL
		return (NULL);
	// Buscar hasta el salto de línea
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	// Usamos calloc para crear la nueva línea y asegurar que esté inicializada a cero
	line = calloc(i + 2, sizeof(char));  // +2 para incluir el salto de línea
	i = 0;
	// Copiar la línea hasta el salto de línea o el final
	while (save[i] != '\0' && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')  // Si hay un salto de línea, lo añadimos
		line[i] = '\n';
	return (line);
}

char	*read_until_enter(int fd, char *save)
{
	int		n_of_chars;
	char	*tmp;

	if (!save)  // Si save es NULL, inicializarlo
		save = calloc(1, sizeof(char));  // Usamos calloc para inicializar save a NULL
	// Usamos calloc para reservar memoria para el buffer temporal
	tmp = calloc(BUFFER_SIZE + 1, sizeof(char));
	n_of_chars = 1;
	// Leer hasta encontrar un salto de línea o hasta el final del archivo
	while (n_of_chars > 0)
	{
		n_of_chars = read(fd, tmp, BUFFER_SIZE);
		if (n_of_chars == -1)  // Error de lectura
		{
			free(tmp);
			free(save);
			return (NULL);
		}
		tmp[n_of_chars] = '\0';  // Aseguramos que el buffer esté terminado en NULL
		save = ft_free_strjoin(save, tmp);
		if (ft_strchr(save, '\n'))  // Si encontramos un salto de línea, terminamos
			break ;
	}
	free(tmp);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	// Comprobación de entrada válida
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);

	// Leer hasta encontrar un salto de línea o llegar al final del archivo
	save = read_until_enter(fd, save);
	if (save == NULL)
		return (NULL);

	// Crear la línea desde el contenido de save
	line = make_line_from(save);
	// Actualizar save con el resto de los datos
	save = the_rest(save);

	return (line);
}


//-----------------------------------------------------------------------
/*
char	*get_next_line(int fd)
{
	static char	*save;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (!save)

		save = initialize_save();
	if (!save)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (handle_read_error(bytes_read, &save))
			return (NULL);
		if (bytes_read == 0)
			return (finalize_save(&save));
		buffer[bytes_read] = '\0';
		save = join_and_free(save, buffer);
		if (ft_strchr(save, '\n'))
		{
			char *line = extract_line(&save);
			if (!line) 
				return (NULL);
			return (line);
		}
	}
}
*/
