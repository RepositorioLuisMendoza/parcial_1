#include "funciones.h"
/*
int main() {
    int n;
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


    // Llama a la función ingresar_materias para obtener la información de las materias ingresadas
    char* info_materias = ingresar_materias();
    //cout << "Informacion de las materias ingresadas:"<<endl;
    //cout << info_materias;


    trabajo_personal(info_materias);

    delete[] info_materias;







    return 0;
}

*/


/*
int main()
{
    int ***conj_matrices;
    unsigned short dim;
    cout<<"Ingrese la dimension de la matriz: ";
    cin >> dim;

    conj_matrices = generar_conj_matrices(dim);
    imprimir_conj_matrices(conj_matrices,dim);

    pedir_datos();
    mostrar_matriz(puntero_matriz, nfilas, ncolumnas);


    return 0;
}
    */


int main() {
    int FILAS;
    cout<<"ingrese el numero de materias que cursa"<<endl;
    cin>>FILAS;
    const int COLUMNAS = 4;

    char** nombres = new char*[FILAS];
    char** codigos = new char*[FILAS];
    int* creditos = new int[FILAS];
    int* horas = new int[FILAS];

    // Crear la matriz
    crearMatriz(nombres, codigos, creditos, horas, FILAS);

    // Mostrar la matriz
    for (int i = 0; i < FILAS; i++) {
        cout << nombres[i] << "\t" << codigos[i] << "\t" << creditos[i] << "\t" << horas[i] << endl;
    }

    // Acceder al número de créditos y horas de la materia 3
    int numCreditos = creditos[2];
    int numHoras = horas[2];

    cout << "La materia 3 tiene " << numCreditos << " créditos y " << numHoras << " horas." << endl;

    // Liberar la memoria utilizada por los nombres y códigos
    for (int i = 0; i < FILAS; i++) {
        delete[] nombres[i];
        delete[] codigos[i];
    }
    delete[] nombres;
    delete[] codigos;
    delete[] creditos;
    delete[] horas;

    return 0;
}
