#include "funciones.h"

int main() {
  /*  int n;
    cout << "Ingrese el numero de materias: ";
    cin >> n;

    char** nombres = new char*[n];
    int* creditos = new int[n];
    int* horas = new int[n];

    guardar_datos(nombres, creditos, horas, n);

    // Liberamos la memoria dinámica utilizada
    for (int i = 0; i < n; i++) {
        delete[] nombres[i];
    }
    delete[] nombres;
    delete[] creditos;
    delete[] horas;
    */

    // Llama a la función ingresar_materias para obtener la información de las materias ingresadas
    char* info_materias = ingresar_materias();
    cout << "Informacion de las materias ingresadas:"<<endl;
    cout << info_materias;
    delete[] info_materias;
    return 0;
}

