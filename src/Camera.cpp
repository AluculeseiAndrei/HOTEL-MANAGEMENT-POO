#include "Camera.h"
#include <cstring>
using namespace std;

Camera::~Camera()
{
    //dtor
}
Camera::Camera()
{
    pret=300;
    nr_persoane=2;
    rez=0;
    strcpy(p.nume,"null");
    strcpy(p.prenume,"null");
    strcpy(p.telefon,"null");
    vedere=0;
    televizor=0;
    ac=0;
    frigider=1;
    bucatarie=0;
    terasa=0;

}
Camera::Camera(int _nr_persoane ,bool _vedere,bool _televizor,bool _ac,bool _bucatarie,bool _terasa,float _pret)
{
    this->pret=_pret;
    this->nr_persoane=_nr_persoane;
    this->rez=0;
    this->vedere=_vedere;
    this->televizor=_televizor;
    this->ac=_ac;
    this->bucatarie=_bucatarie;
    this->terasa=_terasa;
    this->frigider=1;
    strcpy(p.nume,"null");
    strcpy(p.prenume,"null");
    strcpy(p.telefon,"null");
}
istream& operator>> (istream &c, Camera &c1 )
{
    cout<<"INTRODUCETI PRETUL CAMEREI";
    c>>c1.pret;
    cout<<"NUMARUL PERSOANELOR";
    c>>c1.nr_persoane;
    c1.rez=0;
    strcpy(c1.p.nume,"null");
    strcpy(c1.p.prenume,"null");
    strcpy(c1.p.telefon,"null");
}
