#include "funciones.h"

int tam_archivo(){
    unsigned long long tam;
    char* p;
    ifstream archivo;
    archivo.open("ensayo.txt",ios_base::in|ios_base::binary|ios_base::ate);
    if (archivo.is_open())
      tam=archivo.tellg();//posicion actual del apuntador

    archivo.close();
    return tam;
}

char* leer()
{
  unsigned long long tam;
  char* p;
  ifstream archivo;
  archivo.open("ensayo.txt",ios_base::in|ios_base::binary|ios_base::ate);
  if (archivo.is_open()){
    tam=archivo.tellg();//posicion actual del apuntador
    p = new char [tam];//por el caracter nulo
    archivo.seekg(0);//mover el apuntador al inicio
    archivo.read(p,tam);
    cout << p << endl;
    archivo.close();
  }
  else{cout<<"No se pudo abrir el archivo"<<endl;}

  return p;
}

char* informacion(char* cadena) {
    char* inicio = cadena; // puntero que apunta al inicio de la cadena
    char codigo[10]; // arreglo de chars para almacenar el código
    char nombre[20]; // arreglo de chars para almacenar el nombre
    char creditos[2]; // arreglo de chars para almacenar los créditos
    char horas[2]; // arreglo de chars para almacenar las horas

    char *P_codigo;

    while(*inicio != '\0') {
        // Extraemos el código
        int i = 0;
        while(*inicio != ' ') {
            codigo[i] = *inicio;
            i++;
            inicio++;
        }
        codigo[i] = '\0'; // verificamos que termine con el carácter nulo
        inicio++; // saltamos el espacio en blanco

        // sacar  el nombre
        i = 0;
        while(*inicio != ' ') {
            nombre[i] = *inicio;
            i++;
            inicio++;
        }
        nombre[i] = '\0';
        inicio++;

        // sacar los creditos
        i = 0;
        while(*inicio != ' ') {
            creditos[i] = *inicio;
            i++;
            inicio++;
        }
        creditos[i] = '\0';
        inicio++;

        // sacar las horas
        i = 0;
        while(*inicio != '\r') {
            horas[i] = *inicio;
            i++;
            inicio++;
        }
        horas[i] = '\0';
        inicio++;
    }

    // mostrar la informaci0n
    // 0948484 info 4 7

    cout << "Codigo: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Creditos: " << creditos << endl;
    cout << "Horas: " << horas << endl;

    char **puntero_matriz ;

    //reserva de memoria para columnas
    puntero_matriz = new char *[15]; // reserva memoria para filas
    for (int i = 0; i< 15; i++){
        puntero_matriz [i] = new char [7]; // reserva memoria para columnas
    }

    //llenado de matriz con 0
    for (int i= 0; i<15; i++){
         for (int j = 0; j< 7; j++){
              *(*(puntero_matriz+i)+j)=0;
          }
    }

    cout << endl<< "     L  | | M | | W | | J | | V | | S | | D |"<<endl ;
        for (int i= 0,k = 6; i<15; i++,k++){
            cout <<"["<<k<<"] ";
             for (int j = 0; j< 7; j++){
                 cout <<"| "<<*(*(puntero_matriz+i)+j)<<" | ";
             }
             cout << "\n ";
        }



}

