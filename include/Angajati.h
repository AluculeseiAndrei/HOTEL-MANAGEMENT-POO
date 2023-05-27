#ifndef ANGAJATI_H
#define ANGAJATI_H
#include "Client.h"
using namespace std;

class Angajati:public Client
{
    public:
        Angajati();
        virtual ~Angajati();
        float getSalariu();
        char *getPost();
        Angajati(char* _nume, char* _prenume, char* _telefon, float _salariu, char* _post);


    protected:

    private:
        float salariu;
        char post[100];
};

#endif // ANGAJATI_H
