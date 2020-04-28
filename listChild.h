#ifndef LISTCHILD_H_INCLUDED
#define LISTCHILD_H_INCLUDED
#include <iostream>
#define nextChild(P) P->nextChild
#define prevChild(P) P->prevChild
#define infoChild(P) P->infoChild
#define firstChild(L) L.firstChild
#define busana(P) P->busana

// Double Circular
// child : busana

using namespace std;

struct infotypeChild
{
    int kodeBusana;
    string jenisBusana;
    string ukuranBusana;
    int jumlahBusana;
};

typedef struct elmlistChild *addressChild;

struct elmlistChild
{
    infotypeChild infoChild;
    addressChild nextChild;
    addressChild prevChild;
};

struct listChild
{
    addressChild firstChild;
};

void createListChild(listChild &L);
addressChild allocateChild(int code, string kindof, string ukuran, int jumlah);
void insertFirstChild(listChild &L, addressChild P);
void insertAfterChild(listChild &L, addressChild prec, addressChild P);
void insertLastChild(listChild &L, addressChild P);
void insertSortChild(listChild &L, addressChild P);
void deleteFirstChild(listChild &L, addressChild &P);
void deleteAfterChild(listChild &L, addressChild prec, addressChild &P);
void deleteLastChild(listChild &L, addressChild &P);
void printinfoChild(listChild L);
addressChild searchElmChild(listChild &L, int kode);



#endif // LISTCHILD_H_INCLUDED
