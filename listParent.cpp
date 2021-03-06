#include "listParent.h"
#include <stdio.h>
#include <iomanip>

void createListParent(listParent &L)
// By : Michelle C.F.B - 1301194405
{
    firstParent(L) = NULL;
}

addressParent allocateParent(int id, string alamat, string name, int ages)
// By : Michelle C.F.B - 1301194405 and Berliana ShafaW - 1301194181
{
    addressParent P = NULL;

    P = new elmlistParent;
    infoParent(P).idPenyewa = id;
    infoParent(P).namaPenyewa = name;
    infoParent(P).alamatPenyewa = alamat;
    infoParent(P).umurPenyewa = ages;
    nextParent(P) = NULL;

    return P;
}

void insertFirstParent(listParent &L, addressParent P)
// By : Michelle C.F.B - 1301194405
{
    if(firstParent(L)!=NULL)
    {
        nextParent(P)=firstParent(L);
        firstParent(L)=P;
    }
    else
    {
        firstParent(L)=P;
    }
}

void insertAfterParent(listParent &L, addressParent prec, addressParent P)
// By : Michelle C.F.B - 1301194405
{
    if (nextParent(prec)!=NULL){
        nextParent(P)=nextParent(prec);
    }
    nextParent(prec)=P;
}

void insertLastParent(listParent &L, addressParent P)
// By : Michelle C.F.B - 1301194405
{
   addressParent prec;

    prec=firstParent(L);
    if (firstParent(L)== NULL){
        insertFirstParent(L,P);
    }else {
        while (nextParent(prec) != NULL){
            prec=nextParent(prec);
        }
        insertAfterParent(L,prec,P);
    }
}

void insertSortParent(listParent &L, addressParent P)
// By : Berliana Shafa W - 1301194181
{
    if(firstParent(L) == NULL || infoParent(P).idPenyewa <= infoParent(firstParent(L)).idPenyewa)
    {
        insertFirstParent(L, P);
    }
    else
    {
        addressParent Q = firstParent(L);
        while (nextParent(Q) != NULL)
        {
            Q = nextParent(Q);
        }
        if(infoParent(P).idPenyewa  >= infoParent(Q).idPenyewa)
        {
            insertLastParent(L, P);
        }
        else
        {
            addressParent R = firstParent(L);
            while(infoParent(nextParent(R)).idPenyewa < infoParent(P).idPenyewa)
            {
                R = nextParent(R);
            }
            insertAfterParent(L, R, P);
        }
    }
}


void deleteFirstParent(listParent &L, addressParent &P)
// By : Michelle C.F.B - 1301194405
{
    P=firstParent(L);
    if (nextParent(P) != NULL){
        firstParent(L)=nextParent(P);
    } else {
        firstParent(L)=NULL;
    }
}

void deleteAfterParent(listParent &L, addressParent prec, addressParent &P)
// By : Michelle C.F.B - 1301194405
{
    P=nextParent(prec);
    if (nextParent(P)!=NULL){
        nextParent(prec)=nextParent(P);
    } else{
        nextParent(prec)=NULL;
    }
}

void deleteLastParent(listParent &L, addressParent &P)
// By : Michelle C.F.B - 1301194405
{
    addressParent prec;

    prec=firstParent(L);
    if (nextParent(prec)== NULL){
        firstParent(L) = NULL;
    } else {
        while (nextParent(nextParent(prec)) != NULL){
               prec=nextParent(prec);
        }
        P = nextParent(prec);
        nextParent(prec) = NULL;
    }
}

void printinfoParent(listParent L)
// By : Michelle C.F.B - 1301194405 and Berliana Shafa W - 1301194181
{
    addressParent P;
    int i =1;

    P = firstParent(L);
    if (P == NULL){
        cout<<"|=|=|=|=|=|=|=|=|=|=|=|= MAAF LIST KOSONG =|=|=|=|=|=|=|=|=|=|=|"<<endl<<endl;
    }
    else{
        while (nextParent(P) != NULL)
        {
            cout<<"|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|"<<endl;
            cout<<"                             Penyewa "<<i<<endl;
            cout<<"ID     : "<<P -> infoParent.idPenyewa<<endl;
            cout<<"Nama   : "<<P -> infoParent.namaPenyewa<<endl;
            cout<<"Alamat : "<< P -> infoParent.alamatPenyewa<<endl;
            cout<<"Umur   : "<< P -> infoParent.umurPenyewa<<endl;
            cout<<"|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|"<<endl<<endl;
            P = nextParent(P);
            i++;
        }
        cout<<"|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|"<<endl;
        cout<<"                             Penyewa "<<i<<endl;
        cout<<"ID     : "<<P -> infoParent.idPenyewa<<endl;
        cout<<"Nama   : "<<P -> infoParent.namaPenyewa<<endl;
        cout<<"Alamat : "<< P -> infoParent.alamatPenyewa<<endl;
        cout<<"Umur   : "<< P -> infoParent.umurPenyewa<<endl;
        cout<<"|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|"<<endl<<endl;
    }
    cout<<endl;
}

addressParent searchElmParent(listParent &L, int ID)
// By : Michelle C.F.B - 1301194405 and Berliana Shawa W - 1301194181
{
    addressParent P;

    P=firstParent(L);
    while(P!=NULL && infoParent(P).idPenyewa!=ID)
    {
        P=nextParent(P);
    }
    return P;
}
