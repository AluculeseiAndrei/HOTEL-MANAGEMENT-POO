#include <iostream>
#include "Client.h"
#include "Camera.h"
#include "Administrator.h"
#include "Angajati.h"
#include <cstring>
#include "functii.h"
#include <fstream>
#include <cstdlib>


using namespace std;
//files
ofstream IN("bani.out", ios::app); // Open in append mode

int main()
{

    int zi,luna,an;
    get_data(zi,luna,an);

    char *cuv;
    char password[100],id[100];
    strcpy(id,"Student");
    strcpy(password,"Suceava");
    float Min=250,Max=1200;
    int ok=1,nr=0,ok2=0,okm=1,i;
    int j;
    int Fcam;
    char c;
    int x;
    Administrator A1;
    Camera c2;
    Client c1;
    ifstream fin("date.out");
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
    char line[256];


    //rescrierea vectorului cu datele din fisier
    while (fin.getline(line, sizeof(line)))
    {
        j=0;
        cuv = strtok(line, ",");
        while (cuv != NULL)
        {
            if (j == 0)
            {
                nr++;
                Fcam=atoi(cuv);
                A1.camere[Fcam].rez=1;
            }
            if (j == 1)
                strcpy(A1.camere[Fcam].p.nume,cuv);

            if (j == 2)
                strcpy(A1.camere[Fcam].p.prenume,cuv);

            if (j == 3)
                strcpy(A1.camere[Fcam].p.telefon,cuv);
            j++;
            cuv = strtok(NULL, ",");
        }
    }
    fin.close();


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
        case '1'://vizualizare camere rezervate
            system("cls");
            if(nr==0)
                cout<<"NU ATI INCHIRIAT NICI O CAMERA!!"<<endl;
            else
                A1.detalii_camere_rezervate();
            tf();
            break;

        case '2'://vizualizare camere libere
            system("cls");
            A1.afisare_camera_libera();
            tf();
            break;
        case '3'://rezerva camera
            system("cls");

            cout<<"ATI ALES OPTIUNEA REZERVA O CAMERA :"<<endl;
            cout<<"Introduceti camera pe care doriti sa o rezervati : ";
            fflush(stdin);
            cin>>x;
            fflush(stdin);

            if(x>10 or x<1)
            {
                cout<<"NU EXISTA CAMERA SELECTATA"<<endl;
                tf();
                break;
            }
            if(ok2==1)
            {

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
        case '4'://eliberare camera
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
        case '5'://citire client
            fflush(stdin);
            system("cls");
            cout<<"ATI ALES SA CITITI UN CLIENT"<<endl;
            cin>>c1;
            ok2=1;
            tf();
            break;
        case '6'://modificare camera
            cout<<"Introduceti camera pe care doriti sa o MODIFICATI : "<<endl;
            cin>>x;
            if(A1.camere[x-1].rez==1)
                cout<<"NU SE POATE FACE MODIFICAREA CAMEREI CAND AVETI PE CINEVA REZERVAT!"<<endl;
            else
                A1.modif_camere(x-1);
            tf();
            break;
        case '7'://cautare camera
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
        default:
            cout<<"OPTIUNE INVALIDA"<<endl;
            cout<<"INTRODUCETI TASTA ENTER PENTRU A CONTINUA";
            fflush(stdin);
            getchar();
            fflush(stdin);
            break;
        case '0'://meniu manager
            system("cls");
            okm=1;
            if(autentificare(id, password)!=1)
                cout<<"PAROLA SAU ID GRESITE"<<endl;
            else
            {
                while(okm==1)
                {
                    system("cls");
                    meniu_manager();
                    fflush(stdin);
                    c=getchar();
                    switch (toupper(c))
                    {
                    case '1'://incasari
                        cout<<"TOTALUL DE INCASARI ESTE DE : "<<A1.castig<<" lei"<<endl;
                        tf();
                        break;
                    case '2'://angajati
                        A1.afisare_angajati();
                        tf();
                        break;
                    case 'E':
                        okm=0;
                        tf();
                        break;
                    default:
                        cout<<"OPTIUNE INVALIDA"<<endl;
                        cout<<"INTRODUCETI TASTA ENTER PENTRU A CONTINUA";
                        fflush(stdin);
                        getchar();
                        fflush(stdin);
                        break;
                    }
                }
            }
            break;
        case 'E':
        {
            ofstream fout("date.out");
            //popularea fisierelor cu date
            for(int i=0; i<A1.nr_camere; i++)
                if(A1.camere[i].rez==1)
                    fout << i << "," << A1.camere[i].p.nume << "," << A1.camere[i].p.prenume << "," << A1.camere[i].p.telefon << endl;

            IN<<zi<<"-"<<luna<<"-"<<an<<"        "<<A1.castig<<"lei"<<endl;
            fout.close();
            IN.close();
            return 0;
            break;
        }
        }
    }


    return 0;

}
