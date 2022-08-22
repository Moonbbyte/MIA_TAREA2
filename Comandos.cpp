#include "Comandos.h"


Comandos::Comandos()
{
    //Constructor
}

void Comandos::ejecutarInst(Parametros p){
    if(p.Comando=="mkdisk"){ // Se identifica el comando
        CreateDisk();
    }else if(p.Comando=="rep"){
        ShowDisco();
    }else {
        cout<<"Error comando no conocido"<<endl;
        exit(1);
    }
}


void Comandos:: CreateDisk(){
    int size_file=5*1024;
    char bloque[1024];
    for (int i = 0; i < 1024; i++)
    {
        bloque[i]='\0';
    }
    FILE *archivo_bin;
    archivo_bin=fopen("Disco.dk","w");
    fclose(archivo_bin);
    archivo_bin=fopen("Disco.dk","rb+"); //seek_seet no funciona con ab+  solo con rb+ a la hora de escribir
                                        //ab+ siempre escribe al final, pero a la hora de leer si funciona seek set  al parecer
    int limite=0;
    while (limite!=size_file)
    {
        fwrite(&bloque,1024,1,archivo_bin);
        limite++;
    }
      
    disco.mbr_tamano=5*1024*1024;
    disco.mbr_fecha_creacion=time(0);
    disco.mbr_dsk_signature=(rand()%10)+1;

    fseek(archivo_bin,0, SEEK_SET);
    fwrite(&disco, sizeof(disco), 1, archivo_bin);
    fclose(archivo_bin);
}

void Comandos::ShowDisco(){
    FILE *archivo_bin;
    archivo_bin=fopen("Disco.dk","ab+");
    fseek(archivo_bin,0, SEEK_SET);
    fread(&disco2, sizeof(disco2), 1, archivo_bin);
    mostrar(disco2);
    fclose(archivo_bin);
}

void Comandos::mostrar(DiscoMBR disco1){
    if(disco1.mbr_dsk_signature!=0 && disco1.mbr_tamano!=0){
        cout << "Tamanio: "<< disco1.mbr_tamano<<" bytes"<<endl;
        char* dt = ctime(&disco1.mbr_fecha_creacion);
        cout << "Fecha de creacion: " << dt;
        cout << "Asignatura: " << disco1.mbr_dsk_signature<<endl;
    }else{
        cout << "No se ha creado ningun disco"<<endl;
    }
    
}

