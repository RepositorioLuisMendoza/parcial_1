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








char* informacion(char* cadena,char* buscando)
{
    char* inicio = cadena; // puntero que apunta al inicio de la cadena
    char *codigo=nullptr; // cambiamos los arreglos a punteros y los ponm0s nulos al principio
    char *nombre=nullptr; // cambiamos los arreglos a punteros
    char *creditos=nullptr; // cambiamos los arreglos a punteros
    char *horas=nullptr; // cambiamos los arreglos a punteros
    char* resultado = new char[100]; // arreglo donde almacenaremos la información encontrada
    int posicionResultado = 0; // variable que nos indica la posición actual en el arreglo resultado

    while(*inicio != '\0') {
        // sacamos el código
        int i = 0;
        codigo=new char[10];//le ponemos dinamica en esa vaina aver que sale
        while(*inicio != ' ') {
            codigo[i] = *inicio;
            i++;
            inicio++;
        }

        codigo[i] = '\0'; // verificamos que termine con el carácter nulo

        inicio++; // saltamos el espacio en blanco

        // sacar  el nombre
        i = 0;
        nombre=new char[40];//cuarenta por que las materias tienen nombres largos
        while(*inicio != ' ') {
            nombre[i] = *inicio;
            i++;
            inicio++;
        }
        nombre[i] = '\0';
        inicio++;

        // sacar los creditos
        i = 0;
        creditos=new char[2];//los creditos son pequeños
        while(*inicio != ' ') {
            creditos[i] = *inicio;
            i++;
            inicio++;
        }
        creditos[i] = '\0';
        inicio++;

        // sacar las horas
        i = 0;
        horas=new char[2];
        while(*inicio != '\r') {
            horas[i] = *inicio;
            i++;
            inicio++;
        }
        horas[i] = '\0';
        inicio++;

        //vamos a ver si es igual al buscado
        if (es_igual(codigo, buscando))
        {
            cout<<"si esta"<<endl;
            // almacenamos la información encontrada en el arreglo resultado
            for(int j = 0; codigo[j] != '\0'; j++)
            {
                resultado[posicionResultado] = codigo[j];
                posicionResultado++;
            }
                resultado[posicionResultado] = ' ';
                posicionResultado++;

            for(int j = 0; nombre[j] != '\0'; j++)
            {
                resultado[posicionResultado] = nombre[j];
                posicionResultado++;
            }
                resultado[posicionResultado] = ' ';
                posicionResultado++;

            for(int j = 0; creditos[j] != '\0'; j++)
            {
                resultado[posicionResultado] = creditos[j];
                posicionResultado++;
            }
                resultado[posicionResultado] = ' ';
                posicionResultado++;

            for(int j = 0; horas[j] != '\0'; j++)
            {
                resultado[posicionResultado] = horas[j];
                posicionResultado++;
            }
                resultado[posicionResultado] = '\n';
                posicionResultado++;


            resultado[posicionResultado] = '\0';
            // agregamos el caracter nulo al final del arreglo resultado

            delete[] codigo;
            delete[] nombre;
            delete[] creditos;
            delete[] horas;

            // mostrar la informaci0n
            cout << "Codigo: " << codigo << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Creditos: " << creditos << endl;
            cout << "Horas: " << horas << endl;
            return resultado;


        }




    }
    delete[] codigo;
    delete[] nombre;
    delete[] creditos;
    delete[] horas;
    return nullptr;
 // si no encontramos el código, retornar nullptr
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


