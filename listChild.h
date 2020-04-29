#ifndef LISTCHILD_H_INCLUDED
#define LISTCHILD_H_INCLUDED
#include <iostream>
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define firstChild(L) L.firstChild
#define lastChild(L) L.lastChild

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
    infotypeChild info;
    addressChild next;
    addressChild prev;
};

struct listChild
{
    addressChild firstChild;
    addressChild lastChild;
};

void createListChild(listChild &L);
addressChild allocateChild(infotypeChild x);
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
