#include "funciones.h"


void matriz ();
void strcpy(char* destino, const char* fuente);

int main()
{

//    char* cadena=leer();
//    char usuario []= " 0948484 info 4 7";
    matriz();




//    delete[]cadena;


    return 0;
}

void matriz(){
    const int FILAS = 25;
    const int COLUMNAS = 7;
    char*** matriz;
    int dia, hora_inicio, duracion;


    matriz = new char**[FILAS];
    for (int i = 0; i < FILAS; i++) {
        matriz[i] = new char*[COLUMNAS];
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = new char[2]; // cada elemento de la matriz es un char[2]
            matriz[i][j][0] = '0'; // inicializa todos los elementos de la matriz a '0'
            matriz[i][j][1] = '\0'; // agrega el caracter nulo al final
        }
    }

    cout << "Ingrese el horario de clases en formato 24 horas: " << endl;
    cout << "0 = Lunes, 1 = Martes, 2 = Miercoles, 3 = Jueves,\n4 = Viernes, 5 = Sabado, 6 = Domingo" << endl;


    while (true) {
        cout << "Ingrese el dia de la semana (0-6): ";
        cin >> dia;
        if ((dia < 0 )|| (dia > 6)) {
            cout << "Dia de la semana invalido. Intente de nuevo." << endl;
            continue;
        }
        cout << "Ingrese la hora de inicio (0-23): ";
        cin >> hora_inicio;
        if ((hora_inicio < 0) || (hora_inicio > 23)) {
            cout << "Hora de inicio invalida. Intente de nuevo." << endl;
            continue;
        }
        cout << "Ingrese la duracion en horas (1-15): ";
        cin >> duracion;
        if ((duracion < 1 )||( duracion > 15)) {
            cout << "Duracion invalida. Intente de nuevo." << endl;
            continue;
        }

        bool conflicto = false;
        for (int k = hora_inicio; k < hora_inicio + duracion; k++) {
            if (matriz[dia][k][0] != '0') {
                conflicto = true;
                break;
            }
        }
        if (conflicto) {
            cout << "El horario ingresado coincide con otra clase. Intente de nuevo." << endl;
            continue;
        }
        for (int k = hora_inicio; k < hora_inicio + duracion; k++) {
            matriz[k][dia][0] = '1'; // actualiza la matriz con la nueva clase
        }
        cout << "Clase agregada al horario." << endl;
        cout << "Desea agregar otra clase? (s/n): ";
        char respuesta;
        cin >> respuesta;
        if (respuesta != 's') {
            break;
        }
    }


    // Impresión de los datos ingresados
    cout << "Los valores ingresados son:" << endl;
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
             cout << "| " << matriz[i][j] << " ";
        }
       cout << endl;
    }

    // Liberación de la memoria
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            delete[] matriz[i][j];
        }
        delete[] matriz[i];
    }
    delete[] matriz;
}

