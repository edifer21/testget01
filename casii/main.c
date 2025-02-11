#include <stdio.h>
#include <fcntl.h>  // Para open()
#include <unistd.h> // Para close()
#include <stdlib.h> // Para free()
#include <string.h>

#include "get_next_line.h" // Asegúrate de que el archivo existe

void test_gnl(int fd, const char *expected)
{
    char *line = get_next_line(fd);
    
    if ((line == NULL && expected == NULL) || (line && expected && strcmp(line, expected) == 0))
    printf("DEBUG: Line received: \"%s\"\n", line);

        printf("✅ Test passed\n");
    else
        printf("❌ Test failed. Expected: \"%s\", Got: \"%s\"\n", expected, line ? line : "NULL");

    free(line); // Libera la memoria si la línea no es NULL
}

int main(void)
{
    int fd = open("1char.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir 1char.txt");
        return 1;
    }

    /* 1 */ test_gnl(fd, "0"); // Espera recibir "0"
    /* 2 */ test_gnl(fd, NULL); // Espera recibir NULL

    close(fd); // Cierra el archivo
    return 0;
}
