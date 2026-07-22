#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable
                                 //  “CantidadProductosAPedir”
} Cliente;

float CostoTotal(Producto *p)
{
    return p->Cantidad * p->PrecioUnitario;
};

int main()
{
    srand(time(NULL));
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    char buff[100];

    int cant, id;
    printf("ingrese la Cantidad de clientes \n");
    scanf("%d", &cant);
    getchar();

    Cliente *Clientes = (Cliente *)malloc(sizeof(Cliente) * cant);
    char *nombres[cant];

    for (int i = 0; i < cant; i++)
    {
        Clientes[i].ClienteID = i + 1;
        printf("\ningrese el nombre del Cliente \n");
        fgets(buff, 100, stdin);
        buff[strcspn(buff, "\n")] = '\0';
        nombres[i] = (char *)malloc(sizeof(char) * (strlen(buff) + 1));
        strcpy(nombres[i], buff);
        Clientes[i].NombreCliente = nombres[i];
        Clientes[i].CantidadProductosAPedir = 1 + rand() % (5 - 1 + 1);
        Clientes[i].Productos = (Producto *)malloc(sizeof(Producto) * Clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++)
        {
            printf("Ingrese el ID del Producto \n");
            scanf("%d", &id);
            Clientes[i].Productos[j].ProductoID = id;
            Clientes[i].Productos[j].Cantidad = rand() % 10 + 1;
            Clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            Clientes[i].Productos[j].PrecioUnitario = 10 + rand() % (100 - 10 + 1);
        }
        getchar();
    }

    float precio, precio_total;

    for (int i = 0; i < cant; i++)
    {
        precio_total = 0;
        printf("\n ==============================\n");
        printf("\nNombre deL cliente : %s\n", Clientes[i].NombreCliente);
        printf("Cantidad de Produtos distintos a llevar : %d\n", Clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++)
        {
            printf("Producto: %s Cantidad: %d Precio unitario: %.2f \n", Clientes[i].Productos[j].TipoProducto, Clientes[i].Productos[j].Cantidad, Clientes[i].Productos[j].PrecioUnitario);
            precio = CostoTotal(&Clientes[i].Productos[j]);
            printf("Precio de los productos %.2f\n", precio);
            precio_total += precio;
        }
        printf("Precio Total a Pagar : %.2f\n", precio_total);
        printf("\n");
    }

    for (int i = 0; i < cant; i++)
    {
        free(Clientes[i].NombreCliente);
        free(Clientes[i].Productos);
    }
    free(Clientes);

      for (int i = 0; i < cant; i++)
    {
        precio_total = 0;
        printf("\n ==============================\n");
        printf("\nNombre deL cliente : %s\n", Clientes[i].NombreCliente);
        printf("Cantidad de Produtos distintos a llevar : %d\n", Clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++)
        {
            printf("Producto: %s Cantidad: %d Precio unitario: %.2f \n", Clientes[i].Productos[j].TipoProducto, Clientes[i].Productos[j].Cantidad, Clientes[i].Productos[j].PrecioUnitario);
            precio = CostoTotal(&Clientes[i].Productos[j]);
            printf("Precio de los productos %.2f\n", precio);
            precio_total += precio;
        }
        printf("Precio Total a Pagar : %.2f\n", precio_total);
        printf("\n");
    }

    return 0;
}