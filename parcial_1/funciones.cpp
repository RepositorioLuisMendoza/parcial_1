#include "funciones.h"

/*
void guardar_datos(char** nombres, int* creditos, int* horas, int n) {

    // Pedimos memoria dinámica para los punteros de nombres
    for (int i = 0; i < n; i++) {
        nombres[i] = new char[50];
    }

    // Pedimos los datos al usuario y los guardamos en memoria dinámica
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el nombre de la materia #" << i+1 << ": ";
        cin >> nombres[i];
        cout << "Ingrese el numero de creditos de la materia #" << i+1 << ": ";
        cin >> creditos[i];
        cout << "Ingrese el numero de horas recibidas por un docente de la materia #" << i+1 << ": ";
        cin >> horas[i];
    }

    // Imprimimos los datos guardados en memoria dinámica
    for (int i = 0; i < n; i++) {
        cout << "Materia #" << i+1 << ": " << nombres[i] << ", Creditos: " << creditos[i] << ", Horas recibidas por docente: " << horas[i] << endl;
    }
    // Liberamos la memoria dinámica utilizada
    for (int i = 0; i < n; i++) {
        delete[] nombres[i];
    }
    delete[] nombres;
    delete[] creditos;
    delete[] horas;

}
*/




// Función que recibe la cantidad de materias a ingresar y retorna un puntero de char
char* ingresar_materias() {
    int cantidad_materias;
    cout << "Ingrese la cantidad de materias: ";
    cin >> cantidad_materias;

    // Constante que indica la cantidad máxima de caracteres para cada materia
    const int tam_max = 50;

    // Arreglo de tres dimensiones para almacenar la información de cada materia
    char materias[cantidad_materias][4][tam_max];

    // Ciclo para solicitar la información de cada materia
    for (int i = 0; i < cantidad_materias; i++) {
        // Solicita el nombre de la materia
        cout << "Ingrese el nombre de la materia " << i + 1 << ": ";
        cin >> materias[i][0];

        // Solicita el código de la materia
        cout << "Ingrese el codigo de la materia " << i + 1 << ": ";
        cin >> materias[i][1];

        // Solicita el número de créditos de la materia
        cout << "Ingrese el numero de creditos de la materia " << i + 1 << ": ";
        cin >> materias[i][2];

        // Solicita el número de horas de la materia
        cout << "Ingrese el numero de horas de la materia " << i + 1 << ": ";
        cin >> materias[i][3];
    }

    // Arreglo para guardar la información de todas las materias
    char* result = new char[cantidad_materias * 4 * tam_max];

    // Puntero auxiliar para recorrer el arreglo de arriba
    char* p = result;

    // Ciclo para recorrer el arreglo y almacenar informacio
    for (int i = 0; i < cantidad_materias; i++) {
        for (int j = 0; j < 4; j++) { // el 4 son los 4 campos de información de la materia
            for (int k = 0; k < tam_max and materias[i][j][k] != '\0'; k++) { // Ciclo para recorrer los caracteres de cada campo de la materia
                *p++ = materias[i][j][k]; // Almacena el caracter en el arreglo de una dimensión y avanza el puntero
            }
            *p++ = ' '; // Agrega un espacio en blanco después de cada campo de la materia
        }
        *p++ = '\n'; // Agrega un salto de línea después de cada materia
    }

    *p = '\0'; // Agrega el caracter nulo al final del arreglo de una dimensión

    // Retorna el puntero al arreglo de una dimensión
    return result;
}
