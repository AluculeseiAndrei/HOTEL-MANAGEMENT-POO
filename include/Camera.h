#ifndef CAMERA_H
#define CAMERA_H
#include "Rezervare.h"
#include <iostream>
using namespace std;

class Camera
{
    public:
        float pret;
        int nr_persoane;
        int numar;
        bool rez;
        bool vedere;
        bool televizor;
        bool ac;
        bool frigider;
        bool bucatarie;
        bool terasa;
        Rezervare p;
        Camera();
        virtual ~Camera();
        friend istream& operator>> (istream &c, Camera &c1 );
        Camera(int _nr_persoane ,bool _vedere,bool _televizor,bool _ac,bool _bucatarie,bool _terasa,float _pret);
        Camera(float _pret,int _nr_persoane,bool _rez);

    protected:

    private:
};

#endif // CAMERA_H
