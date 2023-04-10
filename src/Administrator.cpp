#include "Administrator.h"
#include <cstring>
using namespace std;
Administrator::Administrator()
{
    strcpy(nume,"ION");
    strcpy(prenume,"POPESCU");
    castig=0;
    nr_camere=10;
    nAngajati=5;
    camere=new Camera[100];
    ang=new Angajati[nAngajati];
}

Administrator::~Administrator()
{
    //dtor
}
