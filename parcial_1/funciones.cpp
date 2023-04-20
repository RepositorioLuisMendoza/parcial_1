
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






