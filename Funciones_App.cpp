#include <iostream>
#include <string>
#include <Funciones_App.h>
using namespace std;

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

string Bin(string str){
    string bin="";
    int bloque;
    for(int i=0; i<str.length(); i++){
        for(int j=0;j<8;j++){
            bin=bin+char(*(Binario(str[i])+j)+48);
        }
    }
    return bin;
}

int stringAInt(string str) {
    int num = 0;
    for (int i = 0; i < str.length(); i++) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

string intAString(int num) {
    if (num == 0) {
        return "0";
    }
    string str = "";
    while (num > 0) {
        char digito = (num % 10) + '0';
        str = digito + str;
        num /= 10;
    }
    return str;
}


string Encriptacion1(string bin, int n){
    string binEncrip_1;
    int uno=0, cero=0;
    for(int i=0; i<n; i++){
        if(bin[i]=='1'){
            binEncrip_1+='0';
            uno++;
        }
        else{
            binEncrip_1+='1';
            cero++;
        }
    }

    for(int i=n; i<bin.length(); i+=n){
        if(uno==cero){
            cero=0;
            uno=0;
            for(int j=0; j<n; j++){
                if(bin[i+j]=='1'){
                    binEncrip_1+='0';
                    uno++;
                }
                else{
                    binEncrip_1+='1';
                    cero++;
                }
            }
        }
        else if(cero>uno){
            cero=0;
            uno=0;
            for(int j=0; j<n; j++){
                if((j+1)%2==0){
                    if(bin[i+j]=='1'){
                        binEncrip_1+='0';
                        uno++;
                    }
                    else{
                        binEncrip_1+='1';
                        cero++;
                    }
                }
                else{
                    binEncrip_1+=bin[i+j];
                    if(bin[i+j]=='1')
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
                    if(bin[i+j]=='1'){
                        binEncrip_1+='0';
                        uno++;
                    }
                    else{
                        binEncrip_1+='1';
                        cero++;
                    }
                }
                else{
                    binEncrip_1+=bin[i+j];
                    if(bin[i+j]=='1')
                        uno++;
                    else
                        cero++;
                }
            }
        }
    }
    return binEncrip_1;
}

string Encriptacion2(string bin, int n){
    int k=0;
    string binEncrip_2;
    for(int i=0; i<bin.length(); i++){
        if((i+1)%n==0){
            binEncrip_2+=bin[i];
            for(int j=0; j<n-1; j++){
                binEncrip_2+=bin[j+k];
            }
            k+=n;
        }
    }
    return binEncrip_2;
}

string Desencriptacion1(string binEncrip_1, int n){
    int uno=0, cero=0;
    string binDesencrip_1;
    for(int i=0; i<n; i++){
        if(binEncrip_1[i]=='1'){
            binDesencrip_1+='0';
            cero++;
        }
        else{
            binDesencrip_1+='1';
            uno++;
        }
    }


    for(int i=n; i<binEncrip_1.length(); i+=n){
        if(uno==cero){
            cero=0;
            uno=0;
            for(int j=0; j<n; j++){
                if(binEncrip_1[i+j]=='1'){
                    binDesencrip_1+='0';
                    cero++;
                }
                else{
                    binDesencrip_1+='1';
                    uno++;
                }
            }
        }
        else if(cero>uno){
            cero=0;
            uno=0;
            for(int j=0; j<n; j++){
                if((j+1)%2==0){
                    if(binEncrip_1[i+j]=='1'){
                        binDesencrip_1+='0';
                        cero++;
                    }
                    else{
                        binDesencrip_1+='1';
                        uno++;
                    }
                }
                else{
                    binDesencrip_1+=binEncrip_1[i+j];
                    if(binEncrip_1[i+j]=='1')
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
                    if(binEncrip_1[i+j]=='1'){
                        binDesencrip_1+='0';
                        cero++;
                    }
                    else{
                        binDesencrip_1+='1';
                        uno++;
                    }
                }
                else{
                    binDesencrip_1+=binEncrip_1[i+j];
                    if(binEncrip_1[i+j]=='1')
                        uno++;
                    else
                        cero++;
                }
            }
        }
    }
    return binDesencrip_1;
}

string Desencriptacion2(string binEncrip_2, int n){
    int k=0;
    string binDesencrip_2;
    for(int i=0; i<binEncrip_2.length(); i++){
        if((i+1)%n==0){

            for(int j=1; j<n; j++){
                binDesencrip_2+=binEncrip_2[j+k];
            }
            binDesencrip_2+=binEncrip_2[i-(n-1)];
            k+=n;

        }
    }
    return binDesencrip_2;
}

string Decimal(string bin){
    string decimal = "";
    for (int i = 0; i < bin.length(); i += 8) {
        int k = 0;
        for (int j = 0; j < 8; j++) {
            if (i + j < bin.length()) {
                k = k * 2 + bin[i + j] - 48;
            }
        }
        char character = (char) k;
        decimal += character;
    }
    return decimal;
}

