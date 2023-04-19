#include "funciones.h"

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
        while (*inicio != ' ') {
            codigo[i] = *inicio;
            i++;
            inicio++;
        }
        codigo[i] = '\0';

        inicio++;

        // Sacar el nombre
        i = 0;
        nombre = new char[40];
        while (*inicio != ' ') {
            nombre[i] = *inicio;
            i++;
            inicio++;
        }
        nombre[i] = '\0';
        inicio++;

        // Sacar los créditos
        i = 0;
        creditos = new char[2];
        while (*inicio != ' ') {
            creditos[i] = *inicio;
            i++;
            inicio++;
        }
        creditos[i] = '\0';
        inicio++;

        // Sacar las horas
        i = 0;
        horas = new char[2];
        while (*inicio != '\r') {
            horas[i] = *inicio;
            i++;
            inicio++;
        }
        horas[i] = '\0';
        inicio++;

        // Verificar si es igual al buscado
        if (es_igual(codigo, buscando)) {
            encontrado = true;
            // Almacenamos la información encontrada en el arreglo resultado
            for (int j = 0; codigo[j] != '\0'; j++) {
                resultado[posicionResultado] = codigo[j];
                posicionResultado++;
            }
            resultado[posicionResultado] = ' ';
            posicionResultado++;

            for (int j = 0; nombre[j] != '\0'; j++) {
                resultado[posicionResultado] = nombre[j];
                posicionResultado++;
            }
            resultado[posicionResultado] = ' ';
            posicionResultado++;

            for (int j = 0; creditos[j] != '\0'; j++) {
                resultado[posicionResultado] = creditos[j];
                posicionResultado++;
            }
            resultado[posicionResultado] = ' ';
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

    if (!encontrado) {
        cout << "El codigo no se encontro" << endl;
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




