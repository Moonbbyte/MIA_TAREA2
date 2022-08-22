#include "Analizador.h"

Analizador::Analizador()
{
    //Este es el constructor 
}

vector<string> Analizador::split_txt(string text){ // Split para separar tipo de comando y parametros
    stringstream ss(text);  //split este texto
    string segment; //variable donde se guardara cada parte
    vector<string> splited;

    while(std::getline(ss, segment, ' ')){
       splited.push_back(segment);
    }
    return splited;
}

string Analizador::replace_txt(string str, const string& from, const string& to) {
    //size_t es un tipo de valor de datos 
    //string::npos  indica el final de la cadena 
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

void Analizador::analisis(string entrada){
    /*
        PASOS PARA REALIZAR LOS COMANDOS:
        1: estarandizar minusculas o mayusculas para todos los elementos
        2: separarlos por los espacios y guardar cada parametro en una celda de un array
        3: identificar cual es el comando (el cual es el primer elemento del array)
        4: distinguir el comando de los demas parametros
        5: proceder dependiendo del comando a pedir unos u otros parametros
        6: distinguir parametros con los comandos que luego procederan a ser eliminados con un replace (elemento,"") 
           dejando solo el valor de estos
        7: mandar a otro metodo a realizar una ejecucion dependiendo del comando y los parametros usados.
    */

    string entradaCmd=entrada;
    //pasar la cadena string a minusculas
    transform(entradaCmd.begin(), entradaCmd.end(), entradaCmd.begin(), ::tolower);
    vector<string> cmdEntrada = split_txt(entradaCmd); //el array del split de la entrada cmd
    vector<string> parametros; //los parametros a realizar
    string comando = ""; //Comando que se va a ejecutar
    for(int i = 0; i< cmdEntrada.size(); i++){
        if(i == 0){
            comando = cmdEntrada.at(i);  //comando=cmdEntrada[0]
        }else{
            parametros.push_back(cmdEntrada.at(i)); //push cmd Entrada
        }
    }
    // Identificacion de comando, parametros y ejecucion
    identificarParametros(comando, parametros);
}

void Analizador::identificarParametros(string comando, vector<string> parametros){
    string param = "";
    if(comando == "mkdisk"){
        cmd.param.Comando = "mkdisk";
        // Ejecucion de metodo
        cmd.ejecutarInst(cmd.param);  //SE MANDA A EJECUTAR EL METODO

    } else if(comando == "rep"){
        cmd.param.Comando = "rep";
        cmd.ejecutarInst(cmd.param);
    } else if(comando == "exec"){
        cmd.param.Comando = "exec";
        for(int i=0; i<parametros.size(); i++){
            param = parametros.at(i);
            if(param.find("-path=") == 0){  //find devuelve un 0 si se encontro, si no devolvera el tamaño del string completo
                param = replace_txt(param, "-path=", "");
                param = replace_txt(param, "\"", "");
                cmd.param.dir = param;
            }
        }
        LeerScript(cmd.param.dir);   
    }else if(comando == "exit"){
        cout<<"Exit"<<endl;
    }else{
        cout<<"Comando no reconocido"<<endl;
    }
}

void Analizador::LeerScript(string path){
    string line;
    ifstream archivo;
    cout<<"dir: "<<path<<endl;
    archivo.open(path,ios::in);
    if(archivo.fail()){
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    while (!archivo.eof())
    {
        getline(archivo,line);
        if(line!=""){
            if(line.at(0)=='#'){
                cout<<"Comentario: "<<line<<endl;
            }else{
                cout<<"instruction: "<<line<<endl;
                analisis(line);
            }
            
        }
    }
}