#include "Administrator.h"
#include <cstring>
using namespace std;
Administrator::Administrator()
{
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
    //dtor
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
