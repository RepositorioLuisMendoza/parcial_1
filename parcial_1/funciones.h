#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

#ifndef FUNCIONES_H
#define FUNCIONES_H

#endif // FUNCIONES_H

char* leer();
char* informacion(char*p,char* buscando);
bool es_igual(const char*c1, const char*c2);
unsigned char**LoadCurso(char* code);
void leer_buscar_materia(char codigo[], char materia[], char horas[], char creditos[], char resultado[]);
