#include <iostream>
#include "Client.h"
#include "Camera.h"
#include "Administrator.h"
#include "Angajati.h"
#include <cstring>
using namespace std;

int main()
{
    //cod de testare a constructorilor
    Administrator A1;
    int i;
    cout<<A1.nume<<endl;
    Client c1;
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
    cout<<c1.nume<<endl;
    cout<<"Citire client"<<endl;
    cin>>c1;
    cout<<c1;
    for(i=0; i<A1.nr_camere; i++)
        cout<<A1.camere[i].pret<<" "<<A1.camere[i].nr_persoane<<endl;
    fflush(stdin);
    getchar();
    system("cls");
    A1.afisare_camera_libera();
     fflush(stdin);
    getchar();
    system("cls");
    A1.detalii_camere_rezervate();

    return 0;
}
