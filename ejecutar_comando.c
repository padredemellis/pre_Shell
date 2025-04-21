#include "shellminator.h"

/**
 * ejecutar_comando - Ejecuta un comando con sus argumentos.
 * @args: Array de argumentos.
 */
void ejecutar_comando(char **args)
{
        pid_t pid;
        int status;
        char *comando, *ruta_completa = NULL;
        char *path_env, *path_copy, *path_token;
        int tam_ruta;

        if (!args || !args[0])
                return;

        comando = args[0];

        if (strcmp(comando, "cd") == 0)
        {
                if (!args[1])
                        fprintf(stderr, "cd: falta el argumento de directorio\n");
                else if (chdir(args[1])
                        perror("cd");
        }
        else if (strcmp(comando, "exit") == 0)
        {
                exit(0);
        }
        else
        {
                pid = fork();
                if (pid == -1)
                {
                        perror("fork error");
                }
                else if (pid == 0)
                {
                        path_env = getenv("PATH");
                        if (!strchr(comando, '/') && path_env)
                        {
                                path_copy = strdup(path_env);
                                if (!path_copy)
                                        exit(EXIT_FAILURE);

                                path_token = strtok(path_copy, ":");
                                while (path_token)
                                {
                                        tam_ruta = strlen(path_token) + strlen(comando) + 2;
                                        ruta_completa = malloc(tam_ruta);
                                        if (!ruta_completa)
                                        {
                                                free(path_copy);
                                                exit(EXIT_FAILURE);
                                        }
                                        sprintf(ruta_completa, "%s/%s", path_token, comando);

                                        if (access(ruta_completa, X_OK) == 0)
                                                break;

                                        free(ruta_completa);
                                        ruta_completa = NULL;
                                        path_token = strtok(NULL, ":");
                                }
                                free(path_copy);
                        }
                        else
                        {
                                ruta_completa = strdup(comando);
                                if (!ruta_completa)
                                        exit(EXIT_FAILURE);
                        }

                        if (ruta_completa)
                        {
                                execve(ruta_completa, args, environ);
                                perror("execve error");
                                free(ruta_completa);
                                exit(EXIT_FAILURE);
                        }
                        else
                        {
                                fprintf(stderr, "%s: comando no encontrado\n", comando);
                                exit(127);
                        }
                }
                else
                {
                        waitpid(pid, &status, 0);
                        if (WIFEXITED(status))
                                printf("Estado: %d\n", WEXITSTATUS(status));
                        else if (WIFSIGNALED(status))
                                printf("Señal: %d\n", WTERMSIG(status));
                }
        }
}
