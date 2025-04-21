#ifndef SHELLMINATOR_H
#define SHELLMINATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* Prototipos de funciones */
void mostrar_prompt(void);
char *leer_entrada(void);
char **analizar_entrada(char *linea);
void ejecutar_comando(char **args);

#endif /* SHELLMINATOR_H */
