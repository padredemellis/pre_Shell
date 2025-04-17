#include <stdlib.h>
#include <string.h>

/**
 * cortar - Divide un comando en tokens
 * @comando: Cadena de entrada con el comando
 * Return: Arreglo de tokens terminado en NULL
 */
char **cortar(char *comando)
{
	char *copia, *token;
	int contador = 0, i = 0;
	char **partes;

	copia = strdup(comando);
	if (!copia)
		return (NULL);

	token = strtok(copia, " \t\n");
	while (token)
	{
		contador++;
		token = strtok(NULL, " \t\n");
	}
	free(copia);

	partes = malloc((contador + 1) * sizeof(char *));
	if (!partes)
		return (NULL);

	token = strtok(comando, " \t\n");
	while (token && i < contador)
	{
		partes[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}
	partes[i] = NULL;

	return (partes);
}
