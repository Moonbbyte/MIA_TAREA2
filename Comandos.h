#ifndef COMANDOS_H
#define COMANDOS_H
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cstdio>

using namespace std; 


typedef struct{
    string Comando = " ";
    string Tamano = " ";
    string Dimensional = " ";
    string dir = " ";
}Parametros;

struct DiscoMBR{
int mbr_tamano;
time_t mbr_fecha_creacion;
int mbr_dsk_signature; 
}disco,disco2;



class Comandos
{
public:
    Parametros param;
    Comandos();
    void CreateDisk();
    void ShowDisco();
    void mostrar(DiscoMBR disco);
    void ejecutarInst(Parametros p);
private:

};

#endif