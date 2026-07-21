#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int BuscarNombreporpalabra(char palabra[], char *nombre[]);

void BuscarNombreporid(int id, char *nombre[]);

int main()
{
    char buff[100];
    char *nombre[5];

    for (int i = 0; i < 5; i++)
    {
        printf("ingrese el nombre \n");
        fgets(buff, 100, stdin);
        buff[strcspn(buff, "\n")] = '\0';
        nombre[i] = (char *)malloc(sizeof(char) * (strlen(buff) + 1));
        strcpy(nombre[i], buff);
    }

    for (int i = 0; i < 5; i++)
    {
        puts(nombre[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%s \n", nombre[i]);
    }

    int opcion, id;
    do
    {
        printf("======== Menu ========");
        printf("1-Buscar por id\n");
        printf("2-Buscar por palabra\n");
        printf("0-Salir\n");
        printf("ingrese la opcion\n");
        scanf("%d", &opcion);
        if (opcion == 1)
        {
            printf("ingrese Un id a buscar\n");
            scanf("%d", &id);
            BuscarNombreporid(id, nombre);
        }
        else if (opcion == 2)
        {
            printf("\ningrese la palabra\n");
            fgets(buff, 100, stdin);
            buff[strcspn(buff, "\n")] = '\0';
            char *palabra;
            palabra = (char *)malloc((strlen(buff) + 1) * sizeof(char));
            strcpy(palabra, buff);
            int id = BuscarNombreporpalabra(palabra, nombre);
            if (id != -1)
            {
                puts(nombre[id]);
            }
            else
            {
                printf("\nno se encontro esa palabra\n");
            }
        }

    } while (opcion > 0 && opcion < 3);

    return 0;
}

int BuscarNombreporpalabra(char palabra[], char *nombre[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strstr(nombre[i], palabra) != NULL)
        {
            return i;
        }
    }
    return -1;
}

void BuscarNombreporid(int id, char *nombre[])
{
    int aux = 0;
    for (int i = 0; i < 5; i++)
    {
        if (id == i)
        {
            aux = 1;
        }
    }

    if (aux == 1)
    {
        puts(nombre[id]);
    }
    else
    {
        puts("\nNo se encontro el valor\n");
    }
}