#ifndef LISTRELASI_H_INCLUDED
#define LISTRELASI_H_INCLUDED
#include <iostream>
#include "listChild.h"
#include "listParent.h"
#define nextRelasi(P) P->nextRelasi
#define infoRelasi(P) P->infoRelasi
#define firstRelasi(L) L.firstRelasi

//Single linked list
// By : Berliana Shafa W - 1301194181 and Michelle C.F.B - 1301194405


using namespace std;

typedef struct elmlistRelasi *addressRelasi;

struct elmlistRelasi
{
    addressChild busana;
    addressParent peminjam;
    addressRelasi nextRelasi;
};

struct listRelasi
{
    addressRelasi firstRelasi;
};

void createListRelasi(listRelasi &L);
addressRelasi allocateRelasi(addressParent P, addressChild Q);
void insertRelasi(listRelasi &L, addressParent R, addressChild Q);
void deleteFirstRelasi(listRelasi &L, addressRelasi &P);
void deleteAfterRelasi(listRelasi &L, addressRelasi prec, addressRelasi &P);
void deleteLastRelasi(listRelasi &L, addressRelasi &P);
void printinfoRelasi(listRelasi L);
addressRelasi searchElmRelasi(listRelasi &L, int ID, int kode);
int totalPeminjaman (listRelasi L);
int totalPinjamBusana (listRelasi L);
int ratarataPinjaman (listRelasi L);


#endif // LISTRELASI_H_INCLUDED
