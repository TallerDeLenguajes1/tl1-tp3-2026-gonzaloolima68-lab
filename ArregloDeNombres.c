#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BuscarNombre(int id, char *nombre[])
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
        puts("No se encontro el valor");
    }
}

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

    int id;
    printf("ingrese Un id a buscar");
    scanf("%d", &id);
    BuscarNombre(id, nombre);

    return 0;
}