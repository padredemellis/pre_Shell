/***2. Línea de comandos a av**

Escribe una función que divida un string en un arreglo de palabras. Usa `strtok` (man strtok).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **cortar (char *s, const char *del)
{
	char **array = NULL;
	int count = 0;
	char *token;
	char *temp = strdup(s);
	int i;

	token = strtok(temp,del);

	while (token)
	{
		count ++;
		token = strtok (NULL, del);
	}
	free (temp);

	array = malloc((count +1) * sizeof(char*));
	if (!array)
		return (NULL);

	i = 0;
	token = strtok (s, del);

	while(token)
	{
		array[i] = strdup(token);
		if (!array[i])
		{
		free(array);
		return (NULL);
		}
		i++;
		token = strtok (NULL, del);
	}
	array[i] = NULL;
	return (array);
}
int main()
{
	char texto [] = "practicando pa la shell";
	const char *delimitadores = " \t\n";
	char **palabras = cortar (texto,delimitadores);
	int i;

	if (palabras)
	{
		for (i = 0; palabras[i] !=NULL; i++)
		{
			printf("Palabra %d: %s\n", i +1, palabras[i]);
		}
	}
	if (palabras)
	{
		for(i = 0; palabras[i] != NULL; i++)
		{
			free(palabras[i]);
		}
		free(palabras);
	}
	return (0);
}
