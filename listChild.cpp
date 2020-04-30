#include "listChild.h"

void createListChild(listChild &L)
// By : Michelle C.F.B - 1301194405
{
    firstChild(L) = NULL;
}

addressChild allocateChild(int code, string kindof, string ukuran, int jumlah)
// By : Michelle C.F.B - 1301194405 and Berliana Shafa W - 1301194181
{
    addressChild P = NULL;

    P = new elmlistChild;
    infoChild(P).kodeBusana = code;
    infoChild(P).jenisBusana = kindof;
    infoChild(P).ukuranBusana = ukuran;
    infoChild(P).jumlahBusana = jumlah;
    nextChild(P)=NULL;
    prevChild(P)=NULL;

    return P;
}

void insertFirstChild(listChild &L, addressChild P)
// By : Michelle C.F.B - 1301194405 and Berliana Shafa W - 1301194181
{
    if(firstChild(L) == NULL)
    {
        firstChild(L) = P;
        nextChild(P) = P;
        prevChild(P) = P;
    }
    else
    {
        nextChild(P) = firstChild(L);
        prevChild(P) = prevChild(firstChild(L));
        nextChild(prevChild(firstChild(L))) = P;
        prevChild(firstChild(L)) = P;
        firstChild(L) = P;
    }
}

void insertAfterChild(listChild &L, addressChild prec, addressChild P)
// By : Michelle C.F.B - 1301194405
{
    nextChild(P)=nextChild(prec);
    prevChild(nextChild(P))=P;
    nextChild(prec)=P;
    prevChild(nextChild(prec))=prec;
}

void insertLastChild(listChild &L, addressChild P)
// By : Michelle C.F.B - 1301194405
{
    if(firstChild(L) == NULL)
    {
        insertFirstChild(L, P);
    }
    else
    {
        nextChild(P) = firstChild(L);
        prevChild(P) = prevChild(firstChild(L));
        nextChild(prevChild(firstChild(L))) = P;
        prevChild(firstChild(L)) = P;
    }
}


void insertSortChild(listChild &L, addressChild P)
// By : Berliana Shafa W - 1301194181
{
    if (firstChild(L) == NULL || infoChild(P).kodeBusana <= infoChild(firstChild(L)).kodeBusana)
    {
        insertFirstChild(L, P);
    }
    else if(infoChild(P).kodeBusana >= infoChild(prevChild(firstChild(L))).kodeBusana )
    {
        insertLastChild(L, P);
    }
    else
    {
        addressChild Q = firstChild(L);
        while(infoChild(nextChild(Q)).kodeBusana  < infoChild(P).kodeBusana)
        {
            Q = nextChild(Q);
        }
        insertAfterChild(L, Q, P);
    }
}

void deleteFirstChild(listChild &L, addressChild &P)
// By : Michelle C.F.B - 1301194405
{
    P = firstChild(L);
    if(firstChild(L) == NULL)
    {
        cout<<"List Kosong"<<endl;
    }
    else if (nextChild(P)==firstChild(L))
    {
        nextChild(P) = NULL;
        prevChild(P) = NULL;
        firstChild(L) = NULL;
    }
    else
    {
        firstChild(L)=nextChild(P);
        nextChild(prevChild(P))=firstChild(L);
        prevChild(firstChild(L))=prevChild(P);
        nextChild(P)=NULL;
        prevChild(P)=NULL;
    }
}

void deleteAfterChild(listChild &L, addressChild prec, addressChild &P)
// By : Michelle C.F.B - 1301194405
{
    P = nextChild(prec);
    if(nextChild(prec) == firstChild(L))
    {
        deleteLastChild(L, P);
    }
    else if (nextChild(prec) == prec)
    {
        nextChild(P) = NULL;
        prevChild(P) = NULL;
        nextChild(prec) = prec;
        prevChild(prec) = prec;
    }
    else
    {
        nextChild(prec) = nextChild(P);
        prevChild(nextChild(P)) = prec;
        nextChild(P) = NULL;
        prevChild(P) = NULL;
    }
}

void deleteLastChild(listChild &L, addressChild &P)
// By : Michelle C.F.B - 1301194405
{
    P = prevChild(firstChild(L));

    nextChild(prevChild(P))=firstChild(L);
    prevChild(firstChild(L))=prevChild(P);
    nextChild(P)=NULL;
    prevChild(P)=NULL;
}

void printinfoChild(listChild L)
// By : Michelle C.F.B - 1301194405 and Berliana Shafa W - 1301194118
{
    addressChild P = firstChild(L);
    int i = 1;
    if (firstChild(L)== NULL)
    {
        cout<<"|=|=|=|=|=|=|=|=|=|=|=|= MAAF LIST KOSONG =|=|=|=|=|=|=|=|=|=|=|"<<endl<<endl;
    }
    else
    {
        do
        {
            cout<<"|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|"<<endl;
            cout<<"                             Busana "<<i<<endl;
            cout<<"Kode Busana                 : "<<infoChild(P).kodeBusana<<endl;
            cout<<"Jenis Busana                : "<<infoChild(P).jenisBusana<<endl;
            cout<<"Ukuran Busana(S/M/L/XL/XXL) : "<<infoChild(P).ukuranBusana<<endl;
            cout<<"Jumlah Busana               : "<<infoChild(P).jumlahBusana<<endl;
            cout<<"|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|"<<endl<<endl;
            P = nextChild(P);
            i++;
        } while(nextChild(P) != nextChild(firstChild(L)));
    }
    cout<<endl;
}

addressChild searchElmChild(listChild &L, int kode)
// By : Michelle C.F.B - 1301194405 and Berliana Shafa W - 1301194181
{
    addressChild P = firstChild(L);
    if (P!= NULL)
    {
        do
        {
            if (infoChild(P).kodeBusana == kode)
            {
                return P;
            }
            P=nextChild(P);
        }while(nextChild(P) != firstChild(L));
        return NULL;
    }
    else
    {
        return NULL;
    }
}
