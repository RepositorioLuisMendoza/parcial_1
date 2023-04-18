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
    p = new char [tam+1];//por el caracter nulo
    archivo.seekg(0);//mover el apuntador al inicio

    archivo.read(p,tam);
    p[tam='\0'];
    cout << p << endl;
    archivo.close();

  }
  else{cout<<"No se pudo abrir el archivo"<<endl;}

  return p;

}








char* matriz(char *)
{

}
