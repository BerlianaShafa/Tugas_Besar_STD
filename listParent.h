#ifndef LISTPARENT_H_INCLUDED
#define LISTPARENT_H_INCLUDED
#include <iostream>
#define nextParent(P) P->nextParent
#define infoParent(P) P->infoParent
#define firstParent(L) L.firstParent
#define peminjam(P) P->peminjam

//Single linked list

using namespace std;

struct infotypeParent
{
    int idPenyewa;
    string alamatPenyewa;
    string namaPenyewa;
    int umurPenyewa;
};

typedef struct elmlistParent *addressParent;

struct elmlistParent
{
    infotypeParent infoParent;
    addressParent nextParent;
};

struct listParent
{
    addressParent firstParent;
};

void createListParent(listParent &L);
addressParent allocateParent(int id, string alamat, string name, int ages);
void insertFirstParent(listParent &L, addressParent P);
void insertAfterParent(listParent &L, addressParent prec, addressParent P);
void insertLastParent(listParent &L, addressParent P);
void insertSortParent(listParent &L, addressParent P);
void deleteFirstParent(listParent &L, addressParent &P);
void deleteAfterParent(listParent &L, addressParent prec, addressParent &P);
void deleteLastParent(listParent &L, addressParent &P);
void printinfoParent(listParent L);
addressParent searchElmParent(listParent &L, int ID);




#endif // LISTPARENT_H_INCLUDED
