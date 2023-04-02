#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
using namespace std;

class Client
{
    public:
        bool rez;
        char nume[100];
        char prenume[100];
        char telefon[11];
        int zile;
        friend istream& operator>> (istream &c, Client &c1 );
        Client();
        virtual ~Client();
    protected:

    private:
};

#endif // CLIENT_H
