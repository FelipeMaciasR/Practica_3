/*
#include <iostream>
#include <fstream>
using namespace std;

char byteArrayToChar(char byteArray[8]);

int main()
{
    ifstream fin;
    ofstream fout;
    try{
        fin.open("CodificadoMetodo1Char.txt");
        if(!fin.is_open()){
            throw '1';
        }

        fout.open("DecodificadoMetodo1Char.txt");
        if(!fout.is_open()){
            throw '2';
        }
        //METODO #1

        int n=4, uno=0, cero=0;

        for(int i=0; i<n; i++){
            char Caracter=fin.get();
            if(Caracter=='1'){
                fout<<0;
                cero++;
            }
            else{
                fout<<1;
                uno++;
            }
        }
        while(fin.good()){
            if(uno==cero){
                cero=0;
                uno=0;
                for(int i=1; i<=n; i++){
                    char Caracter=fin.get();
                    if(Caracter=='1' && fin.good()){
                        fout<<0;
                        cero++;
                    }
                    else if(fin.good()){
                        fout<<1;
                        uno++;
                    }
                }
            }
            else if(cero>uno){
                cero=0;
                uno=0;
                for(int i=1; i<=n; i++){
                    char Caracter=fin.get();
                    if(i%2==0 && fin.good()){
                        if(Caracter=='1'){
                            fout<<0;
                            cero++;
                        }
                        else{
                            fout<<1;
                            uno++;
                        }
                    }
                    else if(fin.good()){
                        fout<<Caracter;
                        if(Caracter=='1')
                            uno++;
                        else
                            cero++;
                    }
                }
            }
            else{
                cero=0;
                uno=0;
                for(int i=1; i<=n; i++){
                    char Caracter=fin.get();
                    if(i%3==0 && fin.good()){
                        if(Caracter=='1'){
                            fout<<0;
                            cero++;
                        }
                        else{
                            fout<<1;
                            uno++;
                        }
                    }
                    else if(fin.good()){
                        fout<<Caracter;
                        if(Caracter=='1')
                            uno++;
                        else
                            cero++;
                    }
                }
            }
        }
        fin.close();
        fout.close();

        fin.open("DecodificadoMetodo1Char.txt");
        if(!fin.is_open()){
            throw '1';
        }

        fout.open("OriginalDecodificadoMetodo1Char.txt");
        if(!fout.is_open()){
            throw '3';
        }

        while(fin.good()){
            char byte[8];
            for(int i=0; i<8; i++){
                byte[i]=fin.get();
            }
            if(fin.good())
                fout<<byteArrayToChar(byte);
        }
        fin.close();
        fout.close();

        //METODO #2
        fin.open("CodificadoMetodo2Char.txt");
        if(!fin.is_open()){
            throw '1';
        }

        fout.open("DecodificadoMetodo2Char.txt");
        if(!fout.is_open()){
            throw '2';
        }

        char bloque[n];
        int i=0;
        while(fin.good()){
            bloque[i]=fin.get();
            i++;
            if(i==n){
                for(int j=1; j<n; j++){
                    fout<<bloque[j];
                }
                fout<<bloque[0];
                i=0;
            }
        }
        fin.close();
        fout.close();

        //CONVERSION DE BINARIO
        fin.open("DecodificadoMetodo2Char.txt");
        if(!fin.is_open()){
            throw '1';
        }

        fout.open("OriginalDecodificadoMetodo2Char.txt");
        if(!fout.is_open()){
            throw '3';
        }

        while(fin.good()){
            char byte[8];
            for(int i=0; i<8; i++){
                byte[i]=fin.get();
            }
            if(fin.good())
                fout<<byteArrayToChar(byte);
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

char byteArrayToChar(char byteArray[8]){
    int decimalValue = 0;
    int base = 1;
    for(int i = 7; i >= 0; i--) {
        decimalValue += base * (byteArray[i]-48);
        base *= 2;
    }
    return decimalValue;
}

*/
