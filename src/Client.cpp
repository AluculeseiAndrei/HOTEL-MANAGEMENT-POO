#include "Client.h"
#include <cstring>
using namespace std;
Client::Client()
{
         rez=0;
        strcpy(nume,"MIHAI");
        strcpy(prenume,"VASILOVICI");
        strcpy(telefon,"0758371910");
        zile=0;
}

Client::~Client()
{
    //dtor
}
istream& operator>>( istream &c, Client &c1)
{
    fflush(stdin);
    cout<<"INTRODUCETI NUMELE CLIENTULUI  ";
    c.getline(c1.nume,100);
    fflush(stdin);
    cout<<"INTRODUCETI PRENUMELE CLIENTULUI  ";
    c.getline(c1.prenume,100);
    fflush(stdin);
    cout<<"INTRODUCETI NUMARUL DE TELEFON AL CLIENTULUI  ";
    fflush(stdin);
    c.getline(c1.telefon,100);
    c1.rez=0;
    fflush(stdin);
    cout<<"INTRODUCETI NUMARUL DE ZILE CAT VA STA CLIENTUL : ";
    fflush(stdin);
    c>>c1.zile;
    fflush(stdin);
    return c;
}
ostream& operator<<( ostream &c, Client &c1)
{
    c<<"DATELE CLIENTULUI:\nNUME:"<<c1.nume<<"\nPRENUME:"<<c1.prenume<<"\nTELEFON:"<<c1.telefon<<"\n";
    return c;
}
