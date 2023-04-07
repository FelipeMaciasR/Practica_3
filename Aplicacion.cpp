#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <Funciones_App.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    string cedula_admin, clave_admin, monto_admin, cedula, clave, monto;
    int metodo, n, opcion;
    try{
        fin.open("sudo.txt");
        if(!fin.is_open()){
            throw '1';
        }
        fout.open("sudoEncrip.txt");
        if(!fout.is_open()){
            throw '2';
        }
        getline(fin, cedula_admin, ',');
        getline(fin, clave_admin, ',');
        fin.seekg(0);
        do{
            cout<<"Ingrese metodo de encriptacion: ";
            cin>>metodo;
            cout<<"Ingrese numero de bits por bloque: ";
            cin>>n;
        }while(metodo!=1 || metodo!=2 && (8%n)!=0);

        if(metodo==1){
            while (getline(fin, cedula, ',') && getline(fin, clave, ',') && getline(fin, monto)){
              fout << cedula << "," << Encriptacion1(Bin(clave),n) << "," << monto << endl;
            }
        }
        else if(metodo==2){
            while (getline(fin, cedula, ',') && getline(fin, clave, ',') && getline(fin, monto)) {
              fout << cedula << "," << Encriptacion2(Bin(clave),n) << "," << monto << endl;
            }
        }
        fin.close();
        fout.close();

        fin.open("sudoEncrip.txt");
        if(!fin.is_open()){
            throw '2';
        }
        string cedulaReg, claveReg, montoReg;
        bool flag;
        do{
            cout<<"Ingrese cedula: ";
            cin>>cedula;
            cout<<"Ingrese clave: ";
            cin>>clave;
            while (getline(fin, cedulaReg, ',') && getline(fin, claveReg, ',') && getline(fin, montoReg)){
              if(metodo==1){
                  if(cedula==cedulaReg && Encriptacion1(Bin(clave),n)==claveReg){
                      flag=true;
                      break;
                  }
                  else
                      flag=false;
              }
              else if(metodo==2){
                  if(cedula==cedulaReg && Encriptacion2(Bin(clave),n)==claveReg){
                      flag=true;
                      break;
                  }
                  else
                      flag=false;
              }
            }
            fin.clear();
            fin.seekg(0);

        }while(flag==false);
        fin.close();
        if(cedula==cedula_admin && clave==clave_admin){
            do{
                cout << "Seleccione una opcion: "<<endl;
                cout << "1. Registrar usuario" << endl;
                cout << "2. Salir" << endl;
                cin >> opcion;
                switch(opcion){
                    case 1:
                    string cedulaNueva, claveNueva, montoNuevo;
                    cout << "Ingrese la cedula del usuario: ";
                    cin >> cedulaNueva;
                    cout << "Ingrese la clave del usuario: ";
                    cin >> claveNueva;
                    cout << "Ingrese el saldo del usuario: ";
                    cin >> montoNuevo;
                    ofstream fout("sudoEncrip.txt", ios::app);
                    if(metodo==1)
                        fout << cedulaNueva << "," << Encriptacion1(Bin(claveNueva),n) << "," << montoNuevo << endl;
                    else if(metodo==2)
                        fout << cedulaNueva << "," << Encriptacion2(Bin(claveNueva),n) << "," << montoNuevo << endl;

                    fout.close();
                        break;
                }
            }while(opcion!=2);
        }
        else{
            do{
                cout << "Seleccione una opcion: "<<endl;
                cout << "1. Consultar saldo" << endl;
                cout << "2. Retirar dinero" << endl;
                cout << "3. Salir" << endl;
                cin >> opcion;
                switch(opcion){
                    case 1:
                    int nuevoSaldo;
                    fin.open("sudoEncrip.txt");
                    if(!fin.is_open()){
                        throw '2';
                    }
                    fin.clear();
                    fin.seekg(0);
                    while (getline(fin, cedulaReg, ',') && getline(fin, claveReg, ',') && getline(fin, montoReg)){
                      if(metodo==1){
                          if(cedula==cedulaReg && Encriptacion1(Bin(clave),n)==claveReg){
                              cout<<"Su saldo es: $"<<montoReg<<endl;
                              nuevoSaldo=stringAInt(montoReg)-1000;
                              break;
                          }

                      }
                      else if(metodo==2){
                          if(cedula==cedulaReg && Encriptacion2(Bin(clave),n)==claveReg){
                              cout<<"Su saldo es: $"<<montoReg<<endl;
                              nuevoSaldo=stringAInt(montoReg)-1000;
                              break;
                          }

                      }
                    }
                    fin.clear();
                    fin.seekg(0);
                    fout.open("sudoAct.txt");

                    while (getline(fin, cedulaReg, ',') && getline(fin, claveReg, ',') && getline(fin, montoReg)){
                        if(metodo==1){
                            if (cedula==cedulaReg && Encriptacion1(Bin(clave),n)==claveReg) {
                                fout << cedulaReg << "," << claveReg << "," << intAString(nuevoSaldo) << endl;
                            }
                            else {
                                fout << cedulaReg << "," << claveReg << "," << montoReg << endl;
                            }
                        }
                        else if(metodo==2){
                            if (cedula==cedulaReg && Encriptacion2(Bin(clave),n)==claveReg) {
                                fout << cedulaReg << "," << claveReg << "," << intAString(nuevoSaldo) << endl;
                            }
                            else {
                                fout << cedulaReg << "," << claveReg << "," << montoReg << endl;
                            }
                        }
                    }
                    fin.close();
                    fout.close();
                    remove("sudoEncrip.txt");
                    rename("sudoAct.txt", "sudoEncrip.txt");
                        break;
                    case 2:
                    int retiro, saldoAct;
                    cout<<"Ingrese el saldo a retirar: ";
                    cin>>retiro;
                    fin.open("sudoEncrip.txt");
                    if(!fin.is_open()){
                        throw '2';
                    }
                    fin.clear();
                    fin.seekg(0);
                    while (getline(fin, cedulaReg, ',') && getline(fin, claveReg, ',') && getline(fin, montoReg)){
                      if(metodo==1){
                          if(cedula==cedulaReg && Encriptacion1(Bin(clave),n)==claveReg){
                              cout<<"Su retiro es de: $"<<retiro<<endl;
                              saldoAct=stringAInt(montoReg)-retiro-1000;
                              break;
                          }

                      }
                      else if(metodo==2){
                          if(cedula==cedulaReg && Encriptacion2(Bin(clave),n)==claveReg){
                              cout<<"Su retiro es de: $"<<retiro<<endl;
                              saldoAct=stringAInt(montoReg)-retiro-1000;
                              break;
                          }

                      }
                    }

                    fin.clear();
                    fin.seekg(0);
                    fout.open("sudoAct.txt");

                    while (getline(fin, cedulaReg, ',') && getline(fin, claveReg, ',') && getline(fin, montoReg)){
                        if(metodo==1){
                            if (cedula==cedulaReg && Encriptacion1(Bin(clave),n)==claveReg) {
                                fout << cedulaReg << "," << claveReg << "," << intAString(saldoAct) << endl;
                            }
                            else {
                                fout << cedulaReg << "," << claveReg << "," << montoReg << endl;
                            }
                        }
                        else if(metodo==2){
                            if (cedula==cedulaReg && Encriptacion2(Bin(clave),n)==claveReg) {
                                fout << cedulaReg << "," << claveReg << "," << intAString(saldoAct) << endl;
                            }
                            else {
                                fout << cedulaReg << "," << claveReg << "," << montoReg << endl;
                            }
                        }
                    }
                    fin.close();
                    fout.close();
                    remove("sudoEncrip.txt");
                    rename("sudoAct.txt", "sudoEncrip.txt");
                        break;
                }
            }while(opcion!=3);

        }
    fin.open("sudoEncrip.txt");
    if(!fin.is_open()){
        throw '2';
    }
    fout.open("sudo.txt");
    if(!fout.is_open()){
        throw '1';
    }
    if(metodo==1){
        while (getline(fin, cedula, ',') && getline(fin, clave, ',') && getline(fin, monto)){
          fout << cedula << "," << Decimal(Desencriptacion1(clave,n)) << "," << monto << endl;
        }
    }
    else if(metodo==2){
        while (getline(fin, cedula, ',') && getline(fin, clave, ',') && getline(fin, monto)) {
          fout << cedula << "," << Decimal(Desencriptacion1(clave,n)) << "," << monto << endl;
        }
    }
    fin.close();
    fout.close();



    }catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='1')
            cout<<"Error al abrir el archivo sudo.\n";
        else if(c=='2'){
            cout<<"Error al abrir el archivo para sudoEncrip.\n";
        }
    }catch (...){
        cout<<"Error no definido\n";
    }

    fin.close();

    return 0;
}





