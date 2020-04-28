#ifndef LISTPARENT_H_INCLUDED
#define LISTPARENT_H_INCLUDED
#include <iostream>
#define next(P) P->next
#define info(P) P->info
#define firstParent(L) L.firstParent

//Single linked list

using namespace std;

struct infoParent
{
    int idPenyewa;
    string alamatPenyewa;
    string namaPenyewa;
    int umurPenyewa;
};

typedef struct elmlistParent *addressParent;

struct elmlistParent
{
    infoParent info;
    addressParent next;
};

struct listParent
{
    addressParent firstParent;
};

void createListParent(listParent &L);
addressParent allocateParent(infoParent x);
void insertFirstParent(listParent &L, addressParent P);
void insertAfterParent(listParent &L, addressParent prec, addressParent P);
void insertLastParent(listParent &L, addressParent P);
void deleteFirstParent(listParent &L, addressParent &P);
void deleteAfterParent(listParent &L, addressParent prec, addressParent &P);
void deleteLastParent(listParent &L, addressParent &P);
void printinfoParent(listParent L);
addressParent searchElmParent(listParent &L, string ID);




#endif // LISTPARENT_H_INCLUDED
