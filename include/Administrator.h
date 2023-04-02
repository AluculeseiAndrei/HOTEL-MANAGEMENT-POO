#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "Camera.h"
#include "Angajati.h"
#include "Client.h"
class Administrator
{
    public:
        int nAngajati;
        Angajati *ang;
        char nume[100];
        char prenume[100];
        float castig;
        int nr_camere;
        Camera *camere;
        Administrator();
        virtual ~Administrator();
        void rezerva_camera(int camera_rez,Client c);
        void afisare_camera_libera();
        void detalii_camere_rezervate();
        void eliberare(int numar_camera);
        bool camera_libera(int numar_camera);
        void modif_camere(int numar_camera);
        bool camere_egale(Camera c1,Camera c2);
        void cautare(Camera c1);
        void afisare_angajati();



    protected:

    private:
};

#endif // ADMINISTRATOR_H
