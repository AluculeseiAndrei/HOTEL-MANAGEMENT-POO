#include <iostream>
#include "Client.h"
#include "Camera.h"
#include "Administrator.h"
#include "Angajati.h"
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
int main()
{
    char password[100],id[100];
    strcpy(id,"Student");
    strcpy(password,"Suceava");
    float Min=250,Max=1200;
    int ok=1,nr=0,ok2=0,okm=1;
    char c;
    int x;
    Administrator A1;
    Camera c2;
    Client c1;
    //A1.camere={Camera(300,1,0),Camera(500,2,0),Camera(500,3,0)};

    //declarare camere
        A1.camere[0]=Camera(1,1,0,1,0,1,250);
        A1.camere[1]=Camera(1,1,0,1,0,1,250);
        A1.camere[2]=Camera(3,1,1,0,0,1,500);
        A1.camere[3]=Camera(2,1,1,1,1,1,500);
        A1.camere[4]=Camera(1,1,1,1,0,1,300);
        A1.camere[5]=Camera(5,1,1,1,1,1,1000);
        A1.camere[6]=Camera(1,0,0,0,0,0,130);
        A1.camere[7]=Camera(2,0,0,0,0,0,250);
        A1.camere[8]=Camera(2,0,0,0,1,1,300);
        A1.camere[9]=Camera(6,1,1,1,1,1,1200);
    //declarare angajati
    A1.ang[0]=Angajati("POP","ION","0790175488",3000.0,"CAMERIST");
    A1.ang[1]=Angajati("IOANA","BALAN","0712582192",5000.0,"MANAGER");
    A1.ang[2]=Angajati("XENIA","POPA","0758414822",4250,"CONTABIL");
    A1.ang[3]=Angajati("VICTOR","POPESCU","0702022805",2500.0,"GRADINAR");



    while(ok==1)
    {
        system("cls");
        meniu();
        fflush(stdin);

        c=getchar();
        switch(toupper(c))
        {
        case '1':
            system("cls");
            if(nr==0)
                cout<<"NU ATI INCHIRIAT NICI O CAMERA!!"<<endl;
            else
                A1.detalii_camere_rezervate();
            tf();
            break;

        case '2':
            system("cls");
            A1.afisare_camera_libera();
            tf();
            break;
        case '3':
            system("cls");

            cout<<"ATI ALES OPTIUNEA REZERVA O CAMERA :"<<endl;
            if(ok2==1)
            {
                cout<<"Introduceti camera pe care doriti sa o rezervati : ";
                fflush(stdin);
                cin>>x;
                fflush(stdin);
                if(A1.camera_libera(x-1))
                {
                    A1.rezerva_camera(x-1,c1);
                    nr++;
                    A1.castig+=c1.zile*A1.camere[x-1].pret;
                    ok2=0;
                }
                else
                    cout<<"NU SE POATE FACE REZERVAREA DEOARECE CAMERA ESTE DEJA OCUPATA"<<endl;
            }
            else
                cout<<"INTRODUCETI UN CLIENT INAINTE DE A FACE O REZERVARE"<<endl;

            tf();
            break;
        case '4':
            system("cls");
            cout<<"ATI ALES OPTIUNEA ELIBEREAZA O CAMERA :"<<endl;
            cout<<"Introduceti camera pe care doriti sa o eliberati : ";
            cin>>x;
            if(A1.camera_libera(x-1)==1)
                cout<<"NU SE POATE ELIBERA CAMERA PENTRU CA ESTE DEJA LIBERA"<<endl;
            else
            {
                A1.eliberare(x-1);
                nr--;
            }
            tf();
            break;
        case '5':
            system("cls");
            cout<<"ATI ALES SA CITITI UN CLIENT"<<endl;
            cin>>c1;
            ok2=1;
            tf();
            break;
        case '6':
            cout<<"Introduceti camera pe care doriti sa o MODIFICATI : "<<endl;
            cin>>x;
            if(A1.camere[x-1].rez==1)
                cout<<"NU SE POATE FACE MODIFICAREA CAMEREI CAND AVETI PE CINEVA REZERVAT!"<<endl;
            else
                A1.modif_camere(x-1);
            tf();
            break;
        case '7':
            system("cls");
            fflush(stdin);
            cout<<"ATI ALES SELECTAREA CAMERELOR DISPONIBILE IN FUNCTIE DE FACILITATI"<<endl;
            cout<<"RASPUNDETI CU 1 PENTRU A AVEA ACEASTA FACILITATE SAU CU 0 DACA NU: \n";
            cout<<"NR.PERSOANE : ";
            fflush(stdin);
            cin>>c2.nr_persoane;
            fflush(stdin);
            cout<<"VEDERE LA MUNTE : ";
            fflush(stdin);
            cin>>c2.vedere;//
            fflush(stdin);
            cout<<"TELEVIZOR : ";
            fflush(stdin);
            cin>>c2.televizor;//
            fflush(stdin);
            cout<<"AC : ";
            fflush(stdin);
            cin>>c2.ac;//
            fflush(stdin);
            c2.frigider=1;
            cout<<"BUCATARIE : ";
            fflush(stdin);
            cin>>c2.bucatarie;//
            fflush(stdin);
            cout<<"TERASA : ";
            fflush(stdin);
            cin>>c2.terasa;//
            fflush(stdin);
            A1.cautare(c2);
            tf();
            break;

        case 'E':
        {
            return 0;
            break;
        }
        }
    }
    return 0;

}
