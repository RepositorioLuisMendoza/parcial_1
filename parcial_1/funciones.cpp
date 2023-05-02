
#include "funciones.h"

void leer_buscar_materia(char codigo[], char materia[], char horas[], char creditos[], char resultado[]) {
    ifstream archivo("ensayo.txt",ios_base::in);//abrir en archivo en modo lectura
    char linea[100]; //arreglo que va a contener cada linea de codigo
    bool encontrado = false;
    while (archivo.getline(linea, 100))//leer linea por linea el archvo y almacenarla en el arreglo linea
    {
        char* codigo_p = codigo;  //apuntar al primer caracter delcodigo
        char* codigo_materia_p = linea;  //apuntar al primero de la linea
        while (*codigo_p != '\0' && *codigo_materia_p != ',')  // Comparar cada carácter del código con cada carácter de la línea hasta encontrar la coma
        {
            if (*codigo_p != *codigo_materia_p)// Si son diferentes, salir del bucle
            {
                break;
            }
            codigo_p++;   //mover el puntero del codigo al siguiente caracter
            codigo_materia_p++;  //mover el puntero de la línea al siguiente carácter
        }
        if (*codigo_p == '\0' && *codigo_materia_p == ',')// Si se encontro el codigo, sacar la informacion
        {
            encontrado = true;
            // sacar el nombre de la materia
            char* nombre_p = codigo_materia_p + 1;  // apuntar al siguiente caracter despues de la coma
            int i = 0;
            while (*(nombre_p + i) != ',')//con este bucle vamos a copiar el nombre hasta que encuentre la coma
            {
                *(materia + i) = *(nombre_p + i);// Copiamos el caracter en el arreglo materia
                i++;//aumentamos i para pasar a la otra
            }
            *(materia + i) = '\0';//cuando terminamos agregamos el nulo


            //sacar las horas de la materia
            char* horas_p = nombre_p + i + 1;  // haremos el mismo proceso de arriba
            i = 0;//actuara como el que recorre
            while (*(horas_p + i) != ',') {
                *(horas + i) = *(horas_p + i);
                i++;
            }
            *(horas + i) = '\0';

            //sacar los creditos de la materia
            char* creditos_p = horas_p + i + 1;  // apuntar al siguiente caracter despues de la coma
            i = 0;
            while (*(creditos_p + i) != '\0') {
                *(creditos + i) = *(creditos_p + i);
                i++;
            }
            *(creditos + i) = '\0';
            // Copiar la línea encontrada en el resultado
            i = 0;
            while (*(linea + i) != '\0') {
                *(resultado + i) = *(linea + i);
                i++;
            }
            *(resultado + i) = '\0';
            break; // salir del bucle while
        }
    }
    if (!encontrado) {
        resultado[0] = '\0'; // si no se encontró la materia, el resultado es una cadena vacía
    }
    archivo.close();
}




int convertir_int(char codigo[])
{
    int codigo_num = 0;
        int i = 0;
        while (codigo[i] != '\0') {
            int valor_ascii = (int)codigo[i];
            if (valor_ascii >= 48 && valor_ascii <= 57) {
                codigo_num = codigo_num * 10 + (valor_ascii - 48);
            }
            i++;
        }
        return codigo_num;
}





void matriz(){
    const int FILAS = 24;
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
            matriz[k-1][dia][0] = '1'; // actualiza la matriz con la nueva clase
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
