#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <string.h>
#include "Analizador.cpp"
using namespace std;

int main(int argc, char const *argv[])

{   
    Analizador analizador;
    string entradaCmd="";

    while (entradaCmd!="exit")
    {
        cout << "-----------------------------------------" <<endl;
        cout << "================TAREA 2==================" <<endl;
        cout << "-----------------------------------------" <<endl;
        cout << "[brandon@moon]: " ;
        getline(cin,entradaCmd);
        analizador.analisis(entradaCmd);
    }   
    
   
    return 0;
}
