#include "funciones.h"

int main()
{

    char codigo[8];
    cout << "Ingrese el codigo de la materia a buscar: ";
    cin >> codigo;
    char materia[50];
    char horas[2];
    char creditos[2];
    char resultado[100];
    leer_buscar_materia(codigo, materia, horas, creditos, resultado);
    if (resultado[0] != '\0') {
        cout << "Se encontro la materia:" <<endl;
        cout << "Materia: " << materia << endl;
        cout << "Horas: " << horas << endl;
        cout << "Creditos: " << creditos << endl;
        cout << "Linea encontrada: " << resultado << endl;
    }
    else{cout<<"la materia no existe"<<endl;}



return 0;
}
