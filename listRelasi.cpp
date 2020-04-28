#include "listRelasi.h"
#include <iostream>
#include <stdlib.h>

void createListRelasi(listRelasi &L)
{
    firstRelasi(L) = NULL;
}

addressRelasi allocateRelasi(addressParent P, addressChild Q)
{
    addressRelasi R;
    R = new elmlistRelasi;
    peminjam(R) = P;
    busana(R) = Q;
    nextRelasi(R) = NULL;

    return R;
}

void insertRelasi(listRelasi &L, addressRelasi P)
{
    if (firstRelasi(L) == NULL)
    {
        firstRelasi(L) = P;
    }
    else
    {
        addressRelasi R;
        while (nextRelasi(firstRelasi(L)) != NULL )
        {
            firstRelasi(L) = nextRelasi(firstRelasi(L));
        }
        firstRelasi(L) = nextRelasi(firstRelasi(L));
        nextRelasi(firstRelasi(L)) = R;
        nextRelasi(R) = NULL;
    }
}

void deleteFirstRelasi(listRelasi &L, addressRelasi &P)
{
    P = firstRelasi(L);
    if (firstRelasi(L) == NULL)
    {
        firstRelasi(L) = NULL;
    }
    else
    {
        firstRelasi(L) = nextRelasi(P);
        nextRelasi(P) = NULL;
    }
}

void deleteAfterRelasi(listRelasi &L, addressRelasi prec, addressRelasi &P)
{
    if (nextRelasi(prec)!=NULL)
    {
        nextRelasi(prec) = P;
        nextRelasi(prec) = nextRelasi(P);
        nextRelasi(P) = NULL;
    }
    else
    {
        deleteFirstRelasi(L,P);
    }
}

void deleteLastRelasi(listRelasi &L, addressRelasi &P)
{
    P = firstRelasi(L);
    if (firstRelasi(L) == NULL)
    {
        firstRelasi(L) = NULL;
    }
    else
    {
        while (nextRelasi(P) != NULL)
        {
            P = nextRelasi(P);
        }
        nextRelasi(P) = NULL;
    }
}

void printinfoRelasi(listRelasi L)
{
    addressRelasi P = firstRelasi(L);
    if (firstRelasi(L) == NULL)
    {
        cout<<"List Kosong"<<endl;
    }
    else
    {
        while (P !=NULL)
        {
            cout<<"Nama Penyewa : "<< infoParent(peminjam(P)).namaPenyewa<<endl;
            cout<<"ID Penyewa : " <<infoParent(peminjam(P)).idPenyewa<< endl;
            cout<<"Umur Penyewa : "<<infoParent(peminjam(P)).umurPenyewa<< endl;
            cout<<"Alamat Penyewa :"<<infoParent(peminjam(P)).alamatPenyewa<<endl;
            cout<<"Kode Busana : "<<infoChild(busana(P)).kodeBusana<<endl;
            cout<<"Jenis Busana : "<<infoChild(busana(P)).jenisBusana<<endl;
            cout<<"Ukuran Busana : "<<infoChild(busana(P)).ukuranBusana<<endl;
            cout<<"Jumlah Busana : "<<infoChild(busana(P)).jumlahBusana<<endl;
            cout<<endl;
            P = nextRelasi(P);
        }
    }
}

addressRelasi searchElmRelasi(listRelasi &L, int ID, int kode)
{
    addressRelasi P = firstRelasi(L);
    while ( P != NULL && infoParent(peminjam(P)).idPenyewa != ID && infoChild(busana(P)).kodeBusana != kode)
    {
        P = nextRelasi(P);
    }
    return P;
}

int totalPeminjaman (listRelasi L)
{
    addressRelasi P = firstRelasi(L);
    int i = 0;
    while (P != NULL)
    {
        i++;
        P = nextRelasi(P);
    }
    return i;
}

int totalPinjamBusana (listRelasi L)
{
    addressRelasi P = firstRelasi(L);
    int i,j = 0;
    while (P != NULL)
    {
        j = infoChild(busana(P)).jumlahBusana;
        i = i + j;
        P = nextRelasi(P);
    }

    return i;
}

int ratarataPinjaman (listRelasi L)
{
    int average;
    average = totalPinjamBusana(L) / totalPeminjaman(L) ;

    return average;
}
