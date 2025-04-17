/*
 * **1. Leer línea**

Escribe un programa que imprima `$` , espere un comando del usuario y lo muestre. Usa `getline` . Importante: manejar EOF (Ctrl+D).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t ret;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		ret = getline(&buffer,&len,stdin);
		
		if (ret == -1)
			break;

		printf("%s \n",buffer);
	}
	free(buffer);

	return(0);
}
