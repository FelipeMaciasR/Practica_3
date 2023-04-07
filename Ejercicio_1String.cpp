/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int* Binario(char x);

int main() {
    ifstream fin;
    string contenidoOriginal, contenidoBinario, contenidoConvertido1, contenidoConvertido2;
    ofstream fout;

    try{
        fin.open("OriginalStr.txt");
        if(!fin.is_open()){
            throw '1';
        }

        fout.open("BinarioStr.txt");
        if(!fout.is_open()){
            throw '2';
        }

        while(fin.good()){
            char temp=fin.get();
            if(fin.good()){
                contenidoOriginal +=temp;
            }
        }

        for(int i=0; i<contenidoOriginal.length(); i++){
            for(int j=0;j<8;j++){
                fout << *(Binario(contenidoOriginal[i])+j);
            }
        }
        fin.close();
        fout.close();

        //METODO #1

        fin.open("BinarioStr.txt");
        if(!fin.is_open()){
            throw '2';
        }
        fout.open("CodificadoMetodo1Str.txt");
        if(!fout.is_open()){
            throw '3';
        }
        while(fin.good()){
            char temp=fin.get();
            if(fin.good()){
                contenidoBinario +=temp;
            }
        }
        int n=4, uno=0, cero=0;
        for(int i=0; i<n; i++){
            if(contenidoBinario[i]=='1'){
                contenidoConvertido1+='0';
                uno++;
            }
            else{
                contenidoConvertido1+='1';
                cero++;
            }
        }

        for(int i=n; i<contenidoBinario.length(); i+=n){
            if(uno==cero){
                cero=0;
                uno=0;
                for(int j=0; j<n; j++){
                    if(contenidoBinario[i+j]=='1'){
                        contenidoConvertido1+='0';
                        uno++;
                    }
                    else{
                        contenidoConvertido1+='1';
                        cero++;
                    }
                }
            }
            else if(cero>uno){
                cero=0;
                uno=0;
                for(int j=0; j<n; j++){
                    if((j+1)%2==0){
                        if(contenidoBinario[i+j]=='1'){
                            contenidoConvertido1+='0';
                            uno++;
                        }
                        else{
                            contenidoConvertido1+='1';
                            cero++;
                        }
                    }
                    else{
                        contenidoConvertido1+=contenidoBinario[i+j];
                        if(contenidoBinario[i+j]=='1')
                            uno++;
                        else
                            cero++;
                    }
                }
            }
            else{
                cero=0;
                uno=0;
                for(int j=0; j<n; j++){
                    if((j+1)%3==0){
                        if(contenidoBinario[i+j]=='1'){
                            contenidoConvertido1+='0';
                            uno++;
                        }
                        else{
                            contenidoConvertido1+='1';
                            cero++;
                        }
                    }
                    else{
                        contenidoConvertido1+=contenidoBinario[i+j];
                        if(contenidoBinario[i+j]=='1')
                            uno++;
                        else
                            cero++;
                    }
                }
            }
        }
        fout<<contenidoConvertido1;
        fin.close();
        fout.close();

        //METODO #2
        fin.open("BinarioStr.txt");
        if(!fin.is_open()){
            throw '2';
        }
        fout.open("CodificadoMetodo2Str.txt");
        if(!fout.is_open()){
            throw '3';
        }
        char bloque[n];
        int i=0, k=0;

        for(int i=0; i<contenidoBinario.length(); i++){
            if((i+1)%n==0){
                contenidoConvertido2+=contenidoBinario[i];
                for(int j=0; j<n-1; j++){
                    contenidoConvertido2+=contenidoBinario[j+k];
                }
                k+=n;
            }
        }
        fout<<contenidoConvertido2<<endl;
        fin.close();
        fout.close();

    }

    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='1'){
            cout<<"Error al abrir el archivo para lectura.\n";
        }
        else if(c=='2'){
            cout<<"Error al abrir el archivo para conversion.\n";
        }
        else if(c=='3'){
            cout<<"Error al abrir el archivo para codificacion.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }

    return 0;
}

int* Binario(char x){
    int convert[8], res, i=7;
    while(i!=-1){
        res=x%2;
        convert[i]=res;
        i--;
        x=x/2;
    }
    int* ptr=&convert[0];
    return ptr;

}
*/

