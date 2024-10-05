#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pasajero {
    char nombre[50];
    int documento;
    int destino;
    struct Pasajero* siguiente;
} Pasajero;

void mostrar_pasajeros() {
    FILE *archivo;
    archivo = fopen("pasajeros.dat", "rb");
    if (archivo == NULL) {
        printf("No hay registros de pasajeros.\n");
        return;
    }

    Pasajero pasajero;
    printf("\n=== Lista de Pasajeros ===\n");
    
    while (fread(&pasajero, sizeof(Pasajero), 1, archivo)) {
        printf("Nombre: %s | Documento: %d | Destino: ", pasajero.nombre, pasajero.documento);
        switch (pasajero.destino) {
            case 1: printf("La Bocana\n"); break;
            case 2: printf("Piangüita\n"); break;
            case 3: printf("Ladrilleros\n"); break;
        }
    }

    fclose(archivo);
}

int main() {
    mostrar_pasajeros();
    return 0;
}