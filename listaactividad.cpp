#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Pasajero {
    char nombre[50];
    int documento;
    int destino;
    struct Pasajero* siguiente;
} Pasajero;

// Crear un nuevo pasajero
Pasajero* crear_pasajero(char* nombre, int documento, int destino) {
    Pasajero* nuevo = (Pasajero*) malloc(sizeof(Pasajero));
    if (nuevo == NULL) return NULL;  
    strcpy(nuevo->nombre, nombre);
    nuevo->documento = documento;
    nuevo->destino = destino;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Registrar pasajero en la lista
void registrar_pasajero(Pasajero** cabeza, char* nombre, int documento, int destino) {
    Pasajero* nuevo = crear_pasajero(nombre, documento, destino);
    if (nuevo == NULL) return;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        Pasajero* temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

// Mostrar la lista de pasajeros
void mostrar_pasajeros(Pasajero* cabeza) {
    if (cabeza == NULL) {
        printf("No hay pasajeros registrados.\n");
        return;
    }

    printf("\nLista de pasajeros:\n");
    while (cabeza != NULL) {
        printf("Nombre: %s | Documento: %d | Destino: ", cabeza->nombre, cabeza->documento);
        switch (cabeza->destino) {
            case 1: printf("La Bocana\n"); break;
            case 2: printf("Piangüita\n"); break;
            case 3: printf("Ladrilleros\n"); break;
        }
        cabeza = cabeza->siguiente;
    }
}

// Ordenar pasajeros por destino y documento
void ordenar_pasajeros(Pasajero* cabeza) {
    if (cabeza == NULL) return;

    int intercambiado;
    Pasajero *actual, *temp = NULL;

    do {
        intercambiado = 0;
        actual = cabeza;

        while (actual->siguiente != temp) {
            if (actual->destino > actual->siguiente->destino || 
               (actual->destino == actual->siguiente->destino && actual->documento > actual->siguiente->documento)) {
                // Intercambiar directamente los datos aquí
                char temp_nombre[50];
                int temp_documento, temp_destino;

                strcpy(temp_nombre, actual->nombre);
                strcpy(actual->nombre, actual->siguiente->nombre);
                strcpy(actual->siguiente->nombre, temp_nombre);

                temp_documento = actual->documento;
                actual->documento = actual->siguiente->documento;
                actual->siguiente->documento = temp_documento;

                temp_destino = actual->destino;
                actual->destino = actual->siguiente->destino;
                actual->siguiente->destino = temp_destino;

                intercambiado = 1;
            }
            actual = actual->siguiente;
        }
        temp = actual;
    } while (intercambiado);
}

// Liberar la memoria dinámica
void liberar_memoria(Pasajero* cabeza) {
    Pasajero* temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

// Función principal con el menú
int main() {
    Pasajero* lista_pasajeros = NULL;
    int opcion;
    char nombre[50];
    int documento, destino;

    do {
        printf("\n Menu \n");
        printf("1. Registrar pasajero\n");
        printf("2. Mostrar pasajeros\n");
        printf("3. Ordenar pasajeros por destino\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // Captura el salto de línea

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre del pasajero: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar el salto de línea
                printf("Ingrese el número de documento: ");
                scanf("%d", &documento);
                printf("Ingrese el destino (1: La Bocana, 2: Piangüita, 3: Ladrilleros): ");
                scanf("%d", &destino);

                registrar_pasajero(&lista_pasajeros, nombre, documento, destino);
                printf("Pasajero registrado con éxito.\n");
                break;

            case 2:
                mostrar_pasajeros(lista_pasajeros);
                break;

            case 3:
                ordenar_pasajeros(lista_pasajeros);
                printf("Pasajeros ordenados correctamente.\n");
                break;

            case 4:
                printf("Saliendo del programa...\n");
                liberar_memoria(lista_pasajeros);
                break;

            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }

    } while (opcion != 4);

    return 0;
}
