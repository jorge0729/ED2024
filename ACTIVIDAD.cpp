#include <iostream>
#include <string>

using namespace std;


struct NodoEstudiante {
    string primerNombre;
    int codigoEstudiantil;
    double nota;
    NodoEstudiante* siguiente;
};


class ListaEnlazada {
private:
    NodoEstudiante* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}


    void insertarEstudiante(string primerNombre, int codigoEstudiantil, double nota) {
        NodoEstudiante* nuevoNodo = new NodoEstudiante();
        nuevoNodo->primerNombre = primerNombre;
        nuevoNodo->codigoEstudiantil = codigoEstudiantil;
        nuevoNodo->nota = nota;
        nuevoNodo->siguiente = nullptr;

        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            NodoEstudiante* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

   
    void ordenarPorCodigoEstudiantil() {
        bool swapped;
        NodoEstudiante* temp = cabeza;

        while (temp != nullptr) {
            swapped = false;
            NodoEstudiante* temp2 = temp;
            while (temp2->siguiente != nullptr) {
                if (temp2->codigoEstudiantil > temp2->siguiente->codigoEstudiantil) {
                   
                    string tempNombre = temp2->primerNombre;
                    int tempCodigoEstudiantil = temp2->codigoEstudiantil;
                    double tempNota = temp2->nota;

                    temp2->primerNombre = temp2->siguiente->primerNombre;
                    temp2->codigoEstudiantil = temp2->siguiente->codigoEstudiantil;
                    temp2->nota = temp2->siguiente->nota;

                    temp2->siguiente->primerNombre = tempNombre;
                    temp2->siguiente->codigoEstudiantil = tempCodigoEstudiantil;
                    temp2->siguiente->nota = tempNota;

                    swapped = true;
                }
                temp2 = temp2->siguiente;
            }
            if (!swapped) {
                break;
            }
        }
    }

    void ordenarPorNota() {
        bool swapped;
        NodoEstudiante* temp = cabeza;

        while (temp != nullptr) {
            swapped = false;
            NodoEstudiante* temp2 = temp;
            while (temp2->siguiente != nullptr) {
                if (temp2->nota < temp2->siguiente->nota) {
                    
                    string tempNombre = temp2->primerNombre;
                    int tempCodigoEstudiantil = temp2->codigoEstudiantil;
                    double tempNota = temp2->nota;

                    temp2->primerNombre = temp2->siguiente->primerNombre;
                    temp2->codigoEstudiantil = temp2->siguiente->codigoEstudiantil;
                    temp2->nota = temp2->siguiente->nota;

                    temp2->siguiente->primerNombre = tempNombre;
                    temp2->siguiente->codigoEstudiantil = tempCodigoEstudiantil;
                    temp2->siguiente->nota = tempNota;

                    swapped = true;
                }
                temp2 = temp2->siguiente;
            }
            if (!swapped) {
                break;
            }
        }
    }

   
    void encontrarMayorNota() {
        double maxNota = 0.0;
        string estudianteMayorNota;
        NodoEstudiante* temp = cabeza;
        while (temp != nullptr) {
            if (temp->nota > maxNota) {
                maxNota = temp->nota;
                estudianteMayorNota = temp->primerNombre;
            }
            temp = temp->siguiente;
        }
        cout << "La mayor nota es de " << maxNota << " y pertenece a " << estudianteMayorNota << endl;
    }

    void encontrarMenorNota() {
        double minNota = cabeza->nota;
        string estudianteMenorNota = cabeza->primerNombre;
        NodoEstudiante* temp = cabeza;
        while (temp != nullptr) {
            if (temp->nota < minNota) {
                minNota = temp->nota;
                estudianteMenorNota = temp->primerNombre;
            }
            temp = temp->siguiente;
        }
        cout << "La menor nota es de " << minNota << " y pertenece a " << estudianteMenorNota << endl;
    }

    double calcularPromedio() {
        double sumNota = 0.0;
        int count = 0;
        NodoEstudiante* temp = cabeza;
        while (temp != nullptr) {
            sumNota += temp->nota;
            count++;
            temp = temp->siguiente;
        }
        return sumNota / count;
    }

   
    void mostrarEstudiantes() {
        NodoEstudiante* temp = cabeza;
        while (temp != nullptr) {
            cout << "Primer nombre: " << temp->primerNombre << endl;
            cout << "Código estudiantil: " << temp->codigoEstudiantil << endl;
            cout << "Nota: " << temp->nota << endl;
            cout << "------------------------" << endl;
            temp = temp->siguiente;
        }
    }
};

int main() {
    ListaEnlazada listaEstudiantes;

    int opcion;
    do {
        cout << "Menú de opciones:" << endl;
        cout << "1. Ingresar datos de estudiantes" << endl;
        cout << "2. Ordenar y mostrar la lista de estudiantes" << endl;
        cout << "3. Mostrar la mayor nota, menor nota y promedio del curso" << endl;
        cout << "4. Salir del programa" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string primerNombre;
                int codigoEstudiantil;
                double nota;

                cout << "Ingrese el primer nombre del estudiante: ";
                cin.ignore(); 
                getline(cin, primerNombre); 
                cout << "Ingrese el código estudiantil: ";
                cin >> codigoEstudiantil;
                cout << "Ingrese la nota del estudiante: ";
                cin >> nota;

                listaEstudiantes.insertarEstudiante(primerNombre, codigoEstudiantil, nota);
                break;
            }
            case 2:
                int ordenarOpcion;
                cout << "Ordenar por:" << endl;
                cout << "1. Código estudiantil" << endl;
                cout << "2. Nota" << endl;
                cout << "Ingrese una opción: ";
                cin >> ordenarOpcion;

                switch (ordenarOpcion) {
                    case 1:
                        listaEstudiantes.ordenarPorCodigoEstudiantil();
                        break;
                    case 2:
                        listaEstudiantes.ordenarPorNota();
                        break;
                    default:
                        cout << "Opción inválida. Intente nuevamente." << endl;
                }

                listaEstudiantes.mostrarEstudiantes();
                break;
            case 3:
                listaEstudiantes.encontrarMayorNota();
                listaEstudiantes.encontrarMenorNota();
                cout << "El promedio del curso es de " << listaEstudiantes.calcularPromedio() << endl;
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 4);

    return 0;
}