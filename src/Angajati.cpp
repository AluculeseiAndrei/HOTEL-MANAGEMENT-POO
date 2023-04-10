#include "Angajati.h"
#include <cstring>
using namespace std;


Angajati::~Angajati()
{
    //dtor
}
Angajati::Angajati()
{

    rez=0;
    strcpy(nume,"PRICOB");
    strcpy(prenume,"MARCU");
    strcpy(telefon,"07555410797");
    zile=0;
    this->salariu=2500;
    strcpy(post,"Camerist");
}
Angajati::Angajati(char _nume[],char _prenume[],char _telefon[], float _salariu[],char _post[])
{

    rez=0;
    zile=0;
    strcpy(nume,_nume);
    strcpy(prenume,_prenume);
    strcpy(telefon,_telefon);

}

float Angajati::getSalariu()
{
    return salariu;
}
char *Angajati::getPost()
{
    return post;
}

