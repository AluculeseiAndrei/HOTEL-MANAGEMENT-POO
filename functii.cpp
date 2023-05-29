#include <iostream>
#include <cstring>
using namespace std;
void meniu_manager()
{
    cout<<"1.INCASARI"<<endl;
    cout<<"2.VEZI ANGAJATI"<<endl;
    cout<<"E.EXIT"<<endl;
    cout<<"Alegeti o optiune";

}
void meniu()
{
    cout<<"1.AFISARE CAMERE REZERVATE"<<endl;
    cout<<"2.AFISARE CAMERE LIBERE"<<endl;
    cout<<"3.INCHIRIAZA O CAMERA PENTRU UN CLIENT"<<endl;
    cout<<"4.ELIBERAREZA O CAMERA"<<endl;
    cout<<"5.CITESTE UN CLIENT DE LA TASTATURA"<<endl;
    cout<<"6.MODIFICARE INFORMATII CAMERE"<<endl;
    cout<<"7.CAUTAREA CAMERE"<<endl;
    cout<<"E.EXIT"<<endl;
    cout<<"Alegeti o optiune";
}
int autentificare(char id1[],char pass1[])
{
    char pass[100],id[100];
    cout<<"PENTRU A INTRA SA VEDETI ACESTE DETALII AVETI NEVOIE DE ID SI PAROLA"<<endl;
    cout<<"ID:";
    fflush(stdin);
    cin.get(id,99);
    cin.get();
    cout<<"PASSWORD:";
    fflush(stdin);
    cin.get(pass,99);
    cin.get();
    if(strcmp(id,id1)==0 and strcmp(pass1,pass)==0)
        return 1;
    return 0;
}
void tf()
{
    cout<<"Introduceti o tasta pentru a continua ";
    fflush(stdin);
    getchar();
    fflush(stdin);
}
