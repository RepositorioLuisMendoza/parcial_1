#include "funciones.h"

int main()
{
    char* contenido=leer();

    informacion(contenido);


    delete[]contenido;




    return 0;
}
