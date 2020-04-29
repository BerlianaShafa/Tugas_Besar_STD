#include "listChild.h"

void createListChild(listChild &L){
    firstChild(L) = NULL;
}

addressChild allocateChild(infotypeChild x){
    addressChild P = NULL;

    P = new elmlistChild;
    info(P).kodeBusana = x.kodeBusana;
    info(P).jenisBusana = x.jenisBusana;
    info(P).ukuranBusana = x.ukuranBusana;
    info(P).jumlahBusana = x.jumlahBusana;
    next(P)=NULL;
    prev(P)=NULL;

    return P;
}

void insertFirstChild(listChild &L, addressChild P){
    if(firstChild(L) == NULL){
        firstChild(L) = P;
        next(P) = P;
        prev(P) = P;
    } else {
        next(P) = firstChild(L);
        prev(P) = prev(firstChild(L));
        next(prev(firstChild(L))) = P;
        prev(firstChild(L)) = P;
        firstChild(L) = P;
    }
}

void insertAfterChild(listChild &L, addressChild prec, addressChild P){
    next(P)=next(prec);
    prev(next(P))=P;
    next(prec)=P;
    prev(next(prec))=prec;
}

void insertLastChild(listChild &L, addressChild P){
    if(firstChild(L) == NULL){
        insertFirstChild(L, P);
    } else {
        next(P) = firstChild(L);
        prev(P) = prev(firstChild(L));
        next(prev(firstChild(L))) = P;
        prev(firstChild(L)) = P;
    }
}

void deleteFirstChild(listChild &L, addressChild &P){
    P = firstChild(L);
    firstChild(L) = next(P);
    next(P) = NULL;
    prev(P) = NULL;
    prev(firstChild(L)) = lastChild(L);
    next(lastChild(L)) = firstChild(L);
}

void deleteAfterChild(listChild &L, addressChild prec, addressChild &P){
    P = next(prec);
    if(next(prec) == firstChild(L)){
        deleteLastChild(L, P);
    } else if (next(prec) == prec){
        next(P) = NULL;
        prev(P) = NULL;
        next(prec) = prec;
        prev(prec) = prec;
    } else {
        next(prec) = next(P);
        prev(next(P)) = prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void deleteLastChild(listChild &L, addressChild &P){
    
    P = lastChild(L);
    lastChild(L) = prev(lastChild(L));
    prev(P) = NULL;
    next(P) = NULL;
    prev(firstChild(L)) = lastChild(L);
    next(lastChild(L)) = firstChild(L);
}

void printinfoChild(listChild L){
    addressChild P;

    P = firstChild(L);
    if (P != NULL){
        do {
            cout<<"************************************"<<endl;
            cout<<"Kode : "<<P -> info.<<endl;
            cout<<"Jenis : "<<P -> info.namaPenyewa<<endl;
            cout<<"Ukuran : "<< P -> info.alamatPenyewa<<endl;
            cout<<"Jumlah : "<< P -> info.umurPenyewa<<endl;
            cout<<"************************************"<<endl<<endl;
            P = next(P);
        }while(P != firstChild(L));
    }
    cout<<endl;
}


addressChild searchElmParent(listChild &L, string ID){
    infotypeChild x;
    addressChild P;
    
    P=firstChild(L);
    while(P!=NULL && info(P)!=ID){
        P=next(P);
    }
    
    return P;
}







