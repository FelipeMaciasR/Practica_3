/*
#include <iostream>
#include <fstream>
using namespace std;

int* Binario(char x);

int main()
{
    ifstream fin;
    ofstream fout;
    try{
        fin.open("OriginalChar.txt");
        if(!fin.is_open()){
            throw '1';
        }

        fout.open("BinarioChar.txt");
        if(!fout.is_open()){
            throw '2';
        }

        while(fin.good()){
            char Caracter=fin.get();
            if(fin.good()){
                for(int j=0;j<8;j++){
                    fout << *(Binario(Caracter)+j);
                }
            }
        }
        fin.close();
        fout.close();

        fin.open("BinarioChar.txt");
        if(!fin.is_open()){
            throw '2';
        }
        fout.open("CodificadoMetodo1Char.txt");
        if(!fout.is_open()){
            throw '3';
        }
        int n=4, uno=0, cero=0;
        //cout<<"Ingrese un numero: "<<endl;
        //cin>>n;

        //METODO #1

        for(int i=0; i<n; i++){
            char Caracter=fin.get();
            if(Caracter=='1'){
                fout<<0;
                uno++;
            }
            else{
                fout<<1;
                cero++;
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
                        uno++;
                    }
                    else if(fin.good()){
                        fout<<1;
                        cero++;
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
                            uno++;
                        }
                        else{
                            fout<<1;
                            cero++;
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
                            uno++;
                        }
                        else{
                            fout<<1;
                            cero++;
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
        //METODO #2
        fin.open("BinarioChar.txt");
        if(!fin.is_open()){
            throw '2';
        }
        fout.open("CodificadoMetodo2Char.txt");
        if(!fout.is_open()){
            throw '3';
        }
        char bloque[n];
        int i=0;

        while(fin.good()){
            bloque[i]=fin.get();
            i++;
            if(i==n){
                fout<<bloque[i-1];
                for(int j=0; j<n-1; j++){
                    fout<<bloque[j];
                }
                i=0;
            }
        }
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
