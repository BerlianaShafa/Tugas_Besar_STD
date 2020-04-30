#include "listRelasi.h"
#include <iostream>
#include <stdlib.h>

void createListRelasi(listRelasi &L)
// By : Berliana Shafa W - 1301194181
{
    firstRelasi(L) = NULL;
}

addressRelasi allocateRelasi(addressParent P, addressChild Q)
// By : Berliana Shafa W - 1301194181
{
    addressRelasi R;
    R = new elmlistRelasi;
    peminjam(R) = P;
    busana(R) = Q;
    nextRelasi(R) = NULL;

    return R;
}

void insertRelasi(listRelasi &L, addressParent R, addressChild Q)
// By : Berliana Shafa W - 1301194181
{
    addressRelasi P = allocateRelasi(R,Q);
    addressRelasi T = firstRelasi(L);
    if (firstRelasi(L) == NULL)
    {
        firstRelasi(L) = P;
    }
    else
    {
        while (nextRelasi(T) != NULL )
        {
            T = nextRelasi(T);
        }
        nextRelasi(T) = P;
    }
    cout<<"masuk"<<endl;
}

void deleteFirstRelasi(listRelasi &L, addressRelasi &P)
// By : Berliana Shafa W - 1301194181
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
// By : Berliana Shafa W - 1301194181
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
// By : Berliana Shafa W - 1301194181
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
// By : Berliana Shafa W - 1301194181
{
    addressRelasi P = firstRelasi(L);
    int 1 = 0;
    if (firstRelasi(L) == NULL)
    {
        cout<<"List Kosong"<<endl;
    }
    else
    {
        while (P != NULL)
        {
            cout<<"PENYEWAAN/PEMINJAMAN "<<i<<endl;
            cout<<"Nama Penyewa : "<< infoParent(peminjam(P)).namaPenyewa<<endl;
            cout<<"ID Penyewa : " <<infoParent(peminjam(P)).idPenyewa<< endl;
            cout<<"Umur Penyewa : "<<infoParent(peminjam(P)).umurPenyewa<< endl;
            cout<<"Alamat Penyewa :"<<infoParent(peminjam(P)).alamatPenyewa<<endl;
            cout<<"Kode Busana : "<<infoChild(busana(P)).kodeBusana<<endl;
            cout<<"Jenis Busana : "<<infoChild(busana(P)).jenisBusana<<endl;
            cout<<"Ukuran Busana : "<<infoChild(busana(P)).ukuranBusana<<endl;
            cout<<"Jumlah Busana : "<<infoChild(busana(P)).jumlahBusana<<endl;
            cout<<endl;
            i++;
            P = nextRelasi(P);
        }
    }
}

addressRelasi searchElmRelasi(listRelasi &L, int ID, int kode)
// By : Berliana Shafa W - 1301194181
{
    addressRelasi P = firstRelasi(L);
    if (P != NULL)
    {
        while ( (nextRelasi(P) != NULL) && (infoParent(peminjam(P)).idPenyewa != ID) && (infoChild(busana(P)).kodeBusana != kode))
        {
            P = nextRelasi(P);
        }
        return P;
    }
    else
    {
        return NULL;
    }
}

int totalPeminjaman (listRelasi L)
// By : Berliana Shafa W - 1301194181
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
// By : Berliana Shafa W - 1301194181
{
    addressRelasi P = firstRelasi(L);
    int i = 0;
    int j = 0;
    while (P != NULL)
    {
        j = infoChild(busana(P)).jumlahBusana;
        i = i + j;
        P = nextRelasi(P);
    }

    return i;
}

int ratarataPinjaman (listRelasi L)
// By : Berliana Shafa W - 1301194181
{
    int i,j,average;
    i = totalPeminjaman(L);
    j = totalPinjamBusana(L);
    if (i==0 && j==0)
    {
        return 0;
    }
    else
    {
        average = j / i ;
        return average;
    }
}
