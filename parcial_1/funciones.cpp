
#include "funciones.h"
/*
char* leer()
{
  unsigned long long tam;
  char* p;
  ifstream archivo;
  archivo.open("ensayo.txt",ios_base::in|ios_base::binary|ios_base::ate);
  if (archivo.is_open())
  {
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
*/
void leer_buscar_materia(char codigo[], char materia[], char horas[], char creditos[], char resultado[]) {
    ifstream archivo("ensayo.txt",ios_base::in);
    char linea[100];
    bool encontrado = false;
    while (archivo.getline(linea, 100)) {
        char* codigo_p = codigo;
        char* codigo_materia_p = linea;
        while (*codigo_p != '\0' && *codigo_materia_p != ',') {
            if (*codigo_p != *codigo_materia_p) {
                break;
            }
            codigo_p++;
            codigo_materia_p++;
        }
        if (*codigo_p == '\0' && *codigo_materia_p == ',') {
            encontrado = true;
            // Extraer el nombre de la materia
            char* nombre_p = codigo_materia_p + 1;  // apuntar al siguiente caracter después de la coma
            int i = 0;
            while (*(nombre_p + i) != ',') {
                *(materia + i) = *(nombre_p + i);
                i++;
            }
            *(materia + i) = '\0';
            // Extraer las horas de la materia
            char* horas_p = nombre_p + i + 1;  // apuntar al siguiente caracter después de la coma
            i = 0;
            while (*(horas_p + i) != ',') {
                *(horas + i) = *(horas_p + i);
                i++;
            }
            *(horas + i) = '\0';
            // Extraer los créditos de la materia
            char* creditos_p = horas_p + i + 1;  // apuntar al siguiente caracter después de la coma
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




/*
char* informacion(char* cadena, char* buscando)
{
    char* inicio = cadena;
    char* codigo = nullptr;
    char* nombre = nullptr;
    char* creditos = nullptr;
    char* horas = nullptr;
    char* resultado = new char[100];
    int posicionResultado = 0;
    bool encontrado = false;

    while (*inicio != '\0') {
        // Sacamos el código
        int i = 0;
        codigo = new char[10];
        while (*inicio != ',') {
            codigo[i] = *inicio;
            i++;
            inicio++;
        }
        cout<<"..."<<codigo<<endl;
        inicio++;

        // Sacar el nombre
        i = 0;
        nombre = new char[40];
        while (*inicio != ',') {
            nombre[i] = *inicio;
            i++;
            inicio++;
        }
        inicio++;

        // Sacar los créditos
        i = 0;
        creditos = new char[2];
        while (*inicio != ' ') {
            creditos[i] = *inicio;
            i++;
            inicio++;
        }

        inicio++;

        // Sacar las horas
        i = 0;
        horas = new char[2];
        while (*inicio != '\r') {
            horas[i] = *inicio;
            i++;
            inicio++;
        }
        inicio++;

        // Verificar si es igual al buscado
        if (es_igual(codigo,buscando)) {

            // Almacenamos la información encontrada en el arreglo resultado
            for (int j = 0; codigo[j] != '\0'; j++) {
                resultado[posicionResultado] = codigo[j];
                posicionResultado++;
            }
            resultado[posicionResultado] = ',';
            posicionResultado++;

            for (int j = 0; nombre[j] != '\0'; j++) {
                resultado[posicionResultado] = nombre[j];
                posicionResultado++;
            }
            resultado[posicionResultado] = ',';
            posicionResultado++;

            for (int j = 0; creditos[j] != '\0'; j++) {
                resultado[posicionResultado] = creditos[j];
                posicionResultado++;
            }
            resultado[posicionResultado] = ',';
            posicionResultado++;

            for (int j = 0; horas[j] != '\0'; j++) {
                resultado[posicionResultado] = horas[j];
                posicionResultado++;
            }
            resultado[posicionResultado] = '\n';
            posicionResultado++;

            resultado[posicionResultado] = '\0';

            // Mostrar la información
            cout << "Codigo: " << codigo << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Creditos: " << creditos << endl;
            cout << "Horas: " << horas << endl;

            delete[] codigo;
            delete[] nombre;
            delete[] creditos;
            delete[] horas;
        }
    }



    return resultado;
}

bool es_igual(const char*c1, const char*c2){
    int i=0;
    while (c1[i]!='\0' and c2[i]!='\0')
    {
        if (c1[i]!=c2[i])
        {
            return false;
        }
        i++;
    }
    return true;
}

*/


