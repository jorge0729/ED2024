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

int main() {
    FILE *archivo;
    archivo = fopen("pasajeros.dat", "ab+");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    Pasajero* lista_pasajeros = NULL;
    char nombre[50];
    int documento, destino;

    printf("=== Registro de Pasajeros ===\n");
    printf("Ingrese el nombre del pasajero: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
    
    printf("Ingrese el número de documento: ");
    scanf("%d", &documento);
    
    printf("Ingrese el destino (1: La Bocana, 2: Piangüita, 3: Ladrilleros): ");
    scanf("%d", &destino);

    registrar_pasajero(&lista_pasajeros, nombre, documento, destino);
    
    // Guardar en archivo
    if (lista_pasajeros != NULL) {
        fwrite(lista_pasajeros, sizeof(Pasajero), 1, archivo);
        printf("Pasajero registrado con éxito.\n");
    }

    fclose(archivo);
    free(lista_pasajeros);
    return 0;
}