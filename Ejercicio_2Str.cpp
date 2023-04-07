/*
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char byteToDecimal(string byteString) ;

int main()
{
    ifstream fin;
    ofstream fout;
    string contenidoCodificado, contenidoCodificado2, contenidoDecodificado, contenidoDecodificado2;
    try{


        fin.open("CodificadoStr.txt");
        if(!fin.is_open()){
            throw '1';
        }

        fout.open("DecodificadoStr.txt");
        if(!fout.is_open()){
            throw '2';
        }

        while(fin.good()){
            char temp=fin.get();
            if(fin.good()){
                contenidoCodificado +=temp;
            }
        }
        //METODO #1

        int n=4, uno=0, cero=0;

        for(int i=0; i<n; i++){
            if(contenidoCodificado[i]=='1'){
                contenidoDecodificado+='0';
                cero++;
            }
            else{
                contenidoDecodificado+='1';
                uno++;
            }
        }


        for(int i=n; i<contenidoCodificado.length(); i+=n){
            if(uno==cero){
                cero=0;
                uno=0;
                for(int j=0; j<n; j++){
                    if(contenidoCodificado[i+j]=='1'){
                        contenidoDecodificado+='0';
                        cero++;
                    }
                    else{
                        contenidoDecodificado+='1';
                        uno++;
                    }
                }
            }
            else if(cero>uno){
                cero=0;
                uno=0;
                for(int j=0; j<n; j++){
                    if((j+1)%2==0){
                        if(contenidoCodificado[i+j]=='1'){
                            contenidoDecodificado+='0';
                            cero++;
                        }
                        else{
                            contenidoDecodificado+='1';
                            uno++;
                        }
                    }
                    else{
                        contenidoDecodificado+=contenidoCodificado[i+j];
                        if(contenidoCodificado[i+j]=='1')
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
                        if(contenidoCodificado[i+j]=='1'){
                            contenidoDecodificado+='0';
                            cero++;
                        }
                        else{
                            contenidoDecodificado+='1';
                            uno++;
                        }
                    }
                    else{
                        contenidoDecodificado+=contenidoCodificado[i+j];
                        if(contenidoCodificado[i+j]=='1')
                            uno++;
                        else
                            cero++;
                    }
                }
            }
        }
        fout<<contenidoDecodificado;
        fin.close();
        fout.close();

        fout.open("OriginalDecodificadoStr.txt");
        if(!fout.is_open()){
            throw '3';
        }

        for(int i=0; i<contenidoDecodificado.length(); i+=8){
            string byte;
            for(int j=0; j<8; j++){
                byte+=contenidoDecodificado[i+j];
            }
            fout<<byteToDecimal(byte);
        }
        fout.close();

        //METODO #2

        fin.open("CodificadoMetodo2Str.txt");
        if(!fin.is_open()){
            throw '2';
        }
        fout.open("DecodificadoMetodo2Str.txt");
        if(!fout.is_open()){
            throw '3';
        }

        while(fin.good()){
            char temp=fin.get();
            if(fin.good()){
                contenidoCodificado2 +=temp;
            }
        }


        int i=0, k=0;

        for(int i=0; i<contenidoCodificado2.length(); i++){
            if((i+1)%n==0){

                for(int j=1; j<n; j++){
                    contenidoDecodificado2+=contenidoCodificado2[j+k];
                }
                contenidoDecodificado2+=contenidoCodificado2[i-(n-1)];
                k+=n;

            }
        }
        fout<<contenidoDecodificado2;
        fin.close();
        fout.close();

        //CONVERSION A DECIMAL

        fin.open("DecodificadoMetodo2Str.txt");
        if(!fin.is_open()){
            throw '1';
        }

        fout.open("OriginalDecodificadoMetodo2Str.txt");
        if(!fout.is_open()){
            throw '3';
        }

        for(int i=0; i<contenidoDecodificado2.length(); i+=8){
            string byte;
            for(int j=0; j<8; j++){
                byte+=contenidoDecodificado[i+j];
            }
            fout<<byteToDecimal(byte);
        }

        fin.close();
        fout.close();


    }

    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='1'){
            cout<<"Error al abrir el archivo Codificado.\n";
        }
        else if(c=='2'){
            cout<<"Error al abrir el archivo para Decodificacion.\n";
        }
        else if(c=='3'){
            cout<<"Error al abrir el archivo para Prueba 2.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }

    return 0;
}

char byteToDecimal(string byteString) {
    int decimal = 0;
    int power = 1;

    for (int i = 7; i >= 0; i--) {
        if (byteString[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }

    return decimal;
}
*/
