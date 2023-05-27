#include "Administrator.h"
#include "Camera.h"
#include "Client.h"
#include <cstring>
#include <iostream>
using namespace std;
Administrator::Administrator()
{
    //ctor
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
    delete []camere;
    delete []ang;
}
void Administrator::afisare_angajati()
{
    int i;
    cout<<"Angajati sunt urmatorii : "<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|                        |                       |              |               |               |"<<endl;
    cout<<"|"<<"\tNUME\t\t |\tPRENUME\t\t |   SALARIU\t|      POST\t|    TELEFON\t|"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
     for(i=0;i<nAngajati;i+=1)
        {
         cout<<"|\t"<<ang[i].nume<<"\t\t |\t"<<ang[i].prenume<<"\t\t |\t"<<ang[i].getSalariu()<<"\t|    "<<ang[i].getPost()<<"\t|   "<<ang[i].telefon<<"  |"<<endl;
         cout<<"|                        |                       |              |               |               |"<<endl;
         cout<<"-------------------------------------------------------------------------------------------------"<<endl;
        }

}
void Administrator::afisare_camera_libera()
{
    int i;
    cout<<"Camerele disponibile sunt : "<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    cout<<"|                        |                       |                              |"<<endl;
    cout<<"|"<<"\t CAMERA \t | \t PRETUL \t | \t NUMAR DE PERSOANE \t|"<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    for(i=0;i<nr_camere;i+=1)
       if(camere[i].rez==0)
        {
         cout<<"|                        |                       |                              |"<<endl;
         cout<<"|\tCamera "<<i+1<<"\t |\t   "<<camere[i].pret<<"\t \t |\t\t"<<camere[i].nr_persoane<<"\t\t|"<<endl;
         cout<<"|                        |                       |                              |"<<endl;
         cout<<"---------------------------------------------------------------------------------"<<endl;
        }
}
bool Administrator::camera_libera(int numar_camera)
{
    if(camere[numar_camera].rez==1)//daca camera este deja rezervata
       return 0;//nu o pot inchiria
    return 1;//o pot inchiria
}

void Administrator::rezerva_camera(int numar_camera,Client c)
{
    int i;
    camere[numar_camera].rez=1;
    strcpy(camere[numar_camera].p.nume,c.nume);
    strcpy(camere[numar_camera].p.prenume,c.prenume);
    strcpy(camere[numar_camera].p.telefon,c.telefon);
}

void Administrator::detalii_camere_rezervate()
{
    int i;
    cout<<"CAMERELE REZERVATE SUNT : "<<endl;
   cout<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|                        |                       |                              |                              |                              |"<<endl;
    cout<<"|"<<"\t CAMERA \t | \t PRETUL \t | \t NUMAR DE PERSOANE \t|\tNUME PERSOANA      \t| \t TELEFON \t      |"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for(i=0;i<nr_camere;i+=1)
       if(camere[i].rez==1)
        {
         cout<<"|                        |                       |                              |                              |                              |"<<endl;
         cout<<"|\tCamera "<<i+1<<"\t |\t   "<<camere[i].pret<<"\t \t |\t\t"<<camere[i].nr_persoane<<"\t\t|\t"<<camere[i].p.nume<<" "<<camere[i].p.prenume<<"\t       |\t"<<camere[i].p.telefon<<"\t      |"<<endl;
         cout<<"|                        |                       |                              |                              |                              |"<<endl;
         cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        }
}
void Administrator::eliberare(int numar_camera)
{
    int i;
    camere[numar_camera].rez=0;
}
void Administrator::modif_camere(int numar_camera)
{
    Camera c1;
    cin>>camere[numar_camera];

}
bool Administrator::camere_egale(Camera c1,Camera c2)
{
    if(c2.ac==c1.ac and c2.bucatarie==c1.bucatarie and c2.terasa==c1.terasa and  c2.vedere==c1.vedere and c2.televizor==c1.televizor and c1.nr_persoane==c2.nr_persoane and c2.rez==c1.rez)
        return 1;
    else
        return 0;

}
void Administrator::cautare(Camera c1)
{
    int i,nr=0;
    for(i=0;i<nr_camere;i+=1)
       if(this->camere_egale(c1,this->camere[i])==1 and this->camera_libera(i)==1)
        nr++;
    if(nr!=0)
    {
    cout<<"Camerele care au caracteristicile dorite sunt urmatoarele : "<<endl;
    cout<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    cout<<"|                        |                       |                              |"<<endl;
    cout<<"|"<<"\t CAMERA \t | \t PRETUL \t | \t NUMAR DE PERSOANE \t|"<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
        for(i=0;i<nr_camere;i+=1)
            if(this->camere_egale(c1,this->camere[i])==1 and this->camera_libera(i)==1)
            {
             cout<<"|                        |                       |                              |"<<endl;
             cout<<"|\tCamera "<<i+1<<"\t |\t   "<<camere[i].pret<<"\t \t |\t\t"<<camere[i].nr_persoane<<"\t\t|"<<endl;
             cout<<"|                        |                       |                              |"<<endl;
             cout<<"---------------------------------------------------------------------------------"<<endl;
            }
    }
    else
        cout<<"NU EXISTA CAMERE DISPONIBILE CU CARACTERISTICILE PE CARE LE-ATI CAUTAT!";


    cout<<endl;
}
