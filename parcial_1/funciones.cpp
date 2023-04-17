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



/*
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
                cout<<"creditos"<<*materias[j];
            }
            *p++ = ' '; // Agrega un espacio en blanco después de cada campo de la materia
        }
        *p++ = '\n'; // Agrega un salto de línea después de cada materia

    }
    *p = '\0'; // Agrega el caracter nulo al final del arreglo de una dimensión

    // Retorna el puntero al arreglo de una dimensión
    return result;
}


char* trabajo_personal(char *p){

    cout << " \n  \n Informacion de las materias ingresadas: \n \n"<<endl;
    cout<<"perrrrrororororororororororororor \n"<<endl;
    cout<<p<<endl;
    int longitud = sizeof(p);




}

*/



/*void pedir_datos(){

    cout << "Dijite el numero de filas:"<<endl;
    //cin >> nfias;
    nfilas = 15;
    cout << "Dijite el numero de filas:"<<endl;
    //cin >> ncolumnas;
    ncolumnas = 7;

   //reserva de memoria para columnas
   puntero_matriz = new int *[nfilas]; // reserva memoria para filas
   for (int i = 0; i< nfilas; i++){
       puntero_matriz [i] = new int [ncolumnas]; // reserva memoria para columnas
   }

   // llenado de matris con numero 0
   for (int i= 0; i<nfilas; i++){
        for (int j = 0; j< ncolumnas; j++){
            //cout << "Dijite un numero ["<<i<<"] ["<<j <<"]: ";
            //cin >> ((puntero_matriz+i)+j);

             ((puntero_matriz+i)+j)=0;
         }
   }

}

void mostrar_matriz (int **puntero_matriz, int nfilas, int ncolumnas ){
cout << endl<< "     L  | | M | | W | | J | | V | | S | | D |"<<endl ;
    for (int i= 0,k = 6; i<nfilas; i++,k++){
        cout <<"["<<k<<"] ";
         for (int j = 0; j< ncolumnas; j++){
             cout <<"| "<<((puntero_matriz+i)+j)<<" | ";
         }
         cout << "\n ";
    }
}

void Ingresar_horario(int **){
    int numero_materias, codigo_materia,n_dias_materia,n_horas_semana;
    char dia ;
    cout << "Ingrese el numero de materias: "<<endl;
    cin >> numero_materias;

    cout << "Ingreso de horario: "<<endl;
    for (int i = 0; i<numero_materias; i++){
        cout << "Ingrese codigo de la materia ["<< i <<" ]."<<endl;
        cin >> codigo_materia;
        cout << "Ingrese el numero de dias que ve la materia a la semana ["<< i <<" ]."<<endl;
        cin >> n_dias_materia;
        cout << "Ingrese el numero de horas que ve la materia a la semana ["<< i <<" ]."<<endl;
        cin >> n_horas_semana;

        cout <<"L = Lunes.\n M = Martes.\n W = Miercoles.\n J  = Jueves.\n V = Viernes.\n S = Sabado.\n D = Domingo \n "<<endl;


    }
}
*/



void crearMatriz(char**& nombres, char**& codigos, int*& creditos, int*& horas, int FILAS) {
    // Pedir al usuario que ingrese los datos de la matriz
    for (int i = 0; i < FILAS; i++) {
        // Pedir el nombre
        cout << "Ingrese el nombre de la materia " << i+1 << ": ";
        char* nombre = new char[50];
        cin >> nombre;
        nombres[i] = nombre;

        // Pedir el código
        cout << "Ingrese el codigo de la materia " << i+1 << ": ";
        char* codigo = new char[10];
        cin >> codigo;
        codigos[i] = codigo;

        // Pedir los créditos
        cout << "Ingrese el numero de crediyos de la materia " << i+1 << ": ";
        int credito;
        cin >> credito;
        creditos[i] = credito;

        // Pedir las horas
        cout << "Ingrese el numero de horas de la materia " << i+1 << ": ";
        int hora;
        cin >> hora;
        horas[i] = hora;
    }
}

