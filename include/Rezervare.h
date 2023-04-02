#ifndef REZERVARE_H
#define REZERVARE_H


class Rezervare
{
    public:
        char nume[100];
        char prenume[100];
        char telefon[11];
        float avans;
        int camera_rezervata;
        Rezervare();
        virtual ~Rezervare();

    protected:

    private:
};

#endif // REZERVARE_H
