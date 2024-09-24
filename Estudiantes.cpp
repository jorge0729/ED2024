#include <iostream>
#include<malloc.h>


using namespace std;

struct Estudiante
{
    char nombre[10];
    int codigo;
    float nota;
    Estudiante *siguiente;
};

Estudiante *cabeza, *auxiliar, *auxiliar2;

void registrar()
{
    auxiliar = (struct Estudiante *) malloc (sizeof(Estudiante));
    cout<<"ingrese el nombre del estudiante: ";
    cin>>auxiliar->nombre;
    cout<<"ingrese el codigo del estudiante: ";
    cin>>auxiliar->codigo;
    cout<<"ingrese la nota del estudiante: ";
    cin>>auxiliar->nota;
    auxiliar->siguiente = NULL;

    if (!cabeza)
    {
        cabeza = auxiliar;
    }else{

        auxiliar2 = cabeza;
        while (auxiliar2->siguiente != NULL)
        {
            auxiliar2 = auxiliar2->siguiente;
        }
        auxiliar2->siguiente = auxiliar;     
        
    }
    auxiliar = auxiliar2 = NULL; free(auxiliar);free(auxiliar2);   
       
}

void mostrar()
{
    auxiliar = cabeza;
    int item = 0;
    if(cabeza != NULL)
    {
        cout<<"item"<<'\t'<<"codigo"<<'\t'<<"nombre"<<'\t'<<"nota"<<endl;
        while (auxiliar != NULL)
        {
            item++;
            cout<<item<<'\t';
            cout<<auxiliar->codigo<<'\t';
            cout<<auxiliar->nombre<<'\t';
            cout<<auxiliar->nota<<endl;
            auxiliar = auxiliar->siguiente;
        }

        auxiliar = NULL; free(auxiliar);
}else{cout<<"la lista está vacia"<<'\n';}

}

void promedio()
{
    auxiliar = cabeza;

    int cantidad = 0;
    float suma = 0;
    float out = 0;

    while(auxiliar != NULL)
    {
        suma += auxiliar->nota;
        cantidad +=1;
        auxiliar = auxiliar->siguiente;
    }

    out = suma / cantidad;
    cout<<"la cantidad es: "<<cantidad<<" ,la sumatoria es: "<<suma<<" , el promedio es: "<<out<<endl;

    auxiliar = NULL; free(auxiliar);
    
}

void ordenarCodigo()
{
    int tmpCodigo = 0;
    float tmpNota = 0;
    char tmpNombre[10];
    auxiliar2 = cabeza;
    if(cabeza != NULL)
    while(auxiliar2->siguiente != NULL)
    {
        auxiliar = cabeza;
        while (auxiliar->siguiente != NULL)
        {
            if(auxiliar->codigo > auxiliar->siguiente->codigo)
            {
                tmpCodigo = auxiliar->codigo;
                tmpNota = auxiliar->nota;
                for(int x = 0;x<10;x++)
                tmpNombre[x] = auxiliar->nombre[x];
                
                auxiliar->codigo = auxiliar->siguiente->codigo;
                auxiliar->nota = auxiliar->siguiente->nota;                
                for(int x = 0;x<10;x++)
                auxiliar->nombre[x] = auxiliar->siguiente->nombre[x];

                auxiliar->siguiente->codigo = tmpCodigo;
                auxiliar->siguiente->nota = tmpNota;
                for(int x = 0;x<10;x++)
                auxiliar->siguiente->nombre[x] = tmpNombre[x];
            }
            auxiliar = auxiliar->siguiente;
        }
        auxiliar2 = auxiliar2->siguiente;        
    }

    auxiliar = auxiliar2 = NULL;free(auxiliar);free(auxiliar2);

}

void ordenarNota()
{
    int tmpCodigo, tmpNota = 0;
    char tmpNombre[10];
    auxiliar2 = cabeza;
    if(cabeza != NULL)
    {
        while(auxiliar2->siguiente != NULL)
        {
            auxiliar = cabeza;
            while (auxiliar->siguiente != NULL)
            {
                if(auxiliar->nota < auxiliar->siguiente->nota)
                {
                    tmpCodigo = auxiliar->codigo;
                    tmpNota = auxiliar->nota;
                    for(int x = 0;x<10;x++)
                    tmpNombre[x] = auxiliar->nombre[x];
                    
                    auxiliar->codigo = auxiliar->siguiente->codigo;
                    auxiliar->nota = auxiliar->siguiente->nota;                
                    for(int x = 0;x<10;x++)
                    auxiliar->nombre[x] = auxiliar->siguiente->nombre[x];

                    auxiliar->siguiente->codigo = tmpCodigo;
                    auxiliar->siguiente->nota = tmpNota;
                    for(int x = 0;x<10;x++)
                    auxiliar->siguiente->nombre[x] = tmpNombre[x];
                }
                auxiliar = auxiliar->siguiente;
            }
            auxiliar2 = auxiliar2->siguiente;     
        }
            //promedio();
            cout<<" el estudiante con la nota mas alta es "<<cabeza->nombre<<" con "<<cabeza->nota<<endl;
            cout<<" el estudiante con la nota mas baja es "<<auxiliar2->nombre<<" con "<<auxiliar2->nota<<endl;

        auxiliar = auxiliar2 = NULL;free(auxiliar);free(auxiliar2);
    }else{cout<<"la lista está vacia"<<endl;}

}

int main()
{
    int opcion;
    do
    {
        cout<<'\t'<<"*****MENU*****"<<'\n';
        cout<<"1. ingresar datos del estudiante"<<'\n';
        cout<<"2. mostrar lista de los estudiantes"<<'\n';
        cout<<"3. Mostrar la mayor nota, menor nota y promedio del curso"<<'\n';
        cout<<"0. salir"<<'\n';
        cin>>opcion;

        switch (opcion)
        {
            case 0: {cout<<"**gracias**"<<endl;}
                break;

            case 1:{registrar();}
                break;
            
            case 2:{ordenarCodigo();mostrar();}
                break;
            
            case 3:{ordenarNota();promedio();}
                break;
                
            default:{cout<<"la opcion no existe"<<endl;}
                break;
        }

    } while (opcion != 0);

    return 0;
}