#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos la estructura del pasajero
typedef struct Pasajero {
    char nombre[50];
    int documento;
    int destino; // 1: La Bocana, 2: Piangüita, 3: Ladrilleros
    struct Pasajero *siguiente;
} Pasajero;

// Función para crear un nuevo pasajero
Pasajero* crearPasajero(char nombre[], int documento, int destino) {
    Pasajero nuevo = (Pasajero)malloc(sizeof(Pasajero));
    strcpy(nuevo->nombre, nombre);
    nuevo->documento = documento;
    nuevo->destino = destino;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Función para registrar un nuevo pasajero
void registrarPasajero(Pasajero **cabeza) {
    char nombre[50];
    int documento, destino;
    printf("Ingrese el nombre del pasajero: ");
    scanf("%s", nombre);
    printf("Ingrese el número de documento: ");
    scanf("%d", &documento);
    printf("Ingrese el destino (1: La Bocana, 2: Piangüita, 3: Ladrilleros): ");
    scanf("%d", &destino);

    Pasajero *nuevo = crearPasajero(nombre, documento, destino);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

// Función para mostrar la lista de pasajeros
void mostrarPasajeros(Pasajero *cabeza) {
    Pasajero *actual = cabeza;
    while (actual != NULL) {
        printf("Nombre: %s, Documento: %d, Destino: %d\n", actual->nombre, actual->documento, actual->destino);
        actual = actual->siguiente;
    }
}

// Función para ordenar los pasajeros usando el método de burbuja
void ordenarPasajeros(Pasajero *cabeza) {
    if (cabeza == NULL) return;

    Pasajero *i, *j;
    int tempDocumento, tempDestino;
    char tempNombre[50];

    for (i = cabeza; i->siguiente != NULL; i = i->siguiente) {
        for (j = i->siguiente; j != NULL; j = j->siguiente) {
            if (i->destino > j->destino || (i->destino == j->destino && i->documento > j->documento)) {
                // Intercambiar datos
                strcpy(tempNombre, i->nombre);
                strcpy(i->nombre, j->nombre);
                strcpy(j->nombre, tempNombre);

                tempDocumento = i->documento;
                i->documento = j->documento;
                j->documento = tempDocumento;

                tempDestino = i->destino;
                i->destino = j->destino;
                j->destino = tempDestino;
            }
        }
    }
}

int main() {
    Pasajero *cabeza = NULL;
    int opcion;

    do {
        printf("1. Registrar pasajero\n");
        printf("2. Mostrar pasajeros\n");
        printf("3. Ordenar pasajeros\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarPasajero(&cabeza);
                break;
            case 2:
                mostrarPasajeros(cabeza);
                break;
            case 3:
                ordenarPasajeros(cabeza);
                printf("Pasajeros ordenados.\n");
                break;
            case 4:
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 4);

    // Liberar memoria
    Pasajero *actual = cabeza;
    while (actual != NULL) {
        Pasajero *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }

    return 0;
}